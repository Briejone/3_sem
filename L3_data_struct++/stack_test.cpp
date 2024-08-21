#include <gtest/gtest.h>
#include "stack.hpp" // Заголовочный файл с вашим кодом на C++

TEST(StackTest, PushPopTest) {
    Stack stack;
    stack.push("test1");
    stack.push("test2");

    EXPECT_EQ(stack.pop(), "test2");
    EXPECT_EQ(stack.pop(), "test1");
}
