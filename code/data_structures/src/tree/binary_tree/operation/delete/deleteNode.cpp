#include <iostream>

struct Node {
	int value;
	Node * left, *right; 
	
	Node(int v) : value(v), left(nullptr), right(nullptr) 
	{}
};

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

void printInOrder(const Node* tree) {
	if (tree == nullptr) return; // check if we have a tree
	printInOrder(tree->left);
	std::cout << tree->value << " ";
	printInOrder(tree->right);
}

void deleteNode(Node** tree, int value) {
	/*check if we are in a node or a nullptr*/
	if ((* tree) == nullptr) return;

	/*go into left branch or right of node*/
	if (value < (*tree)->value) {
		// check left branch
		deleteNode(&(*tree)->left, value);
		return;
	}

	if ((*tree)->value < value) {
		// check right branch
		deleteNode(&(*tree)->right, value);
		return;
	}

	/*check if we are in the node we need to delete*/
	if ((* tree)->value == value) {
		// node needs to be removed

		/*check if we are in a leaf*/
		if (!(*tree)->left && !(*tree)->right) {
			// no left or righ branch
			// remove this reference
			delete (*tree);
			(*tree) = nullptr;
			return;
		}

		// search value to replace this node
		Node * current = nullptr;

		/*find min val in right, or max in left branch if there is no right branch*/
		if ((*tree)->right) {
			//search min node in right side of tree
			current = (*tree)->right;
			// always go left nodes to find min node
			while (current->left) current = current->left;
			(*tree)->value = current->value; // overwrite root value
			deleteNode(&(*tree)->right, current->value); // remove copied node
		} else {
			//search max node in left side of tree
			current = (*tree)->left;
			// always go right nodes to find max node
			while (current->right) current = current->right;
			(*tree)->value = current->value; // overwrite root value
			deleteNode(&(*tree)->left, current->value); // remove copied node
		}
		return;
	}
	
	// value never existed in tree
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
	std::cout << "\n";

	deleteNode(&root, 5);
	printInOrder(root);

	std::cin.clear();
	std::cin.get();
	return 0;
}