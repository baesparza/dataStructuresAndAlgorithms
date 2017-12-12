#include <iostream>
#include <string>

struct Node {
    /*singly_linked_list*/
    int val;
    Node *next;
    Node(int val) { this->val = val, this->next = nullptr; }
    Node(int val, Node * next) { this->val = val, this->next = next; }
};

void print(Node* current) {
    /*Print items in List*/
	std::cout << "Linked List : ";
	for ( ; current != nullptr; current = current->next) std::cout << "[" << current->val << "] -> ";
	std::cout << "null" << std::endl;
}

Node* addBeginning(Node* head, int value) {
	/*Adds a new node with a data field containing value to the beginning of the list*/
	return new Node(value, head); // create new node pointing actual head, and return new head
}

bool isListPalindrome(Node* head) {
	/*Given a singly linked list of integers, determine whether or not it's a palindrome.*/
	std::string temp= "";// were we'll store each node value
	if (!head) return true; // case were list is nullptr, so "" == "" return true
	Node* current = head;
	while (current) { // concatenate elements to be checked
		temp += current->val;
		current = current->next;
	}
	return temp == std::string(temp.rbegin(), temp.rend()); // compare main string with reversed string
}

int main() {
    std::cout << "Given a singly linked list of integers, determine whether or not it's a palindrome" << std::endl;

    /*test 1*/
    Node *head = nullptr;
    head = addBeginning(head, 2);
    head = addBeginning(head, 1);
    head = addBeginning(head, 0);
    head = addBeginning(head, 1);
    head = addBeginning(head, 2);

    print(head);
    if (isListPalindrome(head)) std::cout << "\tIs palindrome" << std::endl;
    else std::cout << "\tIs NOT palindrome" << std::endl;

    /*test 2*/
    head = nullptr;
    head = addBeginning(head, 0);
    head = addBeginning(head, 1);
    head = addBeginning(head, 2);
    head = addBeginning(head, 3);
    head = addBeginning(head, 4);

    print(head);
    if (isListPalindrome(head)) std::cout << "\tIs palindrome" << std::endl;
    else std::cout << "\tIs NOT palindrome" << std::endl;
    return 0;
}
