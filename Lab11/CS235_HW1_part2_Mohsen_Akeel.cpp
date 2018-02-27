#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream file("inputdata.txt");
    ofstream newfile("outputdata.txt");
    string str;
    vector<string> corpus;
    
    while (getline(file, str))
    {
        corpus.push_back(str);
    }
    for (int i = corpus.size(); i > 0; i--)
    {
        newfile << corpus[i];
    }
}