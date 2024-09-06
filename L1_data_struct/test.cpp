#include "gtest/gtest.h"
#include "Stack.h"
#include "Queue.h"
#include "List.h"
#include "Hash_table.h"
#include "Array.h"
#include "Binary_tree.h"
#include "DLList.h"

// -------- Тесты для Stack --------

TEST(StackTest, CreateStack) {
    Stack* stack = createStack();
    ASSERT_EQ(stack->size, 0);
    ASSERT_EQ(stack->top, nullptr);
}

TEST(StackTest, PushElement) {
    Stack* stack = createStack();
    SPush(stack, (char*)"First Element");
    ASSERT_EQ(stack->size, 1);
    ASSERT_STREQ(stack->top->data, "First Element");

    SPush(stack, (char*)"Second Element");
    ASSERT_EQ(stack->size, 2);
    ASSERT_STREQ(stack->top->data, "Second Element");
}

TEST(StackTest, PopElement) {
    Stack* stack = createStack();
    SPush(stack, (char*)"First Element");
    SPush(stack, (char*)"Second Element");

    char* poppedElement = SPop(stack);
    ASSERT_STREQ(poppedElement, "Second Element");
    ASSERT_EQ(stack->size, 1);
    ASSERT_STREQ(stack->top->data, "First Element");
    free(poppedElement);

    poppedElement = SPop(stack);
    ASSERT_STREQ(poppedElement, "First Element");
    ASSERT_EQ(stack->size, 0);
    ASSERT_EQ(stack->top, nullptr);
    free(poppedElement);
}

TEST(StackTest, TopElement) {
    Stack* stack = createStack();
    SPush(stack, (char*)"First Element");
    SPush(stack, (char*)"Second Element");

    char* topElement = STop(stack);
    ASSERT_STREQ(topElement, "Second Element");
}

TEST(StackTest, EmptyStack) {
    Stack* stack = createStack();
    ASSERT_EQ(STop(stack), nullptr);
    ASSERT_EQ(SPop(stack), nullptr);
}

// -------- Тесты для Queue --------

TEST(QueueTest, CreateQueue) {
    Queue* queue = createQueue();
    ASSERT_EQ(queue->size, 0);
    ASSERT_EQ(queue->head, nullptr);
    ASSERT_EQ(queue->tail, nullptr);
}

TEST(QueueTest, PushElement) {
    Queue* queue = createQueue();
    QPush(queue, (char*)"First Element");
    ASSERT_EQ(queue->size, 1);
    ASSERT_STREQ(queue->head->data, "First Element");

    QPush(queue, (char*)"Second Element");
    ASSERT_EQ(queue->size, 2);
    ASSERT_STREQ(queue->tail->data, "Second Element");
}

TEST(QueueTest, PopElement) {
    Queue* queue = createQueue();
    QPush(queue, (char*)"First Element");
    QPush(queue, (char*)"Second Element");

    char* poppedElement = QPop(queue);
    ASSERT_STREQ(poppedElement, "First Element");
    ASSERT_EQ(queue->size, 1);
    ASSERT_STREQ(queue->head->data, "Second Element");

    poppedElement = QPop(queue);
    ASSERT_STREQ(poppedElement, "Second Element");
    ASSERT_EQ(queue->size, 0);
    ASSERT_EQ(queue->head, nullptr);
    ASSERT_EQ(queue->tail, nullptr);
}

TEST(QueueTest, EmptyQueue) {
    Queue* queue = createQueue();
    ASSERT_EQ(QPop(queue), nullptr);
}

// -------- Тесты для List --------

TEST(ListTest, CreateList) {
    List* list = create_list();
    ASSERT_EQ(list->size, 0);
    ASSERT_EQ(list->head, nullptr);
}

TEST(ListTest, AddElementToFront) {
    List* list = create_list();
    LAdd(list, (char*)"First Element");
    ASSERT_EQ(list->size, 1);
    ASSERT_STREQ(list->head->data, "First Element");

    LAdd(list, (char*)"Second Element");
    ASSERT_EQ(list->size, 2);
    ASSERT_STREQ(list->head->data, "Second Element");
}

TEST(ListTest, AddElementToEnd) {
    List* list = create_list();
    LAddr(list, (char*)"First Element");
    ASSERT_EQ(list->size, 1);
    ASSERT_STREQ(list->head->data, "First Element");

    LAddr(list, (char*)"Second Element");
    ASSERT_EQ(list->size, 2);
    ASSERT_STREQ(list->head->next->data, "Second Element");
}

TEST(ListTest, DeleteElement) {
    List* list = create_list();
    LAdd(list, (char*)"First Element");
    LAdd(list, (char*)"Second Element");

    char* deletedElement = LDel(list);
    ASSERT_STREQ(deletedElement, "Second Element");
    ASSERT_EQ(list->size, 1);
    ASSERT_STREQ(list->head->data, "First Element");
}

