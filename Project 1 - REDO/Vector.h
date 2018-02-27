#ifndef __CS235_VECTOR_H_
#define __CS235_VECTOR_H_

class Vector {
  public:
	//Constructors and Assignment Operator
	Vector(unsigned int capacity = DEFAULT_CAPACITY);
	~Vector();
	Vector(const Vector& rhs);
	Vector& operator=(const Vector& rhs);

	// Returns the total amount of space currently allocated for the vector
	unsigned int capacity() const;
	
	// Returns the number of elements in the vector
	unsigned int size() const;
	
	// Returns whether or not the vector has 0 elements
	bool empty() const;
	
	// If the vector does not already contain data, adds
	// a new element, data, to the front of the vector
	void push_back(const int& data);
	
	// If the vector contains data, removes data from the vector
	bool remove(const int& data);
	
	// Empties the vector of its elements
	void clear();

	// Returns a reference to the element in position pos. 
	int& operator[](unsigned int pos);
	const int& operator[](unsigned int pos) const;

	// If pos is a valid position, retrieves the element in position pos in the
	// array, stores it in data, and returns true; otherwise, returns false
	bool at(unsigned int pos, int& data) const;


  private:
	int* d_arr;
	unsigned int d_size = 0;
	unsigned int d_capacity;

	static const unsigned int DEFAULT_CAPACITY = 3;

	// Helper Function: Reallocates a newCapacity amount of space for the vector and copies the elements over
	void resize(unsigned int capacity);
	
};
#include "Vector.cpp"
#endif