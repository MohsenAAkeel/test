#ifndef __CS235_VECTOR_CPP_
#define __CS235_VECTOR_CPP_

#include "Vector.h"

Vector::Vector(unsigned int capacity)
{
    d_arr = new int(d_capacity);
    d_capacity = capacity;
    
}

Vector::~Vector()
{
    if (d_arr) delete[] d_arr;
}

Vector::Vector(const Vector& rhs)
{
    d_capacity = rhs.capacity();
    d_arr = new int(d_capacity);
    
    for(int i=0; i<rhs.size(); ++i)
    {
        d_arr[i] = rhs[i];
        ++d_size;
    }
}

Vector& Vector::operator=(const Vector& rhs)
{
    if (d_capacity < rhs.capacity())
    {
        resize(rhs.capacity());
    }
    
    for (int i=0; i < rhs.size(); ++i)
    {
        d_arr[i] = rhs[i];   
    }
    
    d_size = rhs.size();
}

unsigned int Vector::capacity() const
{
    return d_capacity;
}

unsigned int Vector::size() const
{
    return d_size;
}

bool Vector::empty() const
{
    return d_size == 0;
}

void Vector::push_back(const int& data)
{
    while (d_size >= d_capacity)
    {
        resize(2*d_capacity);
    }
    d_arr[d_size] = data;
    ++d_size;
}

bool Vector::remove(const int& data)
{
    for (int i=0; i < d_size; ++i)
    {
        if (d_arr[i] == data)
        {
            while(i < (d_size - 1))
            {
                d_arr[i] = d_arr[i+1];
                ++i;
            }
            --d_size;
            return 1;
        }
    }
    
    return 0;
}

void Vector::clear()
{
    d_size = 0;
    d_capacity = DEFAULT_CAPACITY;
}

int& Vector::operator[](unsigned int pos)
{
    return d_arr[pos];
}

const int& Vector::operator[](unsigned int pos) const
{
    return d_arr[pos];
}

bool Vector::at(unsigned int pos, int& data) const
{
    if (pos < d_size && pos >= 0) 
    {
        data = d_arr[pos];
        return 1;
    }
    return 0;
}

void Vector::resize(unsigned int capacity)
{
    int* tmp = new int(capacity);
    
    for (int i = 0; i < d_size; ++i)
    {
        tmp[i] = d_arr[i];
    }
    delete[] d_arr;
    d_arr = tmp;
    d_capacity = capacity;
    
}


#endif









