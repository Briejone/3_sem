#include <gtest/gtest.h>
#include "hash_table.hpp"

class HashTableTest : public ::testing::Test {
protected:
    HashTable hashTable;

    HashTableTest() : hashTable(10) {} // Примерный размер таблицы 10

    void SetUp() override {
        hashTable.insert("key1", "value1");
        hashTable.insert("key2", "value2");
        hashTable.insert("key3", "value3");
    }
};

TEST_F(HashTableTest, InsertAndGetTest) {
    EXPECT_EQ(hashTable.get("key1"), "value1");
    EXPECT_EQ(hashTable.get("key2"), "value2");
    EXPECT_EQ(hashTable.get("key3"), "value3");
    EXPECT_EQ(hashTable.get("key4"), ""); // Не существующий ключ
}

TEST_F(HashTableTest, RemoveTest) {
    EXPECT_EQ(hashTable.remove("key2"), "value2");
    EXPECT_EQ(hashTable.get("key2"), ""); // Удаленный ключ
    EXPECT_EQ(hashTable.getSize(), 2);
}

TEST_F(HashTableTest, RemoveNonExistentKeyTest) {
    EXPECT_EQ(hashTable.remove("nonexistent"), "");
    EXPECT_EQ(hashTable.getSize(), 3); // Размер должен остаться прежним
}


TEST_F(HashTableTest, GetAfterRemovalTest) {
    hashTable.remove("key1");
    EXPECT_EQ(hashTable.get("key1"), ""); // Удаленный ключ
    EXPECT_EQ(hashTable.getSize(), 2);
}

TEST_F(HashTableTest, SizeTest) {
    EXPECT_EQ(hashTable.getSize(), 3);
}
