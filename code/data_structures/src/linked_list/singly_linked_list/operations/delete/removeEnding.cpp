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

Node* removeEnding(Node* head) {
    /*Remove last item in linked List*/
    if (head == nullptr) return head; // check if we have items to remove
    if (head->next == nullptr) return nullptr; // if we only have one item, we have to remove it directly from the head
    Node* current = head;
    while (current->next->next != nullptr) current = current->next; // stop one before the last node
    current->next = nullptr; // remove last node pointer
    return head;
}

int main() {
    Node *head = nullptr;
    head = addBeginning(head, 4);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);
    head = addBeginning(head, 1);
    head = addBeginning(head, 0);

    std::cout << "Remove last item in linked List" << std::endl;
    print(head);

    /*test*/
    head = removeEnding(head);
    print(head);
    head = removeEnding(head);
    print(head);
    head = removeEnding(head);
    print(head);
    head = removeEnding(head);
    print(head);
    head = removeEnding(head);
    print(head);
    head = removeEnding(head);
    print(head);
    return 0;
}
