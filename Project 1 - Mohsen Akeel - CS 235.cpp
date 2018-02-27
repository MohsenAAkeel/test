#include <iostream>
#include <vector>


class Vector
{
    
    public:
        Vector();
    
        //Vector Functions
        unsigned int capacity() const; 
        unsigned int size() const; 
        bool empty() const; 
        void push_back(const int& data); 
        bool remove(const int& data); 
        void clear(); 
        bool at(unsigned int pos, int& data) const;
        
    private:
        void generate_larger_array();
        int array_size_ = 0;
        int array_capacity_ = 3;
        int array_input_;
        int *array_;
        int *temp_array_;

};

Vector::Vector() 
{
    array_ = new int[array_capacity_];
}

//Returns the current number	of elements	in the vector.
unsigned int Vector::capacity() const
{
    return array_capacity_;
}

//Returns the current number	of elements	in the vector.
unsigned int Vector::size() const
{
    return array_size_;
}

//If the vector contains 0 elements, return true, otherwise return false
bool Vector::empty() const
{
    if (array_size_ == 0)
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

//Add data tot he end of the vector, double array size if necessary
void Vector::push_back(const int& data) 
{
    if (array_size_ == (array_capacity_ - 1))
    {
        array_capacity_ = 2 * array_capacity_;
        generate_larger_array();
        array_[array_size_] = data;
    }
    else if (array_size_ < array_capacity_)
    {
        array_[array_size_] = data;
        array_size_++;
    }
}

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
                for(int j=i; j<array_size_; j++)
                {
                    array_[j] = array_[j+1];
                }
                break;
            }
        }
        array_[array_size_] = NULL; //eliminate the duplicate element
        array_size_--; 
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//Empties the vector of its elements and resets the capacity and size.
void Vector::clear();
{
    array_size_ = 0;
    array_capacity_ = 3;
    delete [] array_;
    array_ = new int[array_capacity_];
}

//If pos is a valid position in the vector, set the value of data to the element 
//of the vector at this position. Return true on succes, false on failure
bool Vector::at(unsigned int pos, int& data); const 
{
    if (pos <= array_size_)
    {
        array_[pos] = data;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//Generates a new array of size 2*array_capacity_ when array_ is filled.
void Vector::generate_larger_array()
{
    temp_array_ = new int(array_capacity_)
    for(int i=0; i<array_size_; i++)
    {
        temp_array_[i] = array_[i];
    }
    delete [] array_;
    array_ = temp_array_;
    temp_array_ = NULL;
}













// SET CLASS ###################################################################
class Set
{
    public:
        Set();
        Set(int);
        unsigned int size() const; 
        bool empty() const; 
        bool contains(const int& data) const; 
        bool insert(const int& data); 
        bool remove(const int& data); 
        void clear();
    private:
        int element_;
        Void set_;
        
};

void Set::Set()
{}

void Set::Set(int input_element)
{
    set_.Vector::push_back(input_element);
}

//Returns the current number of elements in the set
unsigned int Set::size() const
{
    return set_.Vector::size();
}

bool Set::empty() const
{
    return set_.Vector::empty();
}

//If the set contains data, return true, otherwise false
bool Set::contains(const int& data) const
{
    for (int i = 0; i < array_size_; i++)
    {
        if (set_[i] == data)
        {
            return TRUE;
        }
    }
    
    return FALSE;
}

//If the set does not already contain data, add a new element, data, and return 
//true, otherwise false
bool insert(const int& data)
{
    if (!contains(data));
    {
        set_.Vector::push_back(data);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//if the set contains data, remove data from the set and return true, otherwise 
//false
bool remove(const int& data)
{
    if(contains(data))
    {
        set_.Vector::remove(data);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void clear() //Empties the set of its elements
{
    set_.Vector::clear();
}






int main() {
	
	//Testing Construction
	Vector aVec;
	assert(aVec.empty());
	assert(aVec.size() == 0);
	assert(aVec.capacity() == 3);

	//Testing Push Back
	aVec.push_back(5);
	aVec.push_back(3);
	
	assert(aVec.size() == 2);
	assert(!aVec.empty());

	//Testing accessors
	assert(aVec[0] == 5);
	
	int data; 
	assert(aVec.at(0, data));
	assert(data == 5);

	assert(aVec.at(3, data) == false);
	assert(aVec.at(-1, data) == false);

	//Testing Copy & Assignment 
	Vector vectorB(aVec);
	Vector vectorC;
	vectorC = vectorB;

	
	assert(vectorB.size() == 2);
	assert(vectorC.size() == 2);
	//cout << aVec[0] << "\n";
	//cout << vectorB[0] << "\n";
	//cout << vectorC[0] << "\n";
	assert(vectorB[0] == 5);
	assert(vectorC[0] == 5);

	//Testing Remove
	assert(!vectorC.remove(10));
	vectorC.push_back(5);
	assert(vectorC.size() == 3);
	assert(vectorC.remove(5));
	assert(vectorC.size() == 2);
	assert(vectorC[0] == 3);
	assert(vectorC[1] == 5);
	vectorC.push_back(6);
	assert(vectorC.remove(5));
	assert(vectorC[0] == 3);
	assert(vectorC[1] == 6);

	//Testing Resize
	vectorC.push_back(1);
	vectorC.push_back(2);
	vectorC.push_back(3);
	vectorC.push_back(4);
	vectorC.push_back(5);

	//Testing Clear
	aVec.clear();
	assert(aVec.empty());


	//Testing Set Construction
	Set aSet;
	assert(aSet.empty());
	assert(aSet.size() == 0);

	//Testing Insert
	assert(aSet.insert(19));
	assert(aSet.size() == 1);
	assert(aSet.insert(29));
	assert(!aSet.insert(19));
	assert(aSet.size() == 2);
	assert(aSet.contains(19));
	assert(aSet.contains(29));
	assert(!aSet.contains(39));

	//Testing Remove
	assert(aSet.remove(19));
	assert(!aSet.contains(19));
	assert(aSet.size() == 1);
	assert(aSet.insert(19));
	assert(aSet.contains(19));

	//Testing Clear
	aSet.clear();
	assert(aSet.empty());

	cout << "DONE!" << endl;
	return 0;
}



//remove is a blue word. and expects a value it never uses.