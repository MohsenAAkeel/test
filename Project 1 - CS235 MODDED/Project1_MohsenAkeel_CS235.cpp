#include <iostream>

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
        int get_array_size();
        int& operator[](unsigned int pos);
        Vector& operator=(const Vector& rhs);
        
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
        return 1;
    }
    else
    {
        return 0;
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
        //array_[array_size_] = NULL; //eliminate the duplicate element
        array_size_--; 
        return 1;
    }
    else
    {
        return 0;
    }
}

//Empties the vector of its elements and resets the capacity and size.
void Vector::clear()
{
    array_size_ = 0;
    array_capacity_ = 3;
    delete [] array_;
    array_ = new int[array_capacity_];
}

//If pos is a valid position in the vector, set the value of data to the element 
//of the vector at this position. Return true on succes, false on failure
bool Vector::at(unsigned int pos, int& data) const 
{
    if (pos <= array_size_)
    {
        array_[pos] = data;
        return 1;
    }
    else
    {
        return 0;
    }
}

//Generates a new array of size 2*array_capacity_ when array_ is filled.
void Vector::generate_larger_array()
{
    temp_array_ = new int(array_capacity_);
    for(int i=0; i<array_size_; i++)
    {
        temp_array_[i] = array_[i];
    }
    delete [] array_;
    array_ = temp_array_;
    temp_array_ = NULL;
}

int Vector::get_array_size()
{
    return array_size_;
}

int& Vector::operator[](unsigned int pos)
{
    return array_[pos];
}

Vector Vector::operator=(const Vector& new_array_)
{
    return array_[pos];
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
        Vector set_;
        
};

Set::Set()
{}

Set::Set(int input_element)
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
    for (int i = 0; i < set_.Vector::get_array_size(); i++)
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

void Set::clear() //Empties the set of its elements
{
    set_.Vector::clear();
}






int main()
{
    Set gary;
    
    gary.insert(4);
}

//remove is a blue word. and expects a value it never uses.