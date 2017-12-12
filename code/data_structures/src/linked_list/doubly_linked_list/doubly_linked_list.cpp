#include <iostream>

struct Node {
    Node* prev, next;
    int val;
    Node(int value) {
        this->val = value;
        this->next = nullptr;
        this->prev = nullptr
    }
};

Node* addBeginning(Node* head, Node* tail, int value) {

}
