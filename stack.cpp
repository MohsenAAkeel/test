#include <iostream>

template <class T>
class Stack{
    private:
        static const int CAPACITY = 10;
        T arr_[CAPACITY];
        int back_ = 0;
        
    public:
        Stack():back_(0){};
        int push(T & const data);
        int pop();
        T top();
};

template <class T>
int Stack<T>::push(T & const data){
    back_++;
    //std::cout << back_ << std::endl;
    if (back_ < CAPACITY)
    {
        arr_[back_] = data;
        return 0;
    } else {
        return -1;
    }
}

template <class T>
int Stack<T>::pop() {
    if (back_ == 0)
    {
        return -1;
    } else {
        back_--;
        return 0;
    }
}

template <class T>
T Stack<T>::top() {
    if (back_ == 0) {
        return -1;
    }
    return arr_[back_];
}

int main(){
    int data;
    Stack<int> stacks;
    
    stacks.push(1);
    //std::cout << stacks.top() << std::endl;
    //std::cout << stacks.pop();
    //std::cout << stacks.pop();
    for(int i=0; i<11; i++){
        stacks.push(i);
    }
    //std::cout << stacks.top() << std::endl;
    stacks.push(11);
    std::cout << stacks.top() << std::endl;
}
