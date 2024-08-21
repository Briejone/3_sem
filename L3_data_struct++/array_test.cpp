#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "array.hpp"

class ArrayTest : public ::testing::Test {
protected:
    Array array;

    void SetUp() override {
        array.ArrAdd("Hello");
        array.ArrAdd("World");
    }
};

TEST_F(ArrayTest, AddAndGet) {
    EXPECT_EQ(std::string(array.ArrGet(0)), "Hello");
    EXPECT_EQ(std::string(array.ArrGet(1)), "World");
}

TEST_F(ArrayTest, Search) {
    EXPECT_EQ(array.ArrSrch("Hello"), 0);
    EXPECT_EQ(array.ArrSrch("World"), 1);
}
