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

void addAfter(Node **head_ref, Node **tail_ref, int value, int n) {
    /*First node index is 0*/
    Node * newNode = new Node(value);
    if (!(*head_ref) && !(*tail_ref)) { // special case, list node is empty
        (*head_ref) = newNode;
        (*tail_ref) = newNode;
        return;
    }

    // when needs to be added at the beginning, move head
    if (n == -1) {
        (*head_ref)->prev = newNode;
        newNode->next = (*head_ref);
        (*head_ref) = newNode;
        return;
    }

    int index = 0;
    Node* current = (*head_ref);
    while (current->next && index < n) { // get were new value will be inserted
        current = current->next;
        index++;
    }

    // when tail needs to be moved
    if (current==(*tail_ref)) {
        newNode->prev = (*tail_ref);
        (*tail_ref)->next = newNode;
        (*tail_ref) = newNode;
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
    addAfter(&head, &tail, 4, 0);
    addAfter(&head, &tail, 0, -1);
    addAfter(&head, &tail, 2, 0);
    addAfter(&head, &tail, 1, 0);
    addAfter(&head, &tail, 3, 2);
    addAfter(&head, &tail, 5, 5);
    printHead(head);
    printTail(tail);
    return 0;
}

