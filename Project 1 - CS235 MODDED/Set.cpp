/*
 Student: Mohsen Akeel
 Instructor: Aarsh Vora
 Class: CS 235
 Project 1, Set header file.
	
	This file will generate a Set class based on the Vector Class in the 
	Vector header file. It will allow only unique integer elements.
*/



#include "Vector.h"

//Returns the current number of elements in the set
template <class Comparable>
unsigned int Set<Comparable>::size() const
{
    return set_.Vector<Comparable>::size();
}

//Returns the truth of the emptiness state of set_
template <class Comparable>
bool Set<Comparable>::empty() const
{
    return set_.Vector<Comparable>::empty();
}

//If the set contains data, return true, otherwise false
template <class Comparable>
bool Set<Comparable>::contains(const Comparable& data) const
{
    for (int i = 0; i < set_.Vector<Comparable>::size(); i++)
    {
        if (set_[i] == data)
        {
            return 1;
        }
    }
    
    return 0;
}

//If the set does not already contain data, add a new element, data, and return 
//true, otherwise false
template <class Comparable>
bool Set<Comparable>::insert(const Comparable& data)
{
    if (!(contains(data)))
    {
        set_.Vector<Comparable>::push_back(data);
        return 1;
    }
    else
    {
        return 0;
    }
}

//if the set contains data, remove data from the set and return true, otherwise 
//false
template <class Comparable>
bool Set<Comparable>::remove(const Comparable& data)
{
    if(contains(data))
    {
        set_.Vector<Comparable>::remove(data);
        return 1;
    }
    else
    {
        return 0;
    }
}

//Empties the set of its elements
template <class Comparable>
void Set<Comparable>::clear() 
{
    set_.Vector<Comparable>::clear();
    return;
}


