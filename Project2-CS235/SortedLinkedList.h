/* add checks */
#include "LinkedList.h"
#include <iostream>

template <class T>
struct CompareDate {
    bool operator()(const Node<T> &rhs, const Node<T> &lhs) {
        return lhs->dueDate < rhs->dueDate;
    }
};

template <class T>
class SortedLinkedList {
    private:
        LinkedList<T> complete_;
        LinkedList<T> incomplete_;
        
    public:
        SortedLinkedList();
        void print();
        void detailed();
        void remove();
        void complete();
        void completed();
        bool save();
        bool load();
        void exitApp();
        bool addNewTask(T& data);
        void addCompTask(T& data);
        bool sort(LinkedList<T>& listIn);
        
};