TEST(ListTest, GetElementIndex) {
    List* list = create_list();
    LAdd(list, (char*)"First Element");
    LAdd(list, (char*)"Second Element");

    int index = LGet(list, (char*)"First Element");
    ASSERT_EQ(index, 1);
}

// -------- Тесты для HashTable --------

TEST(HashTableTest, CreateHashTable) {
    HashTable* hashtable = createHashTable(10);
    ASSERT_EQ(hashtable->size, 10);
    for (int i = 0; i < hashtable->size; i++) {
        ASSERT_EQ(hashtable->table[i], nullptr);
    }
}

TEST(HashTableTest, SetElement) {
    HashTable* hashtable = createHashTable(10);
    char* data = HSet(hashtable, (char*)"key1", (char*)"value1");
    ASSERT_STREQ(data, "value1");
    ASSERT_STREQ(HGet(hashtable, (char*)"key1"), "value1");

    data = HSet(hashtable, (char*)"key1", (char*)"value2");
    ASSERT_STREQ(data, "value2");
    ASSERT_STREQ(HGet(hashtable, (char*)"key1"), "value2");
}

TEST(HashTableTest, GetElement) {
    HashTable* hashtable = createHashTable(10);
    HSet(hashtable, (char*)"key1", (char*)"value1");
    ASSERT_STREQ(HGet(hashtable, (char*)"key1"), "value1");
    ASSERT_EQ(HGet(hashtable, (char*)"key2"), nullptr);
}

TEST(HashTableTest, DeleteElement) {
    HashTable* hashtable = createHashTable(10);
    HSet(hashtable, (char*)"key1", (char*)"value1");
    ASSERT_STREQ(HDel(hashtable, (char*)"key1"), "value1");
    ASSERT_EQ(HGet(hashtable, (char*)"key1"), nullptr);
}

// -------- Тесты для Array --------

TEST(ArrayTest, CreateArray) {
    Array* arr = create_array(5);
    ASSERT_NE(arr, nullptr);
    ASSERT_EQ(arr->size, 0);
    for (int i = 0; i < 5; i++) {
        ASSERT_NE(arr->data[i], nullptr);
    }
    // Clean up
    for (int i = 0; i < 5; i++) {
        free(arr->data[i]);
    }
    free(arr);
}

TEST(ArrayTest, AddElement) {
    Array* arr = create_array(5);
    ArrAdd(arr, (char*)"Element1");
    ASSERT_EQ(arr->size, 1);
    ASSERT_STREQ(ArrGet(arr, 0), "Element1");
    // Clean up
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr);
}

TEST(ArrayTest, DeleteElement) {
    Array* arr = create_array(5);
    ArrAdd(arr, (char*)"Element1");
    ArrAdd(arr, (char*)"Element2");
    char* deleted = ArrDel(arr);
    ASSERT_STREQ(deleted, "Element2");
    ASSERT_EQ(arr->size, 1);
    ASSERT_STREQ(ArrGet(arr, 0), "Element1");
    free(deleted);
    // Clean up
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr);
}

TEST(ArrayTest, InsertElement) {
    Array* arr = create_array(5);
    ArrAdd(arr, (char*)"Element1");
    ArrAdd(arr, (char*)"Element3");
    ArrIns(arr, (char*)"Element2", 1);
    ASSERT_EQ(arr->size, 3);
    ASSERT_STREQ(ArrGet(arr, 0), "Element1");
    ASSERT_STREQ(ArrGet(arr, 1), "Element2");
    ASSERT_STREQ(ArrGet(arr, 2), "Element3");
    // Clean up
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr);
}

TEST(ArrayTest, RemoveElement) {
    Array* arr = create_array(5);
    ArrAdd(arr, (char*)"Element1");
    ArrAdd(arr, (char*)"Element2");
    ArrAdd(arr, (char*)"Element3");
    char* removed = ArrRem(arr, 1);
    ASSERT_STREQ(removed, "Element2");
    ASSERT_EQ(arr->size, 2);
    ASSERT_STREQ(ArrGet(arr, 0), "Element1");
    ASSERT_STREQ(ArrGet(arr, 1), "Element3");
    free(removed);
    // Clean up
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr);
}

TEST(ArrayTest, ChangeElement) {
    Array* arr = create_array(5);
    ArrAdd(arr, (char*)"Element1");
    ArrChg(arr, (char*)"ChangedElement", 0);
    ASSERT_STREQ(ArrGet(arr, 0), "ChangedElement");
    // Clean up
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr);
}

TEST(ArrayTest, SearchElement) {
    Array* arr = create_array(5);
    ArrAdd(arr, (char*)"Element1");
    ArrAdd(arr, (char*)"Element2");
    int index = ArrSrch(arr, (char*)"Element2");
    ASSERT_EQ(index, 1);
    index = ArrSrch(arr, (char*)"Element3");
    ASSERT_EQ(index, -1);
    // Clean up
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr);
}
// -------- Тесты для Tree --------

