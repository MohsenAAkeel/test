#include <iostream>

class LinkedList


LinkedList::LinkedList(const LinkedList& one, const LinkedList& two) {
    int* first = one.head_;
    int* second = two.head_;
    
    while(first->next != NULL || second->next != NULL) {
        if  (second->next == NULL) {
            this.push_back(first->next.data_);
            first = first->next;
        }
        else if(first->next == NULL || second->next.data_ < first->next.data_) {
            this.push_back(second->next.data_);
            second = second->next;
        } 
        else {
            this.push_back(first->next.data_);
            first = first->next;
        }
    }
}


