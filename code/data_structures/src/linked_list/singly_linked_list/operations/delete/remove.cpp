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

Node* remove(Node* head, int value) {
	/*Removes first instance of value from list*/
	if (!head) return head; // check if we have elements to remove
	if (head->val == value) return head->next; // check if head need's to be removed, so return next value
	Node* current = head;
	while (current->next) { // stop one before the item to be removed to keep the reference
		if (current->next->val == value) {
			current->next = current->next->next;
			return head;
		}
		current = current->next;
	}
	return head; // if any Node has the value that needs to be removed
}

int main() {
    Node *head = nullptr;
    head = addBeginning(head, 4);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);
    head = addBeginning(head, 1);
    head = addBeginning(head, 0);

    std::cout << "Removes first instance of value from list" << std::endl;
    std::cout << "remove: " << 4 << std::endl;
    head = remove(head, 4);
    print(head);
    std::cout << "remove: " << 1 << std::endl;
    head = remove(head, 1);
    print(head);
    std::cout << "remove: " << 4 << std::endl;
    head = remove(head, 4);
    print(head);
    std::cout << "remove: " << 0 << std::endl;
    head = remove(head, 0);
    print(head);
    std::cout << "remove: " << 3 << std::endl;
    head = remove(head, 3);
    print(head);
    std::cout << "remove: " << 0 << std::endl;
    head = remove(head, 0);
    print(head);
    return 0;
}
