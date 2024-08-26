#include "tree.hpp"

void BinaryTree::inorder(Node* node, std::ostream& out) const {
    if (node) {
        inorder(node->left, out);
        out << node->data << " ";
        inorder(node->right, out);
    }
}

BinaryTree::Node* BinaryTree::insert(Node* node, int val) {
    if (!node) return new Node(val);
    if (val < node->data)
        node->left = insert(node->left, val);
    else
        node->right = insert(node->right, val);
    return node;
}

BinaryTree::Node* BinaryTree::search(Node* node, int val) const {
    if (!node || node->data == val) return node;
    if (val < node->data)
        return search(node->left, val);
    else
        return search(node->right, val);
}

void BinaryTree::destroy(Node* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BinaryTree::insert(int val) {
    root = insert(root, val);
}

BinaryTree::Node* BinaryTree::search(int val) const {
    return search(root, val);
}

void BinaryTree::inorder(std::ostream& out) const {
    inorder(root, out);
}
