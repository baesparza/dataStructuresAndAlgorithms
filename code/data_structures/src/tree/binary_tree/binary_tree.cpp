#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) {
        this->value = value;
        this->left = this->right = nullptr;
    }
};

void addNode(Node** tree, int value) {
    // check if already has nodes
    if ((* tree) == nullptr) {
        // create new node
        (* tree) = new Node(value);
        return;
    }

    // select left or right branch
    // right branch
    if (value > (* tree)->value) {
        // go into right branch
        addNode(&(* tree)->right, value);
        return;
    }

    // left branch
    if (value < (* tree)->value) {
        // go into right branch
        addNode(&(* tree)->left, value);
    }
    // if node value is repeated, it will not be added
}

void printInOrder(Node* tree) {
    if (tree->left != nullptr) printInOrder(tree->left);
    std::cout << " " << tree->value;
    if (tree->right != nullptr) printInOrder(tree->right);
}

int main () {

    Node* root = nullptr;

    addNode(&root,4);
    addNode(&root,3);
    addNode(&root,2);
    addNode(&root,4);
    addNode(&root,1);

    printInOrder(root);
    return 0;
}
