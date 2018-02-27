#include <iostream>
#include<cmath>
using namespace std;

bool prime(int);

int main()
{
    int n=2, counter=0;
    
    while (counter<10000)
    {
         n++;
         if(prime(n))
         {
            counter++;
         }
    }
    
    cout << n << endl;
    
    return (0);
}

bool prime(int n)
{
    for (int i = 2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}