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

Node* removeValueFromList(Node* head, int value) {
	/*Given a singly linked list of integers and an integer, remove all elements from list that have a value equal to value.*/
	if (!head) return nullptr; // base case

	head->next = removeValueFromList(head->next, value); // check each node until last
	if (head->val == value) return head->next;
	return head;
}

int main() {
    Node *head = nullptr;
    head = addBeginning(head, 4);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);
    head = addBeginning(head, 1);
    head = addBeginning(head, 0);

    std::cout << "Given a singly linked list of integers and an integer, remove all elements from list that have a value equal to value" << std::endl;
    print(head);

    /*test*/
    std::cout << "remove: " << 4 << std::endl;
    head = removeValueFromList(head, 4);
    print(head);
    std::cout << "remove: " << 10 << std::endl;
    head = removeValueFromList(head, 10);
    print(head);
    std::cout << "remove: " << 0 << std::endl;
    head = removeValueFromList(head, 0);
    print(head);
    std::cout << "remove: " << 3 << std::endl;
    head = removeValueFromList(head, 3);
    print(head);
    std::cout << "remove: " << 1 << std::endl;
    head = removeValueFromList(head, 1);
    print(head);
    std::cout << "remove: " << 0 << std::endl;
    head = removeValueFromList(head, 0);
    print(head);
    return 0;
}
