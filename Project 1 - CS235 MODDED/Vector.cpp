/*
 Student: Mohsen Akeel
 Instructor: Aarsh Vora
 Class: CS 235
 Project 1, Vector header file.
	
	This file will generate a Vector class that contains integer elements
	through the use of a dynamic array.
*/

#include <cstdlib>
#include "Set.h"

template <class Type>
Vector<Type>::Vector(unsigned int capacity) 
{
    array_ = new Type[capacity];
    array_capacity_ = capacity;
}

template <class Type>
Vector<Type>::Vector(const Vector& rhs)
{
	Vector<Type> temp_vec(rhs.Vector::size());
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

template <class Type>
Vector<Type>::~Vector()
{
    //delete[] array_;
}

//Returns the current number	of elements	in the vector.
template <class Type>
unsigned int Vector<Type>::capacity() const
{
    return array_capacity_;
}

//Returns the current number	of elements	in the vector.
template <class Type>
unsigned int Vector<Type>::size() const
{
    return array_size_;
}

//If the vector contains 0 elements, return true, otherwise return false
template <class Type>
bool Vector<Type>::empty() const
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

//Add data tot he end of the vector, double array size if necessary
template <class Type>
void Vector<Type>::push_back(const Type& data) 
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

//If vector holds data, removes first instance of data and returns true. 
//otherwise returns false.
template <class Type>
bool Vector<Type>::remove(const Type& data) 
{
    if(array_size_ > 0)
    {
        for (int i=0; i < array_size_; i++)
        {
            if(array_[i] == data)
            {
                for(int j=i; j<array_size_; j++)
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

//Empties the vector of its elements and resets the capacity and size.
template <class Type>
void Vector<Type>::clear()
{
    delete [] array_;
    array_size_ = 0;
    array_capacity_ = DEFAULT_CAPACITY;
    array_ = new Type[DEFAULT_CAPACITY];
}

//If pos is a valid position in the vector, set the value of data to the element 
//of the vector at this position. Return true on succes, false on failure
template <class Type>
bool Vector<Type>::at(unsigned int pos, Type& data) const 
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

//Generates a new array of size 2*array_capacity_ when array_ is filled.
template <class Type>
void Vector<Type>::generate_larger_array(unsigned int capacity)
{
    int * temp_array = new Type(capacity);
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
template <class Type>
Type& Vector<Type>::operator[](unsigned int pos) const
{
	return array_[pos];
}

//overload to allow copying of a Vector class to another. Returns pointer to new
//vector
template <class Type>
Vector<Type>& Vector<Type>::operator=(const Vector<Type>& rhs)
{
    Vector<Type> temp_vec(rhs.Vector::size());
    int temp_element;
    for (int i=0; i<rhs.Vector::size(); i++)
    {
        rhs.at(i, temp_element);
        temp_vec.push_back(temp_element);
    }
    delete [] array_;
    this->array_ = temp_vec.array_;
    this->array_size_ = rhs.size();
    this->array_capacity_ = rhs.capacity();
    //temp_vec.array_ = NULL;
    return *this;
}

#include "Set.cpp"

