/*
 Student: Mohsen Akeel
 Instructor: Aarsh Vora
 Class: CS 235
 Project 1, Vector header file.
	
	This file will generate a Vector class that contains integer elements
	through the use of a dynamic array.
*/
#ifndef __CS235_VECTOR_H_
#define __CS235_VECTOR_H_
#include <cstdlib>

template <class Type>
class Vector
{
    
    public:
        Vector(unsigned int capacity = DEFAULT_CAPACITY);
        Vector(const Vector<Type>& rhs);
        ~Vector();
        unsigned int capacity() const; 
        unsigned int size() const; 
        bool empty() const; 
        void push_back(const Type& data); 
        bool remove(const Type& data); 
        void clear(); 
        bool at(unsigned int pos, Type& data) const;
        int get_array_size() const;
        Type& operator[](unsigned int pos) const;
        Vector& operator=(const Vector& rhs);
        
    private:
    	static const unsigned int DEFAULT_CAPACITY = 3;
        void generate_larger_array(unsigned int capacity);
        int array_size_ = 0;
        int array_capacity_;
        Type *array_;

};



#include "Vector.cpp"

#endif
