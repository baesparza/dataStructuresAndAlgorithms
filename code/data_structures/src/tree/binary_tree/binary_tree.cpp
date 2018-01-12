#include <iostream>

struct Node {
    int value;
    Node * left, *right; 
    
    Node(int v) : value(v), left(nullptr), right(nullptr) 
    {}
};

void printInOrder(const Node* tree) {
    if (tree == nullptr) return; // check if we have a tree
    printInOrder(tree->left);
    std::cout << tree->value << " ";
    printInOrder(tree->right);
}

void addNode(Node** tree, int value) {
    // check if already has nodes
    if ((*tree) == nullptr) {
        // create new node
        (*tree) = new Node(value);
        return;
    }

    /*select left or right branch*/
    // right branch
    if (value > (*tree)->value) {
        // go into right branch
        addNode(&(*tree)->right, value);
        return;
    }

    // left branch
    if (value < (*tree)->value) {
        // go into right branch
        addNode(&(*tree)->left, value);
    }
    // if node value is repeated, it will not be added
}

int main() {

    Node* root = nullptr;
    
    addNode(&root, 7);
    addNode(&root, 2);
    addNode(&root, 8);
    addNode(&root, 1);
    addNode(&root, 4);
    addNode(&root, 3);
    addNode(&root, 10);
    addNode(&root, 9);
    addNode(&root, 6);

    printInOrder(root);

    std::cin.clear();
    std::cin.get();
    return 0;
}