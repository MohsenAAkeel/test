/*
    Author: Mohsen Abu-Akeel
    Instructor: Shankar
    Class: 135
    Assignment: Project 3
    
    This program will read a file containing Eng-- sentences and output
    a file that contains the Eng++ translations.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

//variable for dictionary size.
const int VOCAB_SIZE = 11;

//non-member function prototypes
void populateDict();
string findPos(string);
void eliminateArticles();
void translate();

//########################################################################

class Vitem
{
    public:
        Vitem(string, string);
        Vitem(string);
        Vitem();
        string getWord();
        string getPos();
    private:
        string word;
        string pos;
};

//---member function definitions---
Vitem::Vitem(string iword, string ipos)
{
    word = iword;
    pos = ipos;
}

Vitem::Vitem(string iword)
{
    word = iword;
    pos =  findPos(iword);
}

Vitem::Vitem()
{ }

string Vitem::getWord()
{
    return word;
}

string Vitem::getPos()
{
    return pos;
}
    
//############################################################################    
    
class Sentence
{
    public:
        Sentence(string line);
        string getSentence();
        string getVectorWord(int index);
        string getVectorPos(int index);
        void setVector(string iword, string ipos);
        void removeItem(int index);
        int getWordVecLength();
    private:
        string sent;
        vector<Vitem> vItems;    
 
};

Sentence::Sentence(string line)
{
    sent = line;
    int length = line.length(), j = 0;
    string newWord = "";
    for(int i=0;i<length;i++)
    {
        while(line[j]!=' ' && j < length)
        {
            newWord += line[j];
            j++;
        }
        j++;
        vItems.push_back(Vitem(newWord));
        newWord = "";
        i=j;
    }
}

string Sentence::getSentence()
{
    return sent;
}

string Sentence::getVectorWord(int index)
{
    return vItems[index].getWord();
}

string Sentence::getVectorPos(int index)
{
    return vItems[index].getPos();
}

int Sentence::getWordVecLength()
{
    return vItems.size();
}

void Sentence::setVector(string iword, string ipos)
{
    vItems.push_back(Vitem(iword, ipos));
}

void Sentence::removeItem(int sindex)
{
    for(int i=sindex; i<vItems.size()-1; i++)
    {
        vItems[i] = vItems[i+1];
    }
    vItems.pop_back();
}

//############################################################################

class Corpus
{
    public:
        friend istream& getline(istream& input, Corpus &fileCorpus)
        {
            string line;
            getline(input, line);
            fileCorpus.inputData(line);
        }
        string getSentence(int index);
        string getSentVecWord(int tindex, int sindex);
        string getSentVecPos(int tindex, int sindex);
        int getSentVecLength(int index);
        void removeArticles(int tindex, int sindex);
        void inputData(string line);
        void setTextVector(string iword, string ipos, int tindex);
        int getLength();
    private:
        vector<Sentence> text;
};

void Corpus::inputData(string line)
{   
    text.push_back(Sentence(line));
}

//Member function calls for the sentence of the current index
string Corpus::getSentence(int index)
{
    return text[index].Sentence::getSentence();
}

//calls the element of the sentence vector within the text vector
string Corpus::getSentVecWord(int tindex, int sindex)
{
    return text[tindex].Sentence::getVectorWord(sindex);
}

//Will retrieve the pos for a word at a given text index and Sentence index
string Corpus::getSentVecPos(int tindex, int sindex)
{
    return text[tindex].Sentence::getVectorPos(sindex);
}

//Removes articles from a given text element and calls Sentence to perfrom removal
void Corpus::removeArticles(int tindex, int sindex)
{
    text[tindex].Sentence::removeItem(sindex);
}

//This function will fill a text vector
void Corpus::setTextVector(string iword, string ipos, int tindex)
{
    text.vector::resize(tindex+1, Sentence("man"));
    text[tindex].Sentence::setVector(iword, ipos);
}

//calls the length of the corpus vector
int Corpus::getLength()
{
    return text.size();
}

int Corpus::getSentVecLength(int index)
{
    return text[index].Sentence::getWordVecLength();
}

//############################################################################

//global array
Vitem EngVocab[VOCAB_SIZE];
Corpus fileCorpus, transCorpus;

//---MAIN---##################################################################

int main()
{
    ifstream engFile;
    ofstream engppFile;
    populateDict();
    
    //Open the Eng-- File and copy to Corpus object
    //Open the file and write it to the Eng-- Corpus, fileCorpus
    engFile.open("Eng--sents.txt");
    int index = 0;
    while(engFile)
    {
       getline(engFile, fileCorpus);
    }
    engFile.close();
    /*
    for(int i=0; i < fileCorpus.getLength(); i++)
    {
        for(int j=0; j < fileCorpus.getSentVecLength(i); j++)
        {   
            cout << fileCorpus.getSentVecPos(i,j) << " ";
        }
        cout << endl;
    }*/
    
    translate();
    
    //Write the translation to file.
    engppFile.open("Eng++sents.txt");
    for(int i=0; i<transCorpus.getLength(); i++)
    {
        for(int j=0; j<transCorpus.getSentVecLength(i); j++)
        {
            engppFile << transCorpus.getSentVecWord(i,j) << " ";
        }
        engppFile << endl;
    }
    
    engppFile.close();
    return(0);
}

