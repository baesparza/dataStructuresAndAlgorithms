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

Node* removeThisElement(Node* head, int n) {
	/*Removes node n*/
	/*Important: first node index is 0*/
	if (!head || n < 0) return head; // check if we have items to remove from or remove an element with an impossible index
	if (n == 0) return head->next; // check if first item need to be removed
	Node* current = head;
	int count = 1; // start at one, since case n = 0, already solved
	while (current->next) {
		if (count == n) {
			// reLink next element, with next->next, and return
			current->next = current->next->next;
			return head;
		}
		current = current->next;
		count++;
	}
	// no need to check list.length == n, since node n is nullptr
	return head;
}

int main() {
    Node *head = nullptr;
    head = addBeginning(head, 4);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);
    head = addBeginning(head, 1);
    head = addBeginning(head, 0);

    std::cout << "Removes node n" << std::endl;
    std::cout << "Important: first node index is 0" << std::endl;
    print(head);

    /*test*/
    std::cout << "remove: " << 4 << std::endl;
    head = removeThisElement(head, 4);
    print(head);
    std::cout << "remove: " << -1 << std::endl;
    head = removeThisElement(head, -1);
    print(head);
    std::cout << "remove: " << 10 << std::endl;
    head = removeThisElement(head, 10);
    print(head);
    std::cout << "remove: " << 2 << std::endl;
    head = removeThisElement(head, 2);
    print(head);
    std::cout << "remove: " << 0 << std::endl;
    head = removeThisElement(head, 0);
    print(head);
    std::cout << "remove: " << 1 << std::endl;
    head = removeThisElement(head, 1);
    print(head);
    std::cout << "remove: " << 0 << std::endl;
    head = removeThisElement(head, 0);
    print(head);
    return 0;
}
