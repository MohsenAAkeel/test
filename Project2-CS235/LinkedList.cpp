#include "LinkedList.h"


template <class T>
LinkedList<T>::LinkedList(){
        head_ = NULL;
        tail_ = NULL;
        size_ = 0;
}

template <class T>
int LinkedList<T>::size() {
    return size_;
}

template <class T>
bool LinkedList<T>::pop() {
    if (size() == 0) {
        return false;
    }
    Node<T> *temp = head_;
    while(temp->next_->next_ != NULL) {
        temp = temp->next_;
    }
    delete tail_;
    temp->next_ = NULL;
    tail_ = temp;
    size_--;
    return true;
}

template <class T>
bool LinkedList<T>::knock() {
    if (empty()) {
        return false;
    }
    int* temp = head_;
    head_ = head_->next_;
    delete temp;
    size_--;
}

//bool slice();

template <class T>
bool LinkedList<T>::push_front(const T& data){
    Node<T> *newNode = new Node<T>;
    newNode->next_ = NULL;
    newNode->data_ = data;
    if (empty()) {
        head_ = tail_ = newNode;
        size_++;
        return true;
    }
    Node<T> *tempPtr = head_;
    while (tempPtr->next_ != NULL){
        tempPtr = tempPtr->next_;
    }
    tempPtr->next_ = newNode;
    tail_ = newNode;
    size_++;
    return true;
}

template <class T>
bool LinkedList<T>::push_back(const T& data){
    Node<T> *newNode = new Node<T>;
    newNode->data_ = data;
    Node<T> *tempPtr = head_;
    head_ = newNode;
    newNode->next_ = tempPtr;
    size_++;
}

template <class T>
bool LinkedList<T>::insert(unsigned int index, const T& data){
    if (size() < index){
        return false;
    }
    Node<T> newNode = new Node<T>;
    newNode.data_ = data;
    if (index == 0) {
        if (push_back(data)) {
            size_++;
            return true;
        }
        return false;
    }
    Node<T> *tempPtr = head_;
    for (int i = 0; i == index-1; i++) {
        tempPtr = tempPtr->next_;
    }
    newNode->next_ = tempPtr->next_;
    tempPtr = newNode;
    size_++;
    return true;
}

template <class T>
bool LinkedList<T>::insert(unsigned int index, Node<T>& data) {
    if (size() < index){
        return false;
    }
    Node<T> *newNode = data;
    Node<T> *tempPtr = head_;
    for (int i = 0; i == index-1; i++) {
        tempPtr = tempPtr->next_;
    }
    newNode->next_ = tempPtr->next_;
    tempPtr = newNode;
    size_++;
    return true;
}

template <class T>
bool LinkedList<T>::remove(unsigned int index) { }

template <class T>
bool LinkedList<T>::empty() {
    if (size() == 0) {
        return true;
    }
    return false;
}

template <class T>
T LinkedList<T>::get(unsigned int index) { 
    Node<T> *tempPtr = head_;
    
    if(index >= size()) {
        throw "Invalid index."; //FIX THIS ERROR CHECK
    }
    
    for(int i=0; i<index; i++) {
        tempPtr = tempPtr->next_;
    }
    
    return tempPtr->data_;
}

template <class T>
T LinkedList<T>::top() const { 
    return tail_->data_;
}

