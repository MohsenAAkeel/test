#include "SortedLinkedList.h"

template <class T>
SortedLinkedList<T>::SortedLinkedList() { }

template <class T>
bool SortedLinkedList<T>::addNewTask(T& data) {
    incomplete_.push_front(data); //push data to the front of the list
    return sort(incomplete_); //after data is pushed, sort the data into an 
                              //already sorted list
}

template <class T>
bool SortedLinkedList<T>::sort(LinkedList<T>& listIn) {
    //Set two pointers, one that will be advanced by one. Used to compare dates.
    Node<T> tempPtrLag = listIn.head_;
    Node<T> tempPtrAdv = listIn.head_->next_;
    int index = 0;
    while (tempPtrAdv->next_ != NULL) {
        if (CompareDate<T>(tempPtrAdv, tempPtrLag)) {
            listIn.remove(index);
            listIn.insert(index+1, tempPtrLag->data_);
            tempPtrAdv = tempPtrLag->next_;
        }
        else {
            tempPtrLag = tempPtrLag->next_;
            tempPtrAdv = tempPtrAdv->next_;
        }
    }
}

template <class T>
void SortedLinkedList<T>::print() {
    Node<T> *tempPtr = incomplete_.head_;
    int counter = 1;
    while (tempPtr->next_ != NULL) {
        std::cout << counter << ". " << tempPtr->data_.get_date() << " - " << tempPtr->data_.get_desc();
        tempPtr = tempPtr->next;
        counter++;
    }
}

/////////////////////
template <class T>
void SortedLinkedList<T>::detailed() {
    Node<T> *tempPtr = incomplete_.head_;
    int counter = 1;
    while (tempPtr->next_ != NULL) {
        std::cout << counter << ". " << tempPtr->data_.get_date() << " - " << 
                 tempPtr->data_.get_desc() << std::endl;
        
        tempPtr = tempPtr->next;
        counter++;
    }
}

/*///////////////
template <class T>
void SortedLinkedList<T>::detailed) {
    Node<T> *tempPtr = incomplete_.head_;
    int counter = 1;
    while (tempPtr->next_ != NULL) {
        std::cout << counter << ". " << tempPtr->data_.get_date() << " - " << 
                 tempPtr->data_.get_desc() << std::endl;
        
        tempPtr = tempPtr->next
        counter++;
    }
} 
*/
template <class T>
void SortedLinkedList<T>::complete() {
    Node<T> *tempPtr = incomplete_.head_;
    if (tempPtr == NULL) {
        std::cout << "There are no tasks to mark as complete." << std::endl;
    }
    else {
        int counter = 1;
        while (tempPtr->next_ != NULL) {
            std::cout << counter << ". " << tempPtr->data_.get_date() << " - " << 
                 tempPtr->data_.get_desc() << std::endl;
        
            tempPtr = tempPtr->next_;
            counter++;
        }
    
        int input;
        std::cout << "Select which you would like to remove." << std::endl;
        std::cin >> input;
        while (input > counter || input < 0) {
            std::cout << "Please make a valid selection." << std::endl;
        }
        
        tempPtr = incomplete_.head_;
        for (int i=1; i == counter; i++) {
            tempPtr = tempPtr->next_;
        }
        
        addCompTask(tempPtr->data_);
        incomplete_.remove(input-1);
    }
    
} 

template <class T>
void SortedLinkedList<T>::completed() {
    Node<T> *tempPtr = complete_.head_;
    int counter = 1;
    while (tempPtr->next_ != NULL) {
        std::cout << counter << ". " << tempPtr->data_.get_date() << " - " << 
                 tempPtr->data_.get_desc() << std::endl;
        
        tempPtr = tempPtr->next;
        counter++;
    }
} 

template <class T>
void SortedLinkedList<T>::addCompTask(T& data) {
    complete_.push_back(data);
}




