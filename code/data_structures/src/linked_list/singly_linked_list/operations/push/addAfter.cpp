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

Node* addAfter(Node* head, int value, int n) {
	/*Adds a new node with a data field containing value after node n*/
	/*Important: first node index is 0*/
	if (n < 0 || !head) return addBeginning(head, value); // return new beginning
	int count = 0;
	Node* current = head;
	while (current) {
		if (count == n || !current->next) { // arrive were new node needs to be inserted or case when n is equal or higher than list length
			current->next = addBeginning(current->next, value); // add new node after current node, that point to rest of the list
			break;
		}
		count++;
		current = current->next;
	}
	return head; // return result list
}

int main() {
    Node *head = nullptr;
    head = addBeginning(head, 4);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);
    head = addBeginning(head, 1);
    head = addBeginning(head, 0);

    std::cout << "Adds a new node with a data field containing value after node n" << std::endl;
    print(head);

    /*test*/
    std::cout << "addAfter: " << 0 << "; value: " << 99 << std::endl;
    head = addAfter(head, 99, 0);
    print(head);
    std::cout << "addAfter: " << 3 << "; value: " << 99 << std::endl;
    head = addAfter(head, 99, 3);
    print(head);
    std::cout << "addAfter: " << -1 << "; value: " << 99 << std::endl;
    head = addAfter(head, 99, -1);
    print(head);
    return 0;
}
