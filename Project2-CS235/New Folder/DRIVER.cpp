#include "DRIVER.h"

void Driver<T>::mainMenu() {
    std::cout << "Welcome to your schedule book." << std::endl;
    std::cout << "Type HELP for more info" << std::endl;
    std::cin << userInput;
}


// Requests data from users and populates the member variables of the driver 
// class before moving the data into a new Node of the schedule list.
template <class T>
void Driver<T>::add() {
    //Node<T>* newNode = new Node<T>;
    
    std::cout << "What tupe of task is this? [G: Generic, S: Shopping, E: Event," 
                 "H:Homwork]" << std::endl;
    std::cin >> taskType_;
    taskType_ = tolower(taskType_); //make input lower case
    while (taskType_ != 'g' || taskType_ != 's' || taskType_ != 'e' || taskType_ != 'h') {
        std::cout << "Please enter a valid option. [G: Generic, S: Shopping," 
                     "E: Event,H:Homwork]" << std::endl;
    }
    
    std::cout << "When is this task due?" << std::endl;
    std::cin >> dateInput_;
    
    std::cout << "How would you describe this task?" << std::endl;
    std::cin >> taskDescInput_;
    
    // All fields above are applicable to all task types. From here on input is
    // task specific
    if (taskType_ == 's') {
        ShoppingTask newTask;
        newTask.set_date(dateInput_);
        newTask.set_tdesc(taskDescInput_);
        
        std::cout << "What items do you need to buy?" << std::endl;
        std::cin >> shoppingItemInput_;
        while(shoppingItemInput_ != "DONE") {
            newTask.push_list(shoppingItemInput_);
            std::cin >> shoppingItemInput_;
        }
        
    }
    else if (taskType_ == 'e') {
        EventTask newTask;
        newTask.set_date(dateInput_);
        newTask.set_tdesc(taskDescInput_);
        
        std::cout << "Where is this event taking place?" << std::endl;
        std::cin >> eventLocInput_;
        std::cout << "When is this event taking place?" << std::endl;
        std::cin >> eventTimeInput_;
        
        newTask.set_loc(eventLocInput_);
        newTask.set_time(eventTimeInput_);
    }
    else if (taskType_ == 'h') {
        HWTask newTask;
        newTask.set_date(dateInput_);
        newTask.set_tdesc(taskDescInput_);
        
        std::cout << "What subject is this homework task for?" << std::endl;
        std::cin >> courseInput_;
        
        newTask.set_course(courseInput_);
    }
    else {
        GenericTask newTask;
        newTask.set_date(dateInput_);
        newTask.set_tdesc(taskDescInput_);
    }
    
    addNewTask(newTask);
                 
}

void Driver<T>::print() {
    schedule_.SortedLinkedList<T>::print();
}

void Driver<T>::detailed() {
    schedule_.SortedLinkedList<T>::detailed();
}