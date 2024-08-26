#include <gtest/gtest.h>
#include "queue.hpp"

class QueueTest : public ::testing::Test {
protected:
    Queue queue;

    void SetUp() override {
        queue.enqueue("First");
        queue.enqueue("Second");
    }
};

TEST_F(QueueTest, EnqueueTest) {
    queue.enqueue("Third");
    EXPECT_EQ(queue.dequeue(), "First");
}

TEST_F(QueueTest, DequeueTest) {
    EXPECT_EQ(queue.dequeue(), "First");
    EXPECT_EQ(queue.dequeue(), "Second");
}

TEST_F(QueueTest, DequeueEmptyQueueTest) {
    queue.dequeue(); // Удаление "First"
    queue.dequeue(); // Удаление "Second"
    EXPECT_THROW(queue.dequeue(), std::out_of_range); // Ожидание исключения
}

