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

Tree* createTree();
NodeTree* createNodeTree(int data);
NodeTree* TAdd(Tree* tree, int data);
NodeTree* TSrch(Tree* tree, int data);
NodeTree* findMin(NodeTree* node);
NodeTree* TDel(Tree* tree, int data);
void printTree(NodeTree *tree, int space);

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

NodeTree* TSrch(Tree* tree, int data) {
  NodeTree* tmp = tree->head;
  while (tmp != NULL) {
    if (data < tmp->data) {
      tmp = tmp->left;
    } else if (data == tmp->data) {
      return tmp;
    } else {
      tmp = tmp->right;
    }    
  }
  return NULL;
}

NodeTree* findMin(NodeTree* node) {
  NodeTree* tmp = node;
  while (tmp->left != NULL) {
    tmp = tmp->left;
  }
  return tmp;
}

NodeTree* TDel(Tree* tree, int data) {
  NodeTree* current = TSrch(tree, data);

  if (current == NULL) {
    return NULL;  // Узел с таким значением не найден
  }

  NodeTree* parent = current->parent;
  NodeTree* swap = NULL;

  if (current->left == NULL && current->right == NULL) {
    if (parent != NULL) {
      if (parent->left == current) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
    } else {
      tree->head = NULL;  // Дерево теперь пусто
    }

  } else if (current->left == NULL && current->right != NULL) {
    if (parent != NULL) {
      if (parent->left == current) {
        parent->left = current->right;
      } else {
        parent->right = current->right;
      }
    } else {
      tree->head = current->right;
    }
    current->right->parent = parent;

  } else if (current->left != NULL && current->right == NULL) {
    if (parent != NULL) {
      if (parent->left == current) {
        parent->left = current->left;
      } else {
        parent->right = current->left;
      }
    } else {
      tree->head = current->left;
    }
    current->left->parent = parent;

  } else {
    swap = findMin(current->right);
    if (swap->parent != current) {
      swap->parent->left = swap->right;
      if (swap->right != NULL) {
        swap->right->parent = swap->parent;
      }
      swap->right = current->right;
      current->right->parent = swap;
    }

    if (parent != NULL) {
      if (parent->left == current) {
        parent->left = swap;
      } else {
        parent->right = swap;
      }
    } else {
      tree->head = swap;
    }
    swap->left = current->left;
    current->left->parent = swap;
    swap->parent = parent;
  }

  free(current);
  return current;
}

void printTree(NodeTree *tree, int space) {
    if (tree == NULL) {
        return;
    }
    space += 4;
    printTree(tree->right, space);
    printf("\n");
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", tree->data);
    printTree(tree->left, space);
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

  printf("Tree before deletion:\n");
  printTree(tree->head, 0);

  TDel(tree, 50);

  printf("Tree after deletion:\n");
  printTree(tree->head, 0);

  return 0;
}

