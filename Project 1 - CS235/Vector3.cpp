Vector::Vector(unsigned int capacity = DEFAULT_CAPACITY)
{
        array_capacity_ = capacity;
        array_ = new int(capacity);
}

Vector::Vector(const Vector& rhs)
{
        int temp_element
        array_capacity_ = rhs.capacity();
        for(int i; i<rhs.size(); i++)
        {
                rhs.at(i, temp_element);
                array_->push_back(rhs);
        }
}

~Vector()

unsigned int capacity() const

unsigned int size() const

bool empty() const

void push_back(const int& data)

bool remove(const int& data)

void clear()

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

int get_array_size() const

int& operator[](unsigned int pos) const

Vector& operator=(const Vector& rhs)
