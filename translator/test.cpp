#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<string> words;
    string userSent; 
    string article[] = {"the", "a"};
    vector<string> articles(article, article+2);
    
    cout << "Enter an Eng-- sentence you would like to translate" << endl;
	getline(cin, userSent);
 
    int sentLength = userSent.length();
    int index = 0, prevIndex = 0;
    
    while(index <= sentLength)
    {
        index++;
        if(userSent[index] == ' ' || index == sentLength) 
        {
            string word = ""; 
            for(int i=prevIndex; i<index; i++)
            {
                word+=userSent[i];
            }
            while(userSent[index] == ' ')
            {
                index++;
            }
            prevIndex = index; //set previndex to index for next pass
            words.push_back(word);
        }
    }
 for(int i =0; i<words.size(); i++)
	{
	    cout << words[i] << endl;
	}
    for (int i=0; i<articles.size(); i++)
    {
        for (int k=0; k<words.size(); k++)
        {
            if(articles[i] == words[k])
            {
                for(int j=k; j<words.size()-1; j++)
                {
                    words[j]=words[j+1];
                }
                words.pop_back();
            }
        }
    }

    cout << words.size() << endl;
    for(int i =0; i<words.size(); i++)
	{
	    cout << words[i] << endl;
	}
	
	cout << articles.size() << endl;
	
	for(int i =0; i<articles.size(); i++)
	{
	    cout << articles[i] << endl;
	}
	return(0);
	
}