#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>


using namespace std;

typedef vector<int> His;

const int MAX_DNA_SIZE = 700;

struct DNA
{
    vector<string> header;
    string strand;
    double gcRatio;
}DNAstructs[MAX_DNA_SIZE];

char nucleotide[4] = {'a', 't', 'g', 'c'};

void arrayFill();
bool isValidDNAchar(char);
bool isValidDNAstring(string);
double gcContent(string);
void histGen();
void arraySort();
void gcText();
string transcribe(string);
void codons(string, vector<string> &);
int numCodon(string, vector<string> &);
char complementChar(char);
string complementStr(string);
void expandedDNA();


//MAIN=============================================================================================================

int main()
{
    
    arrayFill();
    histGen();
    arraySort();
    gcText();
    expandedDNA();
    
    return (0);
}


//FUNCTIONS==================================================================================================

void arrayFill()
{
    //variable 'hit' will monitor when a DNA strand is being read and when a new header file has been read from
    //file. This will allow arrayCount to increment by 1 for the next DNA datum read from file.
    ifstream data;
    ofstream badDNA;
    int arrayCount=0, hit=0;
    string line, header;
    
    data.open("DNA.txt");
    badDNA.open("badDNA.txt");
    
    while(data)
    {
        line="";
        getline(data, line);
        
        //If the current line is a header and hit = 1, reset hit to begin a new array element.
        if(line[0] == '>' && hit == 1)
        {
            arrayCount++;
            hit = 0;
        }
        
        //The first character of header lines begins with '>'. Add to vector if true for current line.
        if(line[0] == '>')
        {
            DNAstructs[arrayCount].header.push_back(line);
        }
        
        else
        {
            //Initialize the strand of the array to an epty string so it can be filled, but only when the 
            //first line of DNA is being entered (hit = 0)
            if(hit == 0)
            {
                DNAstructs[arrayCount].strand = "";
            }
            
            //The first line of DNA has been read or another line of DNA has been read and hit is set to 1.
            hit = 1;
            
            //If the DNA string is valid, add it to the strand variable. If it is invalid, write it to file
            if(isValidDNAstring(line))
            {
                DNAstructs[arrayCount].strand += line;
            }
            else
            {
                for(int i = 0; i<DNAstructs[arrayCount].header.size(); i++)
                {
                    badDNA << DNAstructs[arrayCount].header[i] << endl;
                }
                badDNA << line << endl;
            }
        }
        
        //Collect the GC content of each strand from file.
        for(int i=0; i<MAX_DNA_SIZE; i++)
        {
            string tempStrand = DNAstructs[i].strand;
            DNAstructs[i].gcRatio = gcContent(tempStrand);
        }
        
    }
    
    badDNA.close();
    data.close();
}

//Returns true if each nucleotide in a string is valid
bool isValidDNAstring(string strand)
{
    for (int i=0; i<strand.length(); i++)
    {
        if(!(isValidDNAchar(strand[i])))
        {
            return false;
        }
    }
    return true;
}

//Returns true if the nucleotide is valid. False otherwise
bool isValidDNAchar(char tide)
{
    for(int i=0; i<4; i++)
    {
        if(nucleotide[i] == tide)
        {
            return true;
        }
    }
    
    return false;
}

//Calculates the percentage of nucleotides that are G or C.
double gcContent(string strand)
{
    double gcCounter = 0;
    double counter = 0;
    
    for(int i =0; i < strand.length(); i++)
    {
        if(strand[i] == 'g' || strand[i] == 'c')
        {
            gcCounter++;
        }
        counter++;
    }
    
    return (gcCounter/counter);
}

//Precondition
void histGen()
{
    His table;
    table.reserve(3);
    int count;
    
    for(int i = 0; i<MAX_DNA_SIZE; i++)
    {
        count = (DNAstructs[i].header).size();
        if (count > table.size())
        {
            table.resize((DNAstructs[i].header).size()+1);
        }
        table[count]++;
    }
    
    ofstream headFreq;
    headFreq.open("headerLinesFreq.txt");
    
    for (int i=1; i<table.size(); i++)
    {
        headFreq << i << "  " << table[i] << endl;
    }
    
    return;
}


