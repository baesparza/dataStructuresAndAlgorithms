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

Node* insertionSortList(Node* head) {
    if (!head || !head->next) return head; // check if we have items to sort
    // insert items sorted in a new list as we iterate main list
    Node* sortedList = new Node(-99999); // create a new head, were sorted values will be stored
    Node* current = head;
    while(current) {
        Node* sorted_current = sortedList; // iterate through sorted list searching correct position of current value
        while(sorted_current->next && sorted_current->next->val < current->val) sorted_current = sorted_current->next;
        // move through new array and stop on last item to keep reference, and one before were the value is higher were needs to be stored
        Node* temp = new Node(current->val);
        temp->next = sorted_current->next; // keep the reference of node that needs to go after
        sorted_current->next = temp; // link new node to new list
        current=current->next;
    }
    return sortedList->next; // return sorted list as main list
}

int main() {
    Node *head = nullptr;
    head = addBeginning(head, 1);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);
    head = addBeginning(head, 0);
    head = addBeginning(head, 5);

    std::cout << "Insertion Sort List" << std::endl;
    print(head);
    std::cout << "sort: " << std::endl;
    head = insertionSortList(head);
    print(head);
    std::cout << "addBeginning: " << 99 << std::endl;
    head = addBeginning(head, 99);
    print(head);
    std::cout << "sort: " << std::endl;
    head = insertionSortList(head);
    print(head);
    return 0;
}
