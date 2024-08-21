#include <stdio.h>
#include <stdlib.h>

typedef struct NodeTree {
    int data;
    struct NodeTree* left;
    struct NodeTree* right;
    struct NodeTree* parent;
} NodeTree;

typedef struct Tree {
    NodeTree* head;
    int size;
} Tree;

typedef struct QueueNode {
    NodeTree* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Tree* createTree();
NodeTree* createNodeTree(int data);
NodeTree* TAdd(Tree* tree, int data);
void printRightNeighbors(Tree* tree);
void enqueue(Queue* queue, NodeTree* treeNode);
NodeTree* dequeue(Queue* queue);
int isQueueEmpty(Queue* queue);

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->head = NULL;
    tree->size = 0;
    return tree;
}

NodeTree* createNodeTree(int data) {
    NodeTree* node = (NodeTree*)malloc(sizeof(NodeTree));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->data = data;
    return node;
}

NodeTree* TAdd(Tree* tree, int data) {
    NodeTree* node = createNodeTree(data);
    NodeTree* current = tree->head;
    NodeTree* parent = NULL;

    if (tree->head == NULL) {
        tree->head = node;
        return node;
    }

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    node->parent = parent;
    if (data < parent->data) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    return node;
}

void enqueue(Queue* queue, NodeTree* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

NodeTree* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }

    QueueNode* temp = queue->front;
    NodeTree* treeNode = temp->treeNode;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return treeNode;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void printRightNeighbors(Tree* tree) {
    if (tree->head == NULL) {
        return;
    }

    Queue queue = {NULL, NULL};
    enqueue(&queue, tree->head);
    enqueue(&queue, NULL);  // Указатель на конец уровня

    while (!isQueueEmpty(&queue)) {
        NodeTree* current = dequeue(&queue);

        if (current == NULL) {
            if (!isQueueEmpty(&queue)) {
                enqueue(&queue, NULL);  // Добавляем указатель на конец следующего уровня
            }
        } else {
            NodeTree* nextNode = queue.front != NULL ? queue.front->treeNode : NULL;

            if (nextNode != NULL) {
                printf("Node %d -> Right Neighbor: %d\n", current->data, nextNode->data);
            } else {
                printf("Node %d -> Right Neighbor: NULL\n", current->data);
            }

            if (current->left != NULL) {
                enqueue(&queue, current->left);
            }
            if (current->right != NULL) {
                enqueue(&queue, current->right);
            }
        }
    }
}

int main() {
    Tree* tree = createTree();

    TAdd(tree, 50);
    TAdd(tree, 30);
    TAdd(tree, 70);
    TAdd(tree, 20);
    TAdd(tree, 40);
    TAdd(tree, 60);
    TAdd(tree, 80);

    printRightNeighbors(tree);

    return 0;
}
