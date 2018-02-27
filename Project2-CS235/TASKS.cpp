#include "TASKS.h"

Date& Date::operator=(std::string date) {
    std::string day = "", 
                month = "", 
                year = "";
    int index=0;
    
    while(date[index] != '/') {
        month += date[index];
        index++;
    }
    index++;
    while(date[index] != '/') {
        day += date[index];
        index++;
    }
    index++;
    while(date[index] != '/') {
        year += date[index];
        index++;
    }
    
    month_ = std::stoi(month);
    day_ = std::stoi(day);
    year_ = std::stoi(year);
}


bool Date::operator<(const Date& lhs) {
    if (year_ < lhs.year_) {
        return true;
    }    
    else if (month_ < lhs.month_ && year_ == lhs.year_) {
        return true;
    }
    else if (day_ < lhs.day_ && month_ == lhs.month_ && year_ == lhs.year_) {
        return true;
    }
    else {
        return false;
    }
}

std::string GenericTask::get_date() {
    return std::to_string(dueDate_.get_month()) + '/' + std::to_string(dueDate_.get_day()) + '/' + std::to_string(dueDate_.get_year());
}

ShoppingTask::ShoppingTask() {
}

void ShoppingTask::push_list(std::string input) {
    shopList_.push_back(input);
}

std::string ShoppingTask::get_index(int index) {
    return shopList_[index];
}

