#include <iostream>

struct Node {
    /*singly_linked_list*/
    int val;
    Node *next;
    Node(int val) { this->val = val, this->next = nullptr; }
    Node(int val, Node * next) { this->val = val, this->next = next; }
};

void print(Node* current) {
    /*Print items in List*/
	std::cout << "\tLinked List : ";
	for ( ; current != nullptr; current = current->next) std::cout << "[" << current->val << "] -> ";
	std::cout << "null" << std::endl;
}

Node* addBeginning(Node* head, int value) {
	/*Adds a new node with a data field containing value to the beginning of the list*/
	return new Node(value, head); // create new node pointing actual head, and return new head
}

Node* findIndex(Node* head, int index) {
	/*Returns a pointer to the index node from the head pointer, or NULL if index is longer than the length of the list.*/
	if (index < 0) return nullptr; // return impossible index to reach
	Node* current = head;
	int i = 0;
	while (current) { // check with counter if index exist
		if (i == index) return current;
		current = current->next;
		i++;
	}
	return nullptr; // index does not exit
}

int main() {
    Node *head = nullptr;
    head = addBeginning(head, 4);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);
    head = addBeginning(head, 1);
    head = addBeginning(head, 9);

    std::cout << "Returns a pointer to the index node from the head pointer, or NULL" << std::endl;
    std::cout << "First node index is 0" << std::endl;
    print(head);

    /*test*/
    std::cout << "findIndex: " << -1 << std::endl;
    if (findIndex(head, -1)) std::cout << "\tindex -1 found" << std::endl;
    else std::cout << "\tindex NOT found" << std::endl;
    std::cout << "findIndex: " << 2 << std::endl;
    if (findIndex(head, 2)) std::cout << "\tindex 2 found" << std::endl;
    else std::cout << "\tindex NOT found" << std::endl;
    std::cout << "findIndex: " << 5 << std::endl;
    if (findIndex(head, 5)) std::cout << "\tindex 5 found" << std::endl;
    else std::cout << "\tindex NOT found" << std::endl;
    return 0;
}
