#include <iostream>
using namespace std;

bool palindrome (int);

int main()
{
    int max=0;
    
    for (int i = 100; i<1000; i++)
    {
        for (int k = i; k<1000; k++)
        {
            if(palindrome(i*k))
            {
                if (max < i*k)
                {
                    max = i*k;
                    cout << i << ", " << k << endl;
                }
            }
        }
    }
    cout << max << endl;
    cout << "done\n";
    return (0);
}

bool palindrome(int num)
{
    int pal=0, store;
    
    if(num%10 == 0)
    {
        return false;
    }
    store = num;

    while(num)
    {
        pal = num%10+pal;
        if (num/10 > 0)
        {
            pal = pal *10;
        }
        num = num / 10;
    }
    
    if (pal == store)
    {
        return true;
    }
    else
    {
        return false;
    }
}