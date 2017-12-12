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

Node* findValue(Node* head, int value) {
	/*Returns a pointer to the node containing value in the data field,
	or NULL if it is not in the list. This method can be used for membership checking as well*/
	Node* current = head;
	while (current) { // search if value exist
		if (current->val == value) return current;
		current = current->next;
	}
	return nullptr; // value does not exist
}


int main() {
    Node *head = nullptr;
    head = addBeginning(head, 4);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);
    head = addBeginning(head, 1);
    head = addBeginning(head, 0);

    std::cout << "Returns a pointer to the node containing or NULL" << std::endl;
    print(head);

    /*test*/
    std::cout << "findValue: " << 4 << std::endl;
    if (findValue(head, 4)) std::cout << "\tvalue 4 found" << std::endl;
    else std::cout << "\tvalue NOT found" << std::endl;
    std::cout << "findValue: " << 0 << std::endl;
    if (findValue(head, 0)) std::cout << "\tvalue 0 found" << std::endl;
    else std::cout << "\tvalue NOT found" << std::endl;
    std::cout << "findValue: " << 10 << std::endl;
    if (findValue(head, 10)) std::cout << "\tvalue 10 found" << std::endl;
    else std::cout << "\tvalue NOT found" << std::endl;

    return 0;
}
