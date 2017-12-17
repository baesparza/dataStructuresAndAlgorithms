#include <iostream>

#define Print(x, y) printHead(x); printTail(y);

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

void removeThisElement(Node **head_ref, Node **tail_ref, int value) {
    /*remove FIRST element with the specified value start checking node from*/

    // check if list has items to be removed
    if (!(* head_ref)) {
        return; // linked list is empty
    }

    // head value need to be removed
    // move head
    if ((* head_ref)->val == value) {
        if ((* head_ref) == (* tail_ref)) {
            //case when there is one element in list and needs to be removed
            (* head_ref) = nullptr;
            (* tail_ref) = nullptr;
            return;
        }
        // move head and unlink first node
        (* head_ref) = (* head_ref)->next;
        (* head_ref)->prev = nullptr;
        return;
    }

    // check in list for value
    Node* current = (* head_ref);
    while (current->next && current->next->next) {
        // .next to keep reference
        // and stop one before tail
        if (current->next->val == value) {
            // .next node needs to be removed
            // unlink node that needs to be removed
            current->next = current->next->next;
            current->next->prev = current;
            return;
        }
        current = current->next;
    }

    // check tail
    // if tail.value needs to remove it, other wise not
    if ((* tail_ref)->val == value) {
        // move tail
        (* tail_ref) = (* tail_ref)->prev;
        (* tail_ref)->next = nullptr;
    }
}

int main() {
    Node *head = nullptr, *tail = nullptr;
    addBeginning(&head, &tail, 4);
    addBeginning(&head, &tail, 3);
    addBeginning(&head, &tail, 2);
    addBeginning(&head, &tail, 1);
    addBeginning(&head, &tail, 5);
    Print(head, tail);

    std::cout << "Remove: " << 4 <<std::endl;
    removeThisElement(&head, &tail, 4);
    Print(head, tail);

    std::cout << "Remove: " << 5 <<std::endl;
    removeThisElement(&head, &tail, 5);
    Print(head, tail);

    std::cout << "Remove: " << 2 <<std::endl;
    removeThisElement(&head, &tail, 2);
    Print(head, tail);

    return 0;
}
