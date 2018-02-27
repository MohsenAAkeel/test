#include <iostream>
#include <string>


using namespace std;

int main()
{
	string userSent, word1 = "", word2 = "", word3 = "", word4 = "";
	string word5 = "", suff1 = "", suff2 = "", suff3 = "";
	string subject, object, adj, verb, question, sentence;
	int index=0, sentLength;
	
	
//Request the Eng-- sentence from the user
	cout << "Enter an Eng-- sentence you would like to translate" << endl;
	getline(cin, userSent);
	sentLength = userSent.length();
	
//Word 1
	while(userSent[index] != ' ' && index <= sentLength)
	{
		if (index == sentLength)
		{
			cout << "This is not a proper Eng-- sentence" << endl;
			return 0;
		}
		else
		{
			word1 += userSent[index];
			index++;
		}
	}
	
//Cycle through the spaces between word 1 and word 2
	while(userSent[index] == ' ')
	{
		index++;
	}
	
	if (index == sentLength)
	{
		cout << "Not a proper Eng-- sentence" << endl;
		return 0;
	}

//Word 2	
	//set the prevIndex to the index of the first letter 
	//and collect the index for the second word
	while(userSent[index] != ' ')
	{
		if (index == sentLength)
		{
			cout << "This is not a proper Eng-- sentence" << endl;
			return 0;
		}
		else
		{			
		    word2 += userSent[index];
		    index++;
		}
	}
	
//Cycle through the spaces between word 2 and word 3
	while(userSent[index] == ' ')
	{
		index++;
	}
	
	if (index == sentLength)
	{
		cout << "Not a proper Eng-- sentence" << endl;
		return 0;
	}		
	
//Word 3
	while(userSent[index] != ' ' && index < sentLength)
	{
		word3 += userSent[index];
		index++;
	}

//Words greater than 3	
	if (index < sentLength)
	{
		while(userSent[index] == ' ')
		{
			index++;
		}
		//Assigning the 4th word to word4
		while(userSent[index] != ' ' && index < sentLength)
		{
			word4 += userSent[index];
			index++;
		}
		//Checking if there is a 5th word and assigning it to word5
		if (index < sentLength)
		{
			while(userSent[index] == ' ')
			{
				index++;
			}
		
			while(userSent[index] != ' ' && index <sentLength)
			{
				word5 += userSent[index];
				index++;
			}
		}
	}
	
//If there are more than 5 words, not an eng-- sentence
	if(word5 != "" && index < sentLength)
	{
		cout << "This is not a proper Eng-- sentence." << endl;
		return 0;
	}
	
//======================================================================
//======================================================================
//======================================================================	
// TESTING WORD COLLECTION
//======================================================================
//======================================================================
//======================================================================
	cout << endl << "These are the words collected" << endl;
	cout << "Spaces after the colons and period at end of word are added." << endl;
	if (word1 != "")
	{
		cout << "First word: " <<word1<<"."<< endl;
	}
	if (word2 != "")
	{
		cout << "Second word: " <<word2<<"."<< endl;
	}
	if (word3 != "")
	{
		cout << "Third word: " <<word3<<"."<< endl;
	}
	if (word4 != "")
	{
		cout << "Fourth word: " <<word4<<"."<< endl;
	}
	if (word5 != "")
	{
		cout << "Fifth word: " <<word5<<"."<< endl;
	}
	cout << endl;


//======================================================================
//======================================================================
//======================================================================	
//                Assigning the word#'s grammatically
//======================================================================
//======================================================================
//======================================================================


//Questions can have the following forms
//		is woman red
//		is the man a fish
//		is the woman strong

	
	if (word1 == "is")
	{
		question = "is-ka";
		
		//If the second word is a subject, assign it and continue
		//assigning the 3rd or 4th word as the object and kick out
		//an error if not
		if (word2 == string("man") || word2 == string("woman") || word2 == string("fish"))
		{
			subject = word2 + "-ga";
			
			if (word3 == "man" || word3 == "woman" || word3 == "fish")
			{
				object = word3 + "-o";
				sentence = subject + ' ' + object + ' ' + question;
				cout << sentence << endl;
			}
			if (word3 == "red" || word3 == "short" || word3 == "strong")
			{
				adj = word3;
				sentence = subject + ' ' + adj + ' ' + question;
				cout << sentence << endl;
			}
			else
			{
				cout << "This is not a proper Eng-- sentence." << endl;
				cout << "2 The sentence lacks a proper object." << endl;
			}
		}
		//If the second word is an article, shift to the third word and test
		//as above
		else if ((word2 == "a" || word2 == "the")&&(word3 == "man" || word3 == "woman" || word3 == "fish"))
		{
			subject = word3 + "-ga";
			if (word4 == "red" || word4 == "strong" || word4 == "short")
			{
				adj = word4;
				sentence = subject + ' ' + adj + ' ' + question;
				cout << sentence << endl;
			}
			//In case there is a 'is the man a fish' test!
			else if ((word4 == "a" || word4 == "the")&&(word5 == "man" || word5 == "woman" || word5 == "fish"))
			{
				adj = word5;
				sentence = subject + ' ' + object + ' ' + question;
				cout << sentence << endl;
			}
			else
			{
				cout << "This was not a proper Eng-- sentence." << endl;
				cout << "The sentence lacks a proper adjective" << endl;
			}
		}
		else
		{
		    cout << "This was not a proper Eng-- sentence" << endl;
		    cout << "The sentence lacks a proper subject" << endl;
		    return 0;
		}
	}
//IF the sentence does not begin with 'is', it must begin with subject
//or article.
	else if (word1 == "woman" || word1 == "man" || word1 == "fish")
	{
		subject = word1 + "-ga";
		
		if (word2 == "kissed" || word2 == "caught" || word2 == "is")
		{
			verb = word2;
		}
		else
		{
			cout << "This was not a proper eng-- sentence." << endl;
			cout << "The sentence lacks a proper verb." << endl;
			return 0;
		}
		
		if (word3 == "man" || word3 == "woman" || word3 == "fish")
		{
			object = word3 + "-o";
			sentence = subject + ' ' + object + ' ' + verb;;
			cout << sentence << endl;			
		}
		else if ((word3 == "a" || word3 == "the")&&(word4 == "man" || word4 == "woman" || word4 == "fish"))
		{
			object = word4 + "-o";
			sentence = subject + ' ' + object + ' ' + verb;
			cout << sentence << endl;
		}
		else if (word3 == "red" || word3 == "short" || word3 == "strong")
		{
			adj = word3;
			sentence = subject + ' ' + adj + ' ' + verb;
			cout << sentence << endl;
		}
		else
		{
			cout << "This was not a proper eng-- sentence." << endl;
			cout << "1 The sentence lacks a proper object." << endl;
			return 0;
		}
	}
	else if ((word1 == "a" || word1 == "the") && (word2 == "man" || word2 == "woman" || word2 == "fish"))
	{
		subject = word2 + "-ga";
		
		if (word3 == "caught" || word3 == "kissed" || word3 == "is")
		{
			verb = word3;
			
		}
		else
		{
			cout << "This was not a proper eng-- sentence." << endl;
			cout << "The sentence lacks a proper verb." << endl;
			return 0;
		}
		
		if (word4 == "man" || word4 == "woman" || word4 == "fish")
		{
		    object = word4 + "-o";
		    sentence = subject + ' ' + object + ' ' + verb;
			cout << sentence << endl;    
		}
		else if ((word4 == "a" || word4 == "the") && (word5 == "man" || word5 == "woman" || word5 == "fish"))
		{
			object = word5 + "-o";
		    sentence = subject + ' ' + object + ' ' + verb;
			cout << sentence << endl;
		}
		else if (word4 == "red" || word4 == "short" || word4 == "strong")
		{
			adj = word4;
			sentence = subject + ' ' + adj + ' ' + verb;
			cout << sentence << endl;
		}
		else
		{
			cout << "This was not a proper eng-- sentence." << endl;
			cout << "The sentence lacks a proper object." << endl;
			return 0;
		} 
	}
	else
	{
		cout << "This was not a proper eng-- sentence." << endl;
		cout << "The sentence lacks a proper subject." << endl;
		return 0;
	}
	


	return 0;
}	
	
	
	