//---Non-Member Functions---##################################################

//precondition: empty array of type Vitem.
//postcondition: Vitem array containing Eng-- words and their part of speech
void populateDict()
{
    EngVocab[0] = Vitem("man", "noun");
    
    EngVocab[1] = Vitem("woman", "noun");
    
    EngVocab[2] = Vitem("fish", "noun");
    
    EngVocab[3] = Vitem("strong", "adjective");
    
    EngVocab[4] = Vitem("short", "adjective");
    
    EngVocab[5] = Vitem("red", "adjective");
    
    EngVocab[6] = Vitem("is", "verb");
    
    EngVocab[7] = Vitem("caught", "verb");
    
    EngVocab[8] = Vitem("kissed", "verb");
    
    EngVocab[9] = Vitem("a", "article");
    
    EngVocab[10] = Vitem("the", "article");
}

//precondition: Vitem element is missing a pos.
//postcondition: Vitem word element is associated with a pos after searching
//               EngVocab object
string findPos(string iword)
{
    for(int i =0; i<VOCAB_SIZE; i++)
    {
        if(iword == EngVocab[i].getWord())
        {
            return EngVocab[i].getPos();
        }
    }
    exit(1);
}

//precondition: Corpus of sentence element vectors that contain articles
//postcondition: Viems that are articles are removed from Sentence vItems vectors.
void eliminateArticles()
{
    for(int i=0; i<fileCorpus.getLength(); i++)
    {
        for (int j=0; j<fileCorpus.getSentVecLength(i); j++)
        {
            if(fileCorpus.getSentVecPos(i,j) == "article")
            {
                fileCorpus.removeArticles(i,j);
            }
        }
    }
}

void translate()
{
    //vectors will hold adjectives.
    string newSubject, newObject, posHold, verb, wordHold;
    vector<string> object_adjectives, subject_adjectives;
    
    for(int i=0; i < fileCorpus.getLength(); i++)
    {
        //these variables will monitor if a sentence has hit one of these pos
        //The vector adjectives are assigned to subject or object vectors and the modification for Eng++ 
        //depend on these. 
        int object_hit = 0, subject_hit = 0, question = 0; 
        subject_adjectives.resize(0);
        object_adjectives.resize(0);
        newSubject = "", newObject="", verb="", posHold = "", wordHold = "";
        
        for(int j=0; j < fileCorpus.getSentVecLength(i); j++)
        {
            if(j = 0 && fileCorpus.getSentVecWord(i,j) == "is")
            {
                question = 1;
            }
            else if(subject_hit == 0 && fileCorpus.getSentVecPos(i,j) == "noun")
            {
                subject_hit = 1;
                newSubject = fileCorpus.getSentVecWord(i,j);
                newSubject += "-ga";
            }
            else if(subject_hit == 1 && fileCorpus.getSentVecPos(i,j) == "noun")
            {
                object_hit = 1;
                newObject = fileCorpus.getSentVecWord(i,j);
                newObject+="-o";
            }
            else if(subject_hit == 0 && fileCorpus.getSentVecPos(i,j) == "adjective")
            {
                wordHold = fileCorpus.getSentVecWord(i,j);
                subject_adjectives.push_back(wordHold);
            }
            else if(subject_hit == 1 && fileCorpus.getSentVecPos(i,j) == "adjective")
            {
                wordHold = fileCorpus.getSentVecWord(i,j);
                object_adjectives.push_back(wordHold);
            }
            else if(fileCorpus.getSentVecPos(i,j) == "verb")
            {
                verb = fileCorpus.getSentVecWord(i,j);
            }
        }
        
        //Fills the second Corpus with the translated Eng-- sentences
        string sword;
        if(question == 0)
        {
            for(int k=0; k<subject_adjectives.size(); k++)
            {
                sword = subject_adjectives[k];
                transCorpus.setTextVector(sword, "adjective", i);
            }
            transCorpus.setTextVector(newSubject, "noun", i);
            for(int k=0; k<object_adjectives.size(); k++)
            {
                sword = object_adjectives[k];
                transCorpus.setTextVector(sword, "adjective", i);
            }
            transCorpus.setTextVector(newObject, "noun", i);
            transCorpus.setTextVector(verb, "verb", i);
        }
        else
        {
            for(int k=0; k<subject_adjectives.size(); k++)
            {
                sword = subject_adjectives[k];
                transCorpus.setTextVector(sword, "adjective", i);
            }
            transCorpus.setTextVector(newSubject, "noun", i);
            for(int k=0; k<object_adjectives.size(); k++)
            {
                sword = object_adjectives[k];
                transCorpus.setTextVector(sword, "adjective", i);
            }
            transCorpus.setTextVector("is-ka", "verb", i);
        }
    
    }
}
