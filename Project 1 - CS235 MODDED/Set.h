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

template <class Comparable>
class Set
{
    public:
        unsigned int size() const; 
        bool empty() const; 
        bool contains(const Comparable& data) const; 
        bool insert(const Comparable& data); 
        bool remove(const Comparable& data); 
        void clear();
        int get_size();
    private:
        Vector<Comparable> set_;
        
};
#include "Set.cpp"

#endif
