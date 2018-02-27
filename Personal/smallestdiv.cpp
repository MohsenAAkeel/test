#include <iostream>
using namespace std;

bool finder (int);

int main()
{
    int num = 21;
    
    while(!(finder(num)))
    {
        num++;
    }
    
    cout << num << endl;
    
    return (0);
    
}

bool finder(int num)
{
    while(num)
    {
        for(int i=2; i<=20; i++)
        {
            if(num%i != 0)
            {
                return false;
            }
            if(i == 20 && num%20 == 0)
            {
                return true;
            }
        }
    }
}