#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	//variables for each word, suffix, and input
	//variable to hold index and initialize to zero
    string word1="", word2="", word3="";
    string suff1, suff2, suff3;
    string sentence;
    int index=0, sentLen, prevIndex;
    
    cout << "Enter your Eng++ sentence " << endl;
    getline(cin, sentence);
    sentLen = sentence.length();
    
    //find word1 index
    while (sentence[index]!='-')
    {
		if(sentence[index] == ' ')
		{
			cout << "Improper Eng++ sentence" << endl;
			cout << "Subjects must end in -ga" << endl;
			return 0;
		}
		index++;
	}
	for(int i = 0; i<index; i++)
	{
		word1+=sentence[i];
	}

	
	//find suffix1 index
	while (sentence[index]!=' ')
	{
		if(index == sentLen)
		{
			cout << "Improper Eng++ sentence" << endl;
			return 0;
		}
		index++;
	}
	
	for(int i=index-2; i<index; i++)
	{
		suff1+=sentence[i];
	}

	//----------------------------------------------------------------
	//remove spaces
	while(sentence[index] == ' ')
	{
		index++;
	}
	prevIndex = index;
	//find word2
	while(sentence[index]!='-' && sentence[index] != ' ')
	{
		index++;
	}
	for(int i=prevIndex; i<index; i++)
	{
		word2+=sentence[i];
	}
	
	//find suff2
	if (sentence[index] == '-')
	{
		//set prev index to index + 1 to skip '-'
		prevIndex = index+1;
	    while(sentence[index] != ' ')
	    {
		    index++;
	    }
	    for(int i=prevIndex; i<index; i++)
	    {
			suff2+=sentence[i];
		}
	}
	
	//----------------------------------------------------------------
	//remove spaces
	while(sentence[index] == ' ')
	{
		index++;
	}
	prevIndex = index;
	
	//find word3
	while(sentence[index] != '-' && index <= sentLen)
	{
		index++;
	}
	if(index==sentLen)
	{
		for(int i=prevIndex; i <= index; i++)
		{
			word3+=sentence[i];
		}
	}
	else 
	{
		for(int i=prevIndex; i < index; i++)
		{
			word3+=sentence[i];
		}
		//find suff3
		for(int i = index+1; i <= sentLen; i++)
		{
			suff3+=sentence[i];
		}
	}
	
	//Test if the first word is a noun with subject suffix
	if (word1 != "man" && word1 != "woman" && word1 != "fish")
	{
		cout << "This is not a proer Eng++ sentence" << endl;
		cout << "The first word must be a subject ending in -ga" << endl;
		return 0;
	}
	else if (suff1 != "ga")
	{
		cout << "This is not a proer Eng++ sentence" << endl;
		cout << "The subject of a sentence must end in -ga" << endl;
		return 0;
	}
	
	//If the second word is a noun, test for object suffix
	if (word2 == "man" || word2 == "woman" || word2 == "fish")
	{
		if (suff2 != "o")
		{
			cout << "This is not a proer Eng++ sentence" << endl;
			cout << "Objects must end in -o" << endl;
		    return 0;
		   }
	}
	if(word2 != "man" && word2 != "woman" && word2 != "fish" && word2 != "strong" && word2 != "short" && word2 != "red")
	{
		cout << "This is not a proer Eng++ sentence" << endl;
		cout << "The second word must be an object or adjective" << endl;
		return 0;
	}
	if (word3 != "is" && suff3 == "ka")
	{
		cout << "This is not a proer Eng++ sentence" << endl;
		cout << "Only questions can end in -ka" << endl;
		return 0;
	}
	
	cout << "This is a grammatically correct Eng++ sentence!" << endl;
	
	return 0;
	
		
}
    
    
