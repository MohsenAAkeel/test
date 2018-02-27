#include <iostream>

class SortedIntList
{
    private:
        std::list<int>;
    public:
        void insert(const int& n);
        void print(std::ostream& out) const;
    
};

void SortedIntList::insert(const int& n)
{
    vector<int>::iterator start;
    start = list.begin();
    vector<int>::iterator end;
    end = list.end();
    
    while(start != end)
    {
        if (*start < n)
        {
            list.insert(start, n);
            break;
        }
        ++start;
    }
    
}

void SortedIntList::print(std::ostream& out) const
{
    
}