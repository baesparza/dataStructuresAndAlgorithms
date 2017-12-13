#include <iostream>

struct Node {
    Node* prev;
    Node* next;
    int val;
    Node(int value) {
        this->val = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void printHead(Node* current) {
	std::cout << "From Head: ";
	while (current != nullptr) {
		std::cout << "[" << current->val << "] -> ";
		current = current->next;
	}
	std::cout << "null" << std::endl;
}

void printTail(Node* current) {
	std::cout << "From Tail: ";
	while (current != nullptr) {
		std::cout << "[" << current->val << "] -> ";
		current = current->prev;
	}
	std::cout << "null" << std::endl;
}

void addBeginning(Node **head_ref, Node **tail_ref, int value) {
    Node * newNode = new Node(value);
    if (!(*head_ref) && !(*tail_ref)) { // special case, add first node
        (*head_ref) = newNode;
        (*tail_ref) = newNode;
        return;
    }
    newNode->next = (*head_ref);
    (*head_ref)->prev = newNode;
    (*head_ref) = newNode;
}

int main() {
    Node *head = nullptr, *tail = nullptr;
    addBeginning(&head, &tail, 4);
    addBeginning(&head, &tail, 3);
    addBeginning(&head, &tail, 2);
    addBeginning(&head, &tail, 1);
    addBeginning(&head, &tail, 5);
    printHead(head);
    printTail(tail);
    return 0;
}
