#include "LinkedList.cpp"
#include <iostream>

int main() {
    LinkedList<int> list;
    
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    std::cout << list.top() << std::endl;
    std::cout << list.get(3);
}