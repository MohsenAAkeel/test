/*
    Author: Mohsen Abu-Akeel
    Instructor: Ilya Korsunsky
    Course: 136
    Assignment: :ab 11 Task 3
    
    This program will generate a list of countries with current populations using
    data taken from a csv file. It will allow the uder to update the list with a new
    country or change the population of an exisitng country.
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