TEST(BinaryTreeTest, CreateTree) {
    Tree* tree = createTree();
    ASSERT_NE(tree, nullptr);
    ASSERT_EQ(tree->head, nullptr);
    ASSERT_EQ(tree->size, 0);
    free(tree);
}

TEST(BinaryTreeTest, AddNode) {
    Tree* tree = createTree();
    NodeTree* node1 = TAdd(tree, "5");
    NodeTree* node2 = TAdd(tree, "3");
    NodeTree* node3 = TAdd(tree, "7");

    ASSERT_NE(node1, nullptr);
    ASSERT_NE(node2, nullptr);
    ASSERT_NE(node3, nullptr);

    ASSERT_STREQ(tree->head->data, "5");
    ASSERT_STREQ(tree->head->left->data, "3");
    ASSERT_STREQ(tree->head->right->data, "7");

    free(node1);
    free(node2);
    free(node3);
    free(tree);
}

TEST(BinaryTreeTest, SearchNode) {
    Tree* tree = createTree();
    TAdd(tree, "5");
    TAdd(tree, "3");
    TAdd(tree, "7");

    NodeTree* foundNode = TSrch(tree, "3");
    ASSERT_NE(foundNode, nullptr);
    ASSERT_STREQ(foundNode->data, "3");

    NodeTree* notFoundNode = TSrch(tree, "10");
    ASSERT_EQ(notFoundNode, nullptr);

    free(tree);
}

TEST(BinaryTreeTest, DeleteNode) {
    Tree* tree = createTree();
    TAdd(tree, "5");
    TAdd(tree, "3");
    TAdd(tree, "7");
    TAdd(tree, "2"); // Add another node for testing

    NodeTree* deletedNode = TDel(tree, "3");
    ASSERT_NE(deletedNode, nullptr);
    ASSERT_STREQ(deletedNode->data, "3");
    ASSERT_EQ(TSrch(tree, "3"), nullptr);

    NodeTree* remainingNode = TSrch(tree, "7");
    ASSERT_NE(remainingNode, nullptr);
    ASSERT_STREQ(remainingNode->data, "7");

    free(deletedNode);
    free(tree);
}

TEST(BinaryTreeTest, PrintTree) {
    Tree* tree = createTree();
    TAdd(tree, "5");
    TAdd(tree, "3");
    TAdd(tree, "7");
    TAdd(tree, "2");
    TAdd(tree, "4");
    printTree(tree->head, 2);
    
    free(tree);
}

// -------- Тесты для DList --------

TEST(DListTest, CreateDList) {
    DList* list = createDList();
    ASSERT_EQ(list->size, 0);
    ASSERT_EQ(list->head, nullptr);
    ASSERT_EQ(list->tail, nullptr);
}

TEST(DListTest, AddElementToFront) {
    DList* list = createDList();
    DLLAdd(list, (char*)"First Element");
    ASSERT_EQ(list->size, 1);
    ASSERT_STREQ(list->head->data, "First Element");

    DLLAdd(list, (char*)"Second Element");
    ASSERT_EQ(list->size, 2);
    ASSERT_STREQ(list->head->data, "Second Element");
}

TEST(DListTest, AddElementToEnd) {
    DList* list = createDList();
    DLLAddr(list, (char*)"First Element");
    ASSERT_EQ(list->size, 1);
    ASSERT_STREQ(list->head->data, "First Element");

    DLLAddr(list, (char*)"Second Element");
    ASSERT_EQ(list->size, 2);
    ASSERT_STREQ(list->tail->data, "Second Element");
}

TEST(DListTest, DeleteElementFromFront) {
    DList* list = createDList();
    DLLAdd(list, (char*)"First Element");
    DLLAdd(list, (char*)"Second Element");

    DLLDel(list);
    ASSERT_EQ(list->size, 1);
    ASSERT_STREQ(list->head->data, "First Element");
}

TEST(DListTest, DeleteElementByIndex) {
    DList* list = createDList();
    DLLAdd(list, (char*)"First Element");
    DLLAddr(list, (char*)"Second Element");
    DLLAddr(list, (char*)"Third Element");

    DLLRem(list, 1);
    ASSERT_EQ(list->size, 2);
    ASSERT_STREQ(list->head->next->data, "Third Element");
}

TEST(DListTest, InsertElementByIndex) {
    DList* list = createDList();
    DLLAdd(list, (char*)"First Element");
    DLLAddr(list, (char*)"Third Element");

    DLLIns(list, 1, (char*)"Second Element");
    ASSERT_EQ(list->size, 3);
    ASSERT_STREQ(list->head->next->data, "Second Element");
}

// Основная функция для запуска тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
