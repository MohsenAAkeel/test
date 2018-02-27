/*
    Author: Mohsen Abu-Akeel
    Instructor: Ilya Korsunsky
    Course: 136
    Assignment: :ab 11 Task 3
    
    This program will generate a list of countries with current populations using
    data taken from a csv file. It will allow the uder to update the list with a new
    country or change the population of an exisitng country. It will also allow
    the user to merge to countries and their populations.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Country
{
    string name;
    double population;    
};

struct Node
{
    Country ctry;
    Node * next;
};

Node * world;

void pushList (Country, Node *& );
void print (Node *);
void printCountry(Node *, string);
void update(Node *, Country);
void merge(string, string, Node *);
void removeCtry(Node *, Node *);

int main()
{
    ifstream data;
    string line, countryName, updateName, ctry1, ctry2;
    double pop, updatePop;
    Country bot; 
    
    data.open("data.csv");
    
    while (data)
    {
        for(int i = 0; i < 5; i++)
        {
            data >> pop;
        }
        getline(data, line);
        bot.name = line;
        bot.population = pop;
        pushList(bot, world);
    }
       
    getline(cin, countryName);
    cout << world -> ctry.name << endl;
    printCountry(world, countryName);

    cout << "Update name: ";
    getline(cin, updateName);
    cout << "Update pop: ";
    cin >> updatePop;
    
    bot.name = updateName;
    bot.population = updatePop;
    update(world, bot);
    
    cout << "Enter country 1:  " << endl;
    getline(cin, ctry1);
    
    cout << "Enter country 2:  " << endl;
    getline(cin, ctry2);
    
    merge(ctry1, ctry2, world);

    return (0);
}

//Precondition: world is an empty list or a populated list missing the new 'bot' struct.
//Postcondition: world will be populated with the 'bot' struct country at the end of the list.
void pushList(Country bot, Node * &world)
{
    Node * insert = new Node;
    insert->ctry = bot;
    insert->next = NULL;
    if (world == NULL)
    {
        world = insert;
    }
    else
    {
        Node* temp = world;
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }    
        temp -> next = insert;
    }
            
    return;
}

//precondition: N/A
//postcondition: the world list country names will be output on screen
void print(Node * world)
{
    for(Node * i=world; i!=NULL; i=i->next)
    {
        cout << i->ctry.name << endl;
    }
    return;
}

//precondition: N/A
//postcondition: world will be searched for a country, outputting the population
//  if it exists. Otherwise it states the country is not found.
void printCountry(Node * world, string countryName)
{
    Node * temp = world;
    while(temp -> next != NULL)
    {
        if(temp -> ctry.name == countryName)
        {  
            cout << temp->ctry.population << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Country not located." << endl;
    return;
}

//precondition: world list is original
//postcondition: world is updated with population value if the country exists
//  if the country does not exist, it is added to the end via pushList fxn.
void update(Node * world, Country bot)
{
    Node * temp = world;
    while(temp -> next != NULL)
    {
        if(temp -> ctry.name == bot.name)
        {  
            temp->ctry.population = bot.population;
            cout << temp->ctry.name << endl;
            cout << temp->ctry.population << endl;
            return;
        }
        temp = temp->next;
    }
    
    pushList(bot, world);
    
}


void merge(string ctry1, string ctry2, Node * world)
{
    Node* ctryA = world;
    
    while(ctryA->ctry.name != ctry1 && ctryA->next != NULL)
    {
        ctryA = ctryA->next;
    }
    if(ctryA->ctry.name!=ctry1)
    {
        cout << "The first country does not exist" << endl;
        return;
    }
    
    Node * ctryB = world;
    
    while(ctryB->ctry.name != ctry2 && ctryB->next != NULL)
    {
        ctryA = ctryB->next;
    }
    if(ctryB->ctry.name!=ctry2)
    {
        cout << "The second country does not exist" << endl;
        return;
    }
    
    ctryA->ctry.name = ctryA->ctry.name + " " + ctryB->ctry.name;
    ctryA->ctry.population = ctryA->ctry.population + ctryB->ctry.population;
    
    removeCtry(world, ctryB);
    
}

void removeCtry(Node * world, Node * ctry)
{
    Node * temp = world;
    
    while(temp->next != ctry && temp->next != NULL)
    {
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        cout << "The country you wanted to remove does not exist" << endl;
        return;
    }
    
    temp->next = temp->next->next;
    delete ctry;
}