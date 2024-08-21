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
NodeTree* createNodeTree(char* data);
NodeTree* TAdd(Tree* tree, char* data);
NodeTree* TSrch(Tree* tree, char* data);
NodeTree* findMin(NodeTree* node);
NodeTree* TDel(Tree* tree, char* data);
void printTree(NodeTree *tree, int space);
#endif