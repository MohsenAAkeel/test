#include <iostream>
using namespace std;

int square (int);

int main()
{
    int numsq=0, sqnum=0, sum=0;
    
    for (int i=1; i<=100; i++)
    {
        numsq = numsq+square(i);
        sum=sum+i;
    }
    sqnum = square(sum);
    
    cout << sqnum-numsq << endl;
}

int square(int num)
{
    return num*num;
}