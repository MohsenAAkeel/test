#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>


using namespace std;

bool isValidDNAchar(char);
bool isValidDNAstring(string);
string transcribe(string);
double gcContent(string);
char complementChar(char nuc);
string complementStr(string);

char nucleotide[4] = {'A', 'T', 'G', 'C'};

int main()
{
    string strand = "AGTCTACTG";
    string transcribed;
    double content;
    
    isValidDNAstring(strand);
    transcribed = transcribe(strand);
    content = gcContent(strand);
    
    cout << strand << endl;
    cout << transcribed << endl;
    cout << content << endl;
    cout << complementStr(strand) << endl;
    
    return (0);
    
}


bool isValidDNAstring(string strand)
{
    for (int i=0; i<strand.length(); i++)
    {
        if(!(isValidDNAchar(strand[i])))
        {
            cout << "nope" << endl;
            return false;
        }
    }
    return true;
}

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

string transcribe(string strand)
{
    string transcribed = "";
    for(int i=0; i < strand.length(); i++)
    {
        if(strand[i] == 'T')
        {
            transcribed+='U';
        }
        else
        {
            transcribed += strand[i];
        }
    }
    return transcribed;
}

double gcContent(string strand)
{
    double gcCounter = 0;
    double counter = 0;
    
    for(int i =0; i < strand.length(); i++)
    {
        if(strand[i] == 'G' || strand[i] == 'C')
        {
            gcCounter++;
        }
        counter++;
    }
    
    return (gcCounter/counter);
}

char complementChar(char nuc)
{
    if(nuc == 'A')
    {
        return 'T';
    }
    else if(nuc== 'T')
    {
        return 'A';
    }
    else if(nuc == 'G')
    {
        return 'C';
    }
    else if(nuc == 'C')
    {
        return 'G';
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