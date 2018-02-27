#include <iostream>

using namespace std;

int main()
{
    string here;
    
    here = "hello";
    
    if (here == "hello" || here == "no" || here == "go")
    {
        cout << "hey";
        return 0;
    }
    
    cout << "whoa!";
    return 0;
}