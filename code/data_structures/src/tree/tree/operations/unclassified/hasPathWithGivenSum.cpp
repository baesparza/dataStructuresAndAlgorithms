#include <iostream>

struct Node {
	Node(int v) : value(v), left(nullptr), right(nullptr) {}
	int value;
	Node * left;
	Node * right;
};
	
void print(Node * tree) { // print in order tree
	if (!tree) return;
	print(tree->left);
	std::cout << tree->value << " ";
	print(tree->right);
}

bool hasPathWithGivenSum(Node * tree, int s) {
	if (!tree) // check if we have a tree - special case
		return s == 0;
	if (!tree->left && !tree->right) // check we arrived a leaf
		return s == tree->value;
	// never arrive to a nullptr tree
	// if no tree left or right, compare with false
	// otherwise check if path with sum
	return (tree->left ? hasPathWithGivenSum(tree->left, s - tree->value) : false)
		|| (tree->right ? hasPathWithGivenSum(tree->right, s - tree->value) : false);
}

int main() {
	/*
		  4
		 / \
		1   3
	   /   / \
	 -2   1   2
	   \     / \
		3  -2  -3
	*/
	Node * root = new Node(4);
	root->left = new Node(1);
	root->left->left = new Node(-2);
	root->left->left->right = new Node(3);
	root->right = new Node(3);
	root->right->left = new Node(1);
	root->right->right = new Node(2);
	root->right->right->left = new Node(-2);
	root->right->right->right = new Node(-3);

	print(root);
	std::cout << std::endl;
	std::cout << hasPathWithGivenSum(root, 7) << std::endl;
	system("pause");
	return 0;
}
