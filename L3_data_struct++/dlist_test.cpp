#include <gtest/gtest.h>
#include "dlist.hpp"

class DListTest : public ::testing::Test {
protected:
    DoublyLinkedList list;

    void SetUp() override {
        list.addBack("First");
        list.addBack("Second");
        list.addBack("Third");
    }
};

TEST_F(DListTest, AddFrontTest) {
    list.addFront("NewFirst");
    EXPECT_EQ(list.get(0), "NewFirst");
    EXPECT_EQ(list.getSize(), 4);
}

TEST_F(DListTest, AddBackTest) {
    list.addBack("NewLast");
    EXPECT_EQ(list.get(3), "NewLast");
    EXPECT_EQ(list.getSize(), 4);
}

TEST_F(DListTest, RemoveFrontTest) {
    EXPECT_EQ(list.removeFront(), "First");
    EXPECT_EQ(list.get(0), "Second");
    EXPECT_EQ(list.getSize(), 2);
}

TEST_F(DListTest, RemoveBackTest) {
    EXPECT_EQ(list.removeBack(), "Third");
    EXPECT_EQ(list.get(1), "Second");
    EXPECT_EQ(list.getSize(), 2);
}

TEST_F(DListTest, RemoveSpecificTest) {
    EXPECT_TRUE(list.remove("Second"));
    EXPECT_EQ(list.find("Second"), -1);
    EXPECT_EQ(list.getSize(), 2);
}

TEST_F(DListTest, RemoveNonExistentTest) {
    EXPECT_FALSE(list.remove("NonExistent"));
    EXPECT_EQ(list.getSize(), 3);
}

TEST_F(DListTest, GetTest) {
    EXPECT_EQ(list.get(1), "Second");
    EXPECT_THROW(list.get(3), std::out_of_range);
}

TEST_F(DListTest, FindTest) {
    EXPECT_EQ(list.find("Second"), 1);
    EXPECT_EQ(list.find("NonExistent"), -1);
}

TEST_F(DListTest, SizeAndEmptyTest) {
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_FALSE(list.isEmpty());
    DoublyLinkedList emptyList;
    EXPECT_TRUE(emptyList.isEmpty());
    EXPECT_EQ(emptyList.getSize(), 0);
}

