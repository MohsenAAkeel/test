/*
 Student: Mohsen Akeel
 Instructor: Aarsh Vora
 Class: CS 235
 Project 1, Vector header file.
	
	The implementation of "vector.h". This file will generate a Vector class that contains integer elements
	through the use of dynamic array.
*/

//#include <cstdlib>
#include "Vector.h"
#include <iostream>
//parameter: capacity integer that sets the size of the array
//Constructor that will generate an empty vector of size capacity
Vector::Vector(unsigned int capacity) 
{
    
    array_ = new int[capacity];
    array_capacity_ = capacity;
}

//parameter: a second vector 
//does a full copy of the parameter into the current vector
Vector::Vector(const Vector& rhs)
{
	Vector temp_vec(rhs.Vector::size());
    int temp_element;
    for (int i=0; i<rhs.Vector::size(); i++)
    {
        rhs.Vector::at(i, temp_element);
        temp_vec.Vector::push_back(temp_element);
    }
    this->array_ = temp_vec.array_;
    array_size_ = rhs.size();
    array_capacity_ = rhs.capacity();
    temp_vec.array_ = NULL;
}


Vector::~Vector()
{
    delete [] array_;
}

//no parameters
//Returns the current number	of elements	in the vector.
unsigned int Vector::capacity() const
{
    return array_capacity_;
}

//no parameters
//Returns the current number	of elements	in the vector.
unsigned int Vector::size() const
{
    return array_size_;
}

//no parameters
//If the vector contains 0 elements, return true, otherwise return false
bool Vector::empty() const
{
    if (array_size_ == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//parameter: data, integer being inserted into the vector array
//Add data tot he end of the vector, double array size if necessary
void Vector::push_back(const int& data) 
{
    if (array_size_ == array_capacity_)
    {	
        array_capacity_ = 2 * array_capacity_;
        /*
        int * temp = new int(array_capacity_);
        temp = array_;
        delete [] array_;
        array_ = temp;
        temp = 0; 
        */
        generate_larger_array(array_capacity_);
        array_[array_size_] = data;
        array_size_++;
    }
    else if (array_size_ < array_capacity_)
    {
        array_[array_size_] = data;
        array_size_++;
    }
}

//parameter: data, integer, to be removed from the vector array
//If vector holds data, removes first instance of data and returns true. 
//otherwise returns false.
bool Vector::remove(const int& data) 
{
    if(array_size_ > 0)
    {
        for (int i=0; i < array_size_; i++)
        {
            if(array_[i] == data)
            {
                for(int j=i; j<array_size_-1; j++)
                {
                    array_[j] = array_[j+1];
                }
                array_size_--; 
                return 1;
            }
        }
        return 0;
    }
}


//No parameter
//Empties the vector of its elements and resets the capacity and size.
void Vector::clear()
{
    delete [] array_;
    array_size_ = 0;
    array_capacity_ = DEFAULT_CAPACITY;
    array_ = new int[DEFAULT_CAPACITY];
}

//parameters: pos and data, integers, to check for the data at a position and assign to data
//If pos is a valid position in the vector, set the value of data to the element 
//of the vector at this position. Return true on succes, false on failure
bool Vector::at(unsigned int pos, int& data) const 
{
    if (pos <= array_size_)
    {
        data = array_[pos];
        return 1;
    }
    else
    {
        return 0;
    }
}

//parameter: capacity, an integer, to generate a new array equal to that size
//Generates a new array of size 2*array_capacity_ when array_ is filled.
void Vector::generate_larger_array(unsigned int capacity)
{
    int * temp_array = new int(capacity);
    for(int i=0; i<array_size_; i++)
    {
        temp_array[i] = array_[i];
    }
    delete [] array_;
    array_ = temp_array;
    //temp_array = NULL;
}


//overloads index operator for Vector to return the element at pos within the 
//dynamic array
int& Vector::operator[](unsigned int pos) const
{
	return array_[pos];
}

//overload to allow copying of a Vector class to another. Returns pointer to new
//vector
/*
Vector& Vector::operator=(const Vector& rhs)
{
    //Vector temp_vec(rhs.Vector::size());
    Vector* temp_vec = new Vector(rhs.Vector::size());
    int temp_element;
    for (int i=0; i<rhs.Vector::size(); i++)
    {
        rhs.at(i, temp_element);
        temp_vec->push_back(temp_element);
    }
    //delete [] array_;
    
    this->array_ = temp_vec->array_;
    this->array_size_ = rhs.size();
    this->array_capacity_ = rhs.capacity();
    
    delete [] temp_vec;
    return *this;
}
*/
Vector& Vector::operator=(const Vector& rhs)
{
    int temp_element;
    
    
    for (int i=0; i<rhs.Vector::size(); i++)
    {
        rhs.at(i, temp_element);
        push_back(temp_element);
    }
    
    array_size_ = rhs.size();
    array_capacity_ = rhs.capacity();
}