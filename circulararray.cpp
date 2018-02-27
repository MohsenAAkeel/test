//Keep spitting out a 1 after the array is found empty from get_bot fxn.

#include <iostream>
#include <assert.h>
#include <string>

template <class T>
class CircArr{
    private:
        int top_; 
        int bot_;
        static const int ARR_SIZE = 9;
        //int DEFAULT_CAP_ = 3;
        T arr_[ARR_SIZE];
        
    public:
        CircArr():top_(0), bot_(0){};
        bool push_top(const T& data);
        bool push_bot(const T& data);
        bool pop_top();
        bool pop_bot();
        
        T get_top();
        T get_bot();
};

template <class T>
bool CircArr<T>::push_top(const T& data){
    if ((top_-bot_)%ARR_SIZE < ARR_SIZE-1){
        arr_[top_] = data;
        top_++;
        return true;
    } else {
        return false;
    }
}

template <class T>
bool CircArr<T>::pop_top(){
    if (top_ == bot_){
        return false;
    } else {
        top_--;
        return true;
    }
}

template <class T>
bool CircArr<T>::push_bot(const T& data){
    
    
    
    bot_--;
    int temp = bot_;
    
    if ((top_-temp)%ARR_SIZE < ARR_SIZE-1){
        arr_[temp%ARR_SIZE] = data;
        return true;
    } else {
        bot_++;
        return false;
    }
}

template <class T>
bool CircArr<T>::pop_bot(){
    if(top_ == bot_){
        return false;
    } else {
        bot_++;
        return true;
    }
}

template <class T>
T CircArr<T>::get_top(){
    if(top_!=bot_){
        if (top_ < 0) {
            std::cout << (top_%ARR_SIZE) + (ARR_SIZE) << std::endl;
            return arr_[(top_%ARR_SIZE) + (ARR_SIZE-1)];
        }
        return arr_[(top_-1)%ARR_SIZE];
    }
    try
    {
        throw 3;
    }
    catch (int e)
    {
        std::cout << "Array is empty! ";
    }
}

template <class T>
T CircArr<T>::get_bot(){
    std::cout << top_ << " and " << bot_ << std::endl;
    if(top_!=bot_){
        if (bot_ < 0) {
            std::cout << (bot_%ARR_SIZE) + (ARR_SIZE) << std::endl;
            return arr_[(bot_%ARR_SIZE) + (ARR_SIZE-1)];
        }
        return arr_[bot_%ARR_SIZE];
    }
    
    
    try
    {
        throw 3;
    }
    catch (int e)
    {
        std::cout << "Array is empty!" << '\n';
    }
    
}

int main(){
    CircArr<int> array;
    
    assert(array.push_top(1));
    assert(array.push_top(2));
    assert(array.push_top(3));
    assert(array.push_top(4));
    assert(array.push_top(5));
    assert(array.push_top(6));
    assert(array.push_top(7));
    assert(array.push_top(8));
    assert(!(array.push_top(9)));
    assert(!(array.push_top(1)));
    //array.push_top(10);
    //array.push_top(11234);
    std::cout << array.get_top() << std::endl;
    std::cout << array.get_bot() << std::endl;
    array.pop_bot();
    std::cout << array.get_bot() << std::endl;
    array.pop_bot();
    array.pop_bot();
    array.pop_bot();
    std::cout << array.get_bot() << std::endl;
    array.pop_bot();
    array.pop_bot();
    array.pop_bot();
    array.pop_bot();
    array.pop_bot();
    
   std::cout << array.get_top() << std::endl;

    
    return 0;
}