#include "Binary_tree.h"

Tree* createTree() {
  Tree* tree = (Tree*)malloc(sizeof(Tree));
  tree->head = NULL;
  tree->size = 0;
  return tree;
}

NodeTree* createNodeTree(char* data) {
  NodeTree* node = (NodeTree*)malloc(sizeof(NodeTree));
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  strcpy(node->data, data);
  return node;
}

NodeTree* TAdd(Tree* tree, char* data) {
  NodeTree* node = createNodeTree(data);
  NodeTree* current = tree->head;
  NodeTree* parent = NULL;

  if (tree->head == NULL) {
    tree->head = node;
    return node;
  }

  int counter = 0;
  while (current != NULL) {
    counter++;
    if (strcmp( data, current->data ) == -1) {
      parent = current;
      current = current->left;
    } else {
      parent = current;
      current = current->right;
    }
    
  }
  if (current == NULL) {
    node->parent = parent;
    if (strcmp( data, parent->data ) == -1) {
    parent->left = node;
    } else {parent->right = node;} 
  }
  return node;
}

NodeTree* TSrch(Tree* tree, char* data) {
  NodeTree* tmp = tree->head;
  while (tmp != NULL) {
    if (strcmp( data, tmp->data ) == -1) {
      tmp = tmp->left;
    } else if (strcmp(data, tmp->data) == 0) {
      return tmp;
    } else {
      tmp = tmp->right;
    }    
  }
  return tmp;
};

NodeTree* findMin(NodeTree* node) {
  NodeTree* tmp = node;
  while(tmp->left != NULL) {
    tmp = tmp->left;
  }
  return tmp;
}

NodeTree* TDel(Tree* tree, char* data) {
  NodeTree* current = TSrch(tree, data);
  
  NodeTree* parent = NULL;
  NodeTree* swap = NULL;
  if(current != NULL) {
    parent = current->parent;
    if (current->left == NULL && current->right == NULL) {
      if (parent->left == current) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }

    } else if (current->left == NULL && current->right != NULL) {
      current = current->right;
      parent->right = current;
      current->parent = parent;
    
    } else if (current->left != NULL && current->right == NULL) {
      current = current->left;
      parent->left = current;
      current->parent = parent;
    
    } else {
      swap = findMin(current->right);
      swap->parent = parent;
      swap->right = current->right;
      swap->left = current->left;
      if(current->parent == NULL) {
        tree->head = swap;
      } else if (swap == parent->left) {
        parent->left = swap;
      } else {
        parent->right = swap;
      }
    } 
  }
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
    printf("%s\n", tree->data);
    printTree(tree->left, space);
}

// int main() {
//   Tree* tree = createTree();
//   TAdd(tree, "5");
//   TAdd(tree, "1");
//   TAdd(tree, "2");
//   TAdd(tree, "0");
//   TAdd(tree, "7");
//   printTree(tree->head, 2);
//   return 0;
// }

