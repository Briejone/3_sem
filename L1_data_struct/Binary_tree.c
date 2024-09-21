#include "Binary_tree.h"

Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->head = NULL;
    tree->size = 0;
    return tree;
}

NodeTree* createNodeTree(const char* data) {
    NodeTree* node = (NodeTree*)malloc(sizeof(NodeTree));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    strcpy(node->data, data);
    return node;
}

NodeTree* TAdd(Tree* tree, const char* data) {
    NodeTree* node = createNodeTree(data);
    NodeTree* current = tree->head;
    NodeTree* parent = NULL;

    if (tree->head == NULL) {
        tree->head = node;
        return node;
    }

    while (current != NULL) {
        parent = current;
        if (strcmp(data, current->data) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    node->parent = parent;
    if (strcmp(data, parent->data) < 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    return node;
}

NodeTree* TSrch(Tree* tree, const char* data) {
    NodeTree* tmp = tree->head;
    while (tmp != NULL) {
        if (strcmp(data, tmp->data) < 0) {
            tmp = tmp->left;
        } else if (strcmp(data, tmp->data) == 0) {
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

NodeTree* TDel(Tree* tree, const char* data) {
    NodeTree* current = TSrch(tree, data);
    if (current == NULL) {
        return NULL;
    }

    NodeTree* parent = current->parent;
    NodeTree* replacement = NULL;

    // Удаляем лист
    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            tree->head = NULL; 
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    }
    // Один дочерний узел справа
    else if (current->left == NULL) {
        replacement = current->right;
        if (parent == NULL) {
            tree->head = replacement;
        } else if (parent->left == current) {
            parent->left = replacement;
        } else {
            parent->right = replacement;
        }
        replacement->parent = parent;
    }
    // Один дочерний узел слева
    else if (current->right == NULL) {
        replacement = current->left;
        if (parent == NULL) {
            tree->head = replacement;
        } else if (parent->left == current) {
            parent->left = replacement;
        } else {
            parent->right = replacement;
        }
        replacement->parent = parent;
    }
    // Два дочерних узла
    else {
        replacement = findMin(current->right); // Находим минимальный элемент в правом поддереве

        // Если минимальный элемент - не прямой потомок удаляемого узла
        if (replacement->parent != current) {
            // Заменяем минимальный узел его правым поддеревом
            replacement->parent->left = replacement->right;
            if (replacement->right != NULL) {
                replacement->right->parent = replacement->parent;
            }

            replacement->right = current->right;
            if (current->right != NULL) {
                current->right->parent = replacement;
            }
        }

        // Заменяем удаляемый узел минимальным
        replacement->left = current->left;
        if (current->left != NULL) {
            current->left->parent = replacement;
        }

        if (parent == NULL) {
            tree->head = replacement;
        } else if (parent->left == current) {
            parent->left = replacement;
        } else {
            parent->right = replacement;
        }

        replacement->parent = parent;
    }

    free(current);
    return replacement;
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


int main() {
  Tree* tree = createTree();
  TAdd(tree, "5");
  TAdd(tree, "1");
  TAdd(tree, "2");
  TAdd(tree, "0");
  TAdd(tree, "7");
  TDel(tree, "5");
  printTree(tree->head, 2);
  return 0;
}

