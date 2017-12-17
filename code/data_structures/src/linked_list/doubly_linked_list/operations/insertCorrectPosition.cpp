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

void insertCorrectPosition(Node **head_ref, Node **tail_ref, int value) {
    /*insert new item were it belong in sorted list*/
    Node* newNode = new Node(value);

    if (!(*head_ref) && !(*tail_ref)) { // check if list if empty
        // link head and tail with new node
        // unique node, already sorted
        (* head_ref) = newNode;
        (* tail_ref) = newNode;
        return;
    }

    // new element needs to go at the beginning
    // move head
    if (newNode->val < (*head_ref)->val) {
        newNode->next = (* head_ref);
        (* head_ref)->prev = newNode;
        (* head_ref) = newNode;
        return;
    }

    // search position in the list
    Node* current = (* head_ref);
    while (current->next && current->next->val < newNode->val) current = current->next;

    // if need's to be inserted at the end
    // move tail
    if (current == (* tail_ref)) { // check if we arrived tail
        newNode->prev = (* tail_ref);
        (* tail_ref)->next = newNode;
        (* tail_ref) = newNode;
        return;
    }

    // current has not arrive to tail
    // link current and .next with new node
    newNode->next = current->next;
    current->next->prev = newNode;
    newNode->prev = current;
    current->next = newNode;
}

int main() {
    Node *head = nullptr, *tail = nullptr;
    insertCorrectPosition(&head, &tail, 4);
    insertCorrectPosition(&head, &tail, 0);
    insertCorrectPosition(&head, &tail, 2);
    insertCorrectPosition(&head, &tail, 1);
    insertCorrectPosition(&head, &tail, 3);
    insertCorrectPosition(&head, &tail, 5);
    printHead(head);
    printTail(tail);
    return 0;
}