void arraySort()
{
    for(int i = 0; i<MAX_DNA_SIZE; i++)
    {
        int min = i;
        for(int j = i+1; j<MAX_DNA_SIZE; j++)
        {
            if (DNAstructs[j].gcRatio < DNAstructs[min].gcRatio)
            {
                min = j;
            }
        }
        DNA temp = DNAstructs[i];
        DNAstructs[i] = DNAstructs[min];
        DNAstructs[min] = temp;
            
    }
}

void gcText()
{
    ofstream ordered;
    
    ordered.open("GCcontent.txt");
    
    for(int i=0; i<MAX_DNA_SIZE; i++)
    {
        int headsize = (DNAstructs[i].header).size();
        for(int j=0; j<headsize; j++)
        {
            ordered << DNAstructs[i].header[j] << endl;
        }
        ordered << ">GC Content: " << DNAstructs[i].gcRatio << endl;
        ordered << DNAstructs[i].strand << endl << endl;
    }
    
    ordered.close();
}


string transcribe(string strand)
{
    string transcribed = "";
    for(int i=0; i < strand.length(); i++)
    {
        if(strand[i] == 't')
        {
            transcribed+='u';
        }
        else
        {
            transcribed += strand[i];
        }
    }
    return transcribed;
}

//Generates a vector of codons.
void codons(string strand, vector<string> &codonVec)
{
    int counter = 0;
    if(strand.length()%3 == 0)
    {
        for(int i=0; i<strand.length(); i++)
        {
            if(counter == 3)
            {
                string codon = "";
                for(int k = i-3; k<i; k++)
                {
                    codon += strand[k];
                }
                codonVec.push_back(codon);
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
    }
    else
    {
        for(int i=0; i<strand.length()-(strand.length()%3); i++)
        {
            if(counter == 3)
            {
                string codon = "";
                for(int k = i-3; k<i; k++)
                {
                    codon += strand[k];
                }
                codonVec.push_back(codon);
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
        string codon="";
        for(int i=strand.length()-(strand.length()%3); i<strand.length(); i++)
        {
            codon+=strand[i];
        }
        codonVec.push_back(codon);
    }
    
    return;
}

int numCodon(string codon, vector<string> &codonVec)
{
    int counter = 0;
    for(int i = 0; i<codonVec.size(); i++)
    {
        if(codon == codonVec[i])
        {
            counter++;
        }
    }
    
    return counter;
}

char complementChar(char nuc)
{
    if(nuc == 'a')
    {
        return 't';
    }
    else if(nuc== 't')
    {
        return 'a';
    }
    else if(nuc == 'g')
    {
        return 'c';
    }
    else if(nuc == 'c')
    {
        return 'g';
    }
    else
    {
        return 'F';
    }
}

string complementStr(string strand)
{
    string complement="";
    for(int i = 0; i<strand.length(); i++)
    {
        if(complementChar(strand[i])!='F')
        {
            complement+=complementChar(strand[i]);
        }
        else
        {
            cout << "An improper nucleotide was found in your strand" << endl;
            exit(1);
        }
    }
    return complement;
}

void expandedDNA()
{
    ofstream ordered;
    vector<string> codonList;
    string RNAstrand, complementStrand;
    
    ordered.open("expandedDNA.txt");
    for(int i=0; i<MAX_DNA_SIZE; i++)
    {
        int headsize = (DNAstructs[i].header).size();
        for(int j=0; j<headsize; j++)
        {
            ordered << DNAstructs[i].header[j] << endl;
        }
        ordered << ">GC Content: " << DNAstructs[i].gcRatio << endl;
        ordered << DNAstructs[i].strand << endl;
        ordered << "> RNA:" << endl;
        RNAstrand = transcribe(DNAstructs[i].strand);
        ordered << RNAstrand << endl;
        codons(RNAstrand, codonList);
        ordered << "> Number of UGG (tryptophan): " << numCodon("ugg", codonList)  << endl;
        ordered << "> DNA complement: " << endl;
        ordered << complementStr(DNAstructs[i].strand) << endl << endl;
    
        //clear the codon vector for the next struct.
        codonList.resize(0);
    }
    
    ordered.close();
}
