/*
 Student: Mohsen Akeel
 Instructor: Aarsh Vora
 Class: CS 235
 Project 1, Set header file.
	
	This file will generate a Set class based on the Vector Class in the 
	Vector header file. It will allow only unique integer elements.
*/

#ifndef __CS235_SET_H_
#define __CS235_SET_H_

#include "Vector.h"

class Set
{
    public:
        unsigned int size() const; 
        bool empty() const; 
        bool contains(const int& data) const; 
        bool insert(const int& data); 
        bool remove(const int& data); 
        void clear();
        int get_size();
    private:
        Vector set_;
        
};

#include "Set.cpp"
#endif
