#include <iostream>

struct Node {
	int value;
	Node * left, * right;
	Node(int value) { this->value = value; this->left = this->right = nullptr; }
};

void printInOrder(Node* tree) {
	if (tree->left != nullptr) printInOrder(tree->left);
	std::cout << " " << tree->value;
	if (tree->right != nullptr) printInOrder(tree->right);
}

void addNode(Node** tree, int value) {
	if ((*tree) == nullptr) (*tree) = new Node(value);
	else if (value > (*tree)->value) addNode(&(*tree)->right, value);
	else if (value < (*tree)->value) addNode(&(*tree)->left, value);
}

Node* getMax(Node * tree) {
	// return max value in tree
	// always go to the left
	if (tree == nullptr) return nullptr;
	while (tree->right) tree = tree->right;
	return tree;
}

Node* getMin(Node * tree) {
	// return min value in tree
	// always go to the left
	if (tree == nullptr) return nullptr;
	while (tree->left) tree = tree->left;
	return tree;
}

int main() {

	Node* root = nullptr;

	addNode(&root, 4);
	addNode(&root, 3);
	addNode(&root, 2);
	addNode(&root, 1);

	printInOrder(root);
	std::cout << std::endl;
	std::cout << "Max value: " << getMax(root) << std::endl;
	std::cout << "Min value: " << getMin(root) << std::endl;
	std::cin.get();
	return 0;
}