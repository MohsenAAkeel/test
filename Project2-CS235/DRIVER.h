#include "SortedLinkedList.h"
#include "TASKS.h"
#include <vector>
#include <iostream>

template <class T>
class Driver {
    private:
        std::string dateInput_;
        std::string taskDescInput_;
        std::string shoppingItemInput_;
        std::string eventLocInput_;
        std::string eventTimeInput_;
        std::string courseInput_;
        std::vector<std::string> shoppingItemList_;
        SortedLinkedList<T> schedule_;
        
    public:
        char taskType_;
        std::string userInput_;
        void mainMenu();
        void add();
        void print();
        void detailed();
};