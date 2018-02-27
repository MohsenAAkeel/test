#ifndef TASKS_H_
#define TASKS_H_

#include <iostream>
#include <vector>
#include <string>

class Date {
    int month_;
    int day_;
    int year_;
    
    public:
        Date& operator=(std::string date);
        bool operator<(const Date& lhs);
        virtual int get_month() {return month_;}
        virtual int get_day() {return day_;}
        virtual int get_year() {return year_;}
    
};

class GenericTask {
    protected:    
        std::string taskDescription_;
        Date dueDate_;
        char taskChar;
        void set_char(char a) {taskChar = a;}
        char get_char() {return taskChar;}
    public:
        virtual void set_date(std::string date) {dueDate_ = date;};
        virtual void set_tdesc(std::string desc) {taskDescription_ = desc;};
        virtual std::string get_desc() {return taskDescription_;}
        virtual std::string get_date();
        
        
};

class ShoppingTask:public GenericTask {
    private:
        std::vector<std::string> shopList_;
    public:
        ShoppingTask();
        void push_list(std::string input);
        std::string get_index(int index);
    
};

class EventTask:public GenericTask {
    private:
        std::string location_;
        std::string time_;
    public:
        EventTask();
        void set_loc(std::string loc) {location_ = loc;}
        void set_time(std::string inTime) {time_ = inTime;}
        std::string get_loc() {return location_;}
        std::string get_time() {return time_;}
};

class HWTask:public GenericTask {
    private:
        std::string course_;
    public:
        HWTask();
        void set_course(std::string course) {course_ = course;}
        std::string get_course() {return course_;}
};

#endif
