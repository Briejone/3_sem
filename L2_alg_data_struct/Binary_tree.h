#ifndef TREE
#define TREE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct NodeTree {
  char data[256];
  struct NodeTree* left;
  struct NodeTree* right;
  struct NodeTree* parent;
} NodeTree;

typedef struct Tree {
  NodeTree* head;
  int size;
} Tree;

Tree* createTree();
NodeTree* createNodeTree(const char* data);
NodeTree* TAdd(Tree* tree, const char* data);
NodeTree* TSrch(Tree* tree, const char* data);
NodeTree* findMin(NodeTree* node);
NodeTree* TDel(Tree* tree, const char* data);
void printTree(NodeTree *tree, int space);
#endif