#include <gtest/gtest.h>
#include "tree.hpp"

class BinaryTreeTest : public ::testing::Test {
protected:
    BinaryTree tree;

    void SetUp() override {
        tree.insert(10);
        tree.insert(5);
        tree.insert(15);
        tree.insert(2);
        tree.insert(7);
    }
};

TEST_F(BinaryTreeTest, SearchNodeExists) {
    ASSERT_NE(tree.search(10), nullptr);
    ASSERT_NE(tree.search(5), nullptr);
    ASSERT_NE(tree.search(15), nullptr);
}

TEST_F(BinaryTreeTest, SearchNodeDoesNotExist) {
    ASSERT_EQ(tree.search(99), nullptr);
}

