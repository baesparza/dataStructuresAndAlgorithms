#include <iostream>

struct Node {
	int value, height;
	Node * left, *right;
	Node(int v) : value(v), height(0)
	{
		left = right = nullptr;
	}
};

/*Traverse and print tree inOrder*/
void traverse(const Node * tree) {
	/*check if we are in a node*/
	if (tree == nullptr) return;
	traverse(tree->left);
	std::cout << tree->value << ", " << tree->height << "\n";
	traverse(tree->right);
}

/*Basic function to calc max between two numbers*/
int max(int a, int b) {
	return (a > b) ? a : b;
}

/*get height of a node*/
int getHeight(const Node * tree) {
	return (tree != nullptr) ? tree->height : -1;
}

/*geet balance of a node*/
int getBalance(const Node * tree) {
	return (tree == nullptr) ? 0 : getHeight(tree->left) - getHeight(tree->right);
}

/*left rotation of tree*/
Node * leftRoration(Node * tree) {
	//       /          /
	//      x          y
	//     / \        / \
	//    y   C  ->  A   x
	//   / \            / \
	//  A   B          B   C
	Node * x = tree;
	Node * y = tree->left;

	/*rotate*/
	x->left = y->right;
	y->right = x;

	/*update heights of x and y*/
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	/*return y as new root*/
	return y;
}

/*right rotate of tree*/
Node * rightRoration(Node * tree) {
	//   \              \
	//    x              y
	//   / \            / \
	//  A   y    ->    x   C
	//     / \        / \
	//    B   C      A   B
	Node * x = tree;
	Node * y = tree->right;

	/*rotate*/
	x->right = y->left;
	y->left = x;

	/*update heights of x and y*/
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

	/*return y as new root*/
	return y;
}

/*Inset Node in AVL Tree*/
Node * addNode(Node * tree, int value) {
	/*Check if this is a node*/
	if (tree == nullptr)
		return new Node(value);

	/*Insert node  with normal bst insertion method*/
	if (value > tree->value)
		tree->right = addNode(tree->right, value); // go into right branch
	else if (value < tree->value)
		tree->left = addNode(tree->left, value); // go into right branch
	else
		return tree; // value is repeated

	/*update height of this node*/
	tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;

	/*fix avl property, and check wich branch node was inserted that became unbalanced*/
	int balance = getBalance(tree);
	// right right rotation
	if (balance == -2 && value > tree->right->value)
		return rightRoration(tree);
	// left left rotation
	if (balance == 2 && value < tree->left->value)
		return leftRoration(tree);
	// right left rotation
	if (balance == -2 && value < tree->right->value) {
		tree->right = leftRoration(tree->right);
		return rightRoration(tree);
	}
	// left right rotation
	if (balance == 2 && value > tree->left->value) {
		tree->left = rightRoration(tree->left);
		return leftRoration(tree);
	}

	/*return unchanged tree*/
	return tree;
}

int main() {

	Node * root = nullptr;
	root = addNode(root, 5);
	root = addNode(root, 4);
	root = addNode(root, 2);
	root = addNode(root, 3);
	root = addNode(root, 1);
	root = addNode(root, 6);
	root = addNode(root, 7);
	root = addNode(root, 9);
	root = addNode(root, 1);
	root = addNode(root, 0);
	root = addNode(root, 12);
	root = addNode(root, 8);

	std::cout << "v, h\n";
	traverse(root);

	std::cin.get();
	return 0;
}