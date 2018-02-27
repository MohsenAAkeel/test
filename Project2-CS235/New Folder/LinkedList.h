#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>

template <class T>
struct Node {
    Node<T> *next_;
    T data_;
};

template <class T>
class LinkedList {
    private: 
        Node<T> *head_ = NULL;
        Node<T> *tail_ = NULL;
        unsigned int size_ = 0;
        
    public:
        LinkedList();
        int size(); //get the size of the list
        bool pop(); //remove the last element in the list
        bool knock(); //remove the first element in the list
        bool slice();
        bool push_front(const T& data); //push an element into the front of the list
        bool push_back(const T& data); //push an element into the back of the list
        bool insert(unsigned int index, const T& data); //insert an element at some specified index
        bool remove(unsigned int index); //remove an element form some specified index
        bool insert(unsigned int index, Node<T>& data);
        bool empty(); //determine if the list is empty (return true if empty)
        T get(unsigned int index); //get the datum at a specified index
        T top() const; //get the datum of the last list object
};

//include "LinkedList.cpp"
#endif