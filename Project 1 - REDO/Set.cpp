#ifndef __CS235_SET_CPP_
#define __CS235_SET_CPP_

#include "Set.h"


// Returns the number of elements in the Set
unsigned int Set::size() const
{
    return d_vector.Vector::size();
}
	
// Returns whether or not the Set has 0 elements
bool Set::empty() const
{
    return d_vector.Vector::empty();
}
	
// If the Set contains data, returns true; otherwise, returns false
bool Set::contains(const int& data) const
{
    for(int i=0; i<d_vector.Vector::size(); ++i)
    {
        if(d_vector[i] == data)    
            return 1;
    }
        return 0;
}

// If the Set does not already contain data, adds
// a new element, data, to the Set
bool Set::insert(const int& data)
{
    if (!(contains(data)))   
    {    
        d_vector.Vector::push_back(data);
        return 1;
    }
    return 0;
            
}

// If the Set contains data, removes data from the Set
bool Set::remove(const int& data)
{
    d_vector.Vector::remove(data);
}

// Empties the Set of its elements
void Set::clear()
{
    d_vector.Vector::clear();
}

#endif