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

Node* addEnding(Node* head, int value) {
    /*Adds a new node with a data field containing value to the ending of the list*/
    if (!head) return new Node(value, nullptr); // ensure we have items, otherwise add first item to the list
    Node* current = head;
    while (current->next != nullptr) current = current->next; // iterate until we arrive to the [end - 1], to not lose ref
    current->next = new Node(value);
    return head;
}


int main() {
    Node *head = nullptr;
    std::cout << "Adds a new node with a data field containing value to the ending of the list" << std::endl;

    /*test*/
    std::cout << "addEnding: " << 0 << std::endl;
    head = addEnding(head, 0);
    print(head);
    std::cout << "addEnding: " << 1 << std::endl;
    head = addEnding(head, 1);
    print(head);
    std::cout << "addEnding: " << 2 << std::endl;
    head = addEnding(head, 2);
    print(head);
    std::cout << "addEnding: " << 3 << std::endl;
    head = addEnding(head, 3);
    print(head);
    std::cout << "addEnding: " << 4 << std::endl;
    head = addEnding(head, 4);
    print(head);
    return 0;
}
