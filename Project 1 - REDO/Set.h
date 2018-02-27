#ifndef __CS235_SET_H_
#define __CS235_SET_H_

#include "Vector.h"

class Set {
  public:
	// Returns the number of elements in the Set
	unsigned int size() const;
	
	// Returns whether or not the Set has 0 elements
	bool empty() const;
	
	// If the Set contains data, returns true; otherwise, returns false
	bool contains(const int& data) const;
		
	// If the Set does not already contain data, adds
	// a new element, data, to the Set
	bool insert(const int& data);

	// If the Set contains data, removes data from the Set
	bool remove(const int& data);

	// Empties the Set of its elements
	void clear();

  private:
	Vector d_vector;

};


#include "Set.cpp"
#endif
