#include <iostream>
#include <vector>
using namespace std;

void wordCollect(string, vector<string> &);
void eliminateArticles(vector<string> &, vector<string> &);
void statement(vector<string> &, vector<string> &, vector<string>, vector<string>, vector<string>);
void question(vector<string> &, vector<string> &, vector<string>, vector<string>, vector<string>);

int main()
{
    vector<string> words, translation;
    string userSent;
	int index = 0, sentLength;
	
	//Assign the allowed words to arrays before assigning them to vectors
	string noun[] = {"man", "woman", "fish"};
	string article[] = {"the", "a"};
	string verb[] = {"kissed", "is", "caught"};
	string adjective[] = {"strong", "red", "short"};
	
	vector<string> nouns(noun, noun+3);
	vector<string> articles(article, article+2);
	vector<string> verbs(verb, verb+3);
	vector<string> adjectives(adjective, adjective+3);
	
	cout << "Enter an Eng-- sentence you would like to translate" << endl;
	getline(cin, userSent);
	sentLength = userSent.length();
	
	//split the sentence into words and eliminate all "the"s and "a"s
	wordCollect(userSent, words);
	eliminateArticles(words, articles);

	//Sentences that start with is are questions.
	if (words[0] == "is")
	{
	    question(words, translation, nouns, adjectives, verbs);
	}
	else 
	{
	    statement(words, translation, nouns, adjectives, verbs);
	}

    return (0);	
}

//Cycles through the user sentence and sends the word back to main
//Precondition: usersentence is not parsed.
//Postcondition: user sentence is parsed for words and stored in vector
void wordCollect(string userSent, vector<string> &words)
{
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
}

//Cycle through the sentence vector and remove articles
//Precondition: sentence contains articles a and/or the
//Postcondition: sentence is cleared of articles.
void eliminateArticles(vector<string> &words, vector<string> &articles)
{
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
}

//Generate the translation if the sentence starts with is.
//Precondition: the sentence is an Eng-- sentence starting with 'is'
//Postcondition: the translation vector contains the Eng++ translation
void question(vector<string> &words, vector<string> &translation, vector<string> nouns, vector<string> adjectives, vector<string> verbs)
{
    bool subject=false, verb=false, adjective=false;
    translation.push_back("is-ka");
    for(int i = 0; i < nouns.size(); i++)
    {
        if (words[1] == nouns[i])
        {
            translation.push_back(words[1]+"-ga");
            subject = true;
        }
    }
    
    if (subject == false)
    {
        cout << "This was not a proper Eng-- sentence.\n";
        cout << "You are missing a subject.\n";
        return;
    }
    
    for(int i=0; i<adjectives.size(); i++)
    {
        if (words[2] == adjectives[i])
        {
            translation.push_back(words[2]);
            adjective = true;
        }
    }
    
    for(int i=0; i<verbs.size(); i++)
    {
        if (words[2] == verbs[i])
        {
            translation.push_back(words[2]);
            verb = true;
        }
    }
    
    if(adjective == false && verb==false)
    {
        cout << "This was not a proper Eng-- sentence.\n";
        cout << "You are missing an adjective or verb.\n";
        return;
    }
    
    cout << "The translation is: \n";
    for(int i=0; i<translation.size(); i++)
    {
        cout << translation[i] << ' ';
    }
    cout<<endl;
}

//Generate the translation if the sentence is a statement.
//Precondition: the sentence is an Eng-- sentence starting with a subject
//Postcondition: the translation vector contains the Eng++ translation
void statement(vector<string> &words, vector<string> &translation, vector<string> nouns, vector<string> adjectives, vector<string> verbs)
{
    bool subject=false, verb=false, adjective=false, object=false;
    
    for(int i = 0; i < nouns.size(); i++)
    {
        if (words[0] == nouns[i])
        {
            translation.push_back(words[0]+"-ga");
            subject = true;
        }
    }
    
    if (subject == false)
    {
        cout << "This was not a proper Eng-- sentence.\n";
        cout << "You are missing a subject.\n";
        return;
    }
    
    for(int i=0; i<verbs.size(); i++)
    {
        if (words[1] == verbs[i])
        {
            translation.push_back(words[1]);
            verb = true;
        }
    }
    
    if (verb == false)
    {
        cout << "This was not a proper Eng-- sentence.\n";
        cout << "You are missing a verb.\n";
        return;
    }
    
    for(int i=0; i<adjectives.size(); i++)
    {
        if (words[2] == adjectives[i])
        {
            translation.push_back(words[2]);
            adjective = true;
        }
    }
    
    for(int i=0; i<nouns.size(); i++)
    {
        if (words[2] == nouns[i])
        {
            translation.push_back(words[2]+"-o");
            object = true;
        }
    }
    
    if(adjective == false && object==false)
    {
        cout << "This was not a proper Eng-- sentence.\n";
        cout << "You are missing an adjective or an object.\n";
        return;
    }
    
    cout << endl << "The translation is: \n";
    for(int i=0; i<translation.size(); i++)
    {
        cout << translation[i] << ' ';
    }
    cout<<endl;
}