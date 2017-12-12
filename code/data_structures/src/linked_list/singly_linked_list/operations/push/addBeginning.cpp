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

int main() {
    Node *head = nullptr;

    std::cout << "Adds a new node with a data field containing value to the beginning of the list" << std::endl;
    print(head);

    /*test*/
    std::cout << "addBeginning: " << 4 << std::endl;
    head = addBeginning(head, 4);
    print(head);
    std::cout << "addBeginning: " << 1 << std::endl;
    head = addBeginning(head, 1);
    print(head);
    std::cout << "addBeginning: " << 4 << std::endl;
    head = addBeginning(head, 4);
    print(head);
    std::cout << "addBeginning: " << 0 << std::endl;
    head = addBeginning(head, 0);
    print(head);
    std::cout << "addBeginning: " << 3 << std::endl;
    head = addBeginning(head, 3);
    print(head);
    std::cout << "addBeginning: " << 0 << std::endl;
    head = addBeginning(head, 0);
    print(head);
    return 0;
}
