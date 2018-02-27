#include <iostream>

struct Node {
    Node *next_;
    int data_ = 0;
};


bool push_front(const int data, Node *head_);

int main() {
    Node *head = new Node;
    head->next_ = NULL;
    
    push_front(1, head);
}




bool push_front(const int data, Node *head_){
    Node *newNode = new Node;
        newNode->next_ = NULL;
        newNode->data_ = data;
    /*
    if (empty()) {
        head_ = tail_ = newNode;
        size_++;
        return true;
    }
    */
    Node *tempPtr = head_;
    while (tempPtr->next_ != NULL){
        tempPtr = tempPtr->next_;
    }
    tempPtr->next_ = newNode;
    //tail_ = newNode;
    return true;
}
