/*
 Student: Mohsen Akeel
 Instructor: Aarsh Vora
 Class: CS 235
 Project 1, Set header file.
	
	The implementation of 'Set.h'. This file will generate a Set class based on the Vector Class in the 
	Vector header file. It will allow only unique integer elements.
*/

#include "Set.h"
//#include "Vector.h"

//No parameters
//Returns the current number of elements in the set
unsigned int Set::size() const
{
    return set_.Vector::size();
}

//No parameters
//Returns the truth of the emptiness state of set_
bool Set::empty() const
{
    return set_.Vector::empty();
}

//Parameter: data point that is being introduced or removed from the container
//If the set contains data, return true, otherwise false
bool Set::contains(const int& data) const
{
    for (int i = 0; i < set_.Vector::size(); i++)
    {
        if (set_[i] == data)
        {
            return 1;
        }
    }
    
    return 0;
}

//parameter: data point that is to be entered into the Set
//If the set does not already contain data, add a new element, data, and return 
//true, otherwise false
bool Set::insert(const int& data)
{
    if (!(contains(data)))
    {
        set_.Vector::push_back(data);
        return 1;
    }
    else
    {
        return 0;
    }
}

//parameter: int data - variable that is to be removed from the Set
//if the set contains data, remove data from the set and return true, otherwise 
//false
bool Set::remove(const int& data)
{
    if(contains(data))
    {
        set_.Vector::remove(data);
        return 1;
    }
    else
    {
        return 0;
    }
}

//No parameters
//Empties the set of its elements
void Set::clear() 
{
    set_.Vector::clear();
    return;
}


