#include <iostream>

struct Node {
	int value;
	Node * left, * right;
	Node(int value) { this->value = value; this->left = this->right = nullptr; }
};

void addNode(Node** tree, int value) {
	if ((*tree) == nullptr) (*tree) = new Node(value);
	else if (value > (*tree)->value) addNode(&(*tree)->right, value);
	else if (value < (*tree)->value) addNode(&(*tree)->left, value);
}

void printInOrder(Node* tree) {
	// Inorder traversal
	if (!tree) return;
	printInOrder(tree->left);
	std::cout << " " << tree->value;
	printInOrder(tree->right);
}

void printPreOrder(Node* tree) {
	// Preorder traversal
	if (!tree) return;
	std::cout << " " << tree->value;
	printPreOrder(tree->left);
	printPreOrder(tree->right);
}

void printPostOrder(Node* tree) {
	// Postorder traversal
	if (!tree) return;
	printPostOrder(tree->left);
	printPostOrder(tree->right);
	std::cout << " " << tree->value;
}

int main() {

	Node* root = nullptr;

	addNode(&root, 3);
	addNode(&root, 2);
	addNode(&root, 4);
	addNode(&root, 1);

	std::cout << "Inorder" << std::endl;
	printInOrder(root);
	std::cout << "\nPreorder" << std::endl;
	printPreOrder(root);
	std::cout << "\nPosorder" << std::endl;
	printPostOrder(root);
	std::cin.get();
	return 0;
}