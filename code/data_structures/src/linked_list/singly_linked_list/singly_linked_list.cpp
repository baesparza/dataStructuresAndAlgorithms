#include <iostream>

struct Node {
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
    Node(int val, Node * next) {
        this->val = val;
        this->next = next;
    }
};

void print(Node* current) {
	std::cout << "Linked List : ";
	while (current != nullptr) {
		std::cout << "[" << current->val << "] -> ";
		current = current->next;
	}
	std::cout << "null" << std::endl;
}

Node* addBeginning(Node* head, int value) {
	/*Adds a new node with a data field containing value to the beginning of the list*/
	return new Node(value, head); // create new node pointing actual head, and return new head
}

int main() {
    Node *head = nullptr;
    head = addBeginning(head, 4);
    head = addBeginning(head, 3);
    head = addBeginning(head, 2);
    head = addBeginning(head, 1);
    head = addBeginning(head, 0);

    print(head);
    return 0;
}
