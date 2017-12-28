#include <iostream>

struct Node {
	Node(int v) : value(v), left(nullptr), right(nullptr) {}
	Node(int v, Node * l, Node * r) : value(v), left(l), right(r) {}
	int value;
	Node * left;
	Node * right;
};

void printInorder(Node * tree) {
	if (!tree) return;
	printInorder(tree->left);
	std::cout << tree->value << ", ";
	printInorder(tree->right);
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
	Node * root = new Node(
		4,
		new Node(
			1,
			new Node(
				-2,
				nullptr,
				new Node(3)
			), nullptr
		),
		new Node(
			3,
			new Node(1),
			new Node(
				2,
				new Node(-2),
				new Node(-3)
			)
		)
	);

	printInorder(root);

	system("pause");
	return 0;
}
