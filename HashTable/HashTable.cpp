#include <string>
#include <iostream>
#include <cstdlib>
#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Table[i] = new Node;
        Table[i]->title = "";
        Table[i]->author = "";
        Table[i]->isbn = 0;
        Table[i]->next = NULL;
    }
}

HashTable::~HashTable()
{
    Nodeptr temp1;
    Nodeptr temp2;
    for(int i = 0; i < TABLE_SIZE; i++)
        {
            temp1 = Table[i];
            while(temp1 != NULL)
                {
                    temp2 = temp1->next;
                    delete temp1;
                    temp1 = temp2;
                }
                Table[i] = NULL;
        }
}

/*************      1       *****************/
/*************      1       *****************/
/*************      1       *****************/

int HashTable::hash(string key)
{
    int index, sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i];
    index = sum % TABLE_SIZE;
    return index;
}

void HashTable::addItem(string title, string author, int isbn)
{
    int index = hash(title);

    if(Table[index]->title == "")
    {
        Table[index]->title = title;
        Table[index]->author = author;
        Table[index]->isbn = isbn;
    }
    else
    {
        Nodeptr temp1 = Table[index];
        Nodeptr  temp2 = new Node;
        temp2 -> title = title;
        temp2 -> author = author;
        temp2 -> isbn = isbn;
        temp2 -> next = NULL;

        while(temp1 -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next = temp2;
    }
}

void HashTable::removeItem(string key)
{
    int index = hash(key);
    Nodeptr DelTemp;
    Nodeptr temp1;
    Nodeptr temp2;
    if(Table[index] -> title == "" && Table[index] -> author == "")
    {
            cout << key << " does not exist" << endl;
    }
    else if(Table[index] -> title == key && Table[index] -> next == NULL)
    {
        Table[index] -> title = "";
        Table[index] -> author = "";
        Table[index] -> isbn = 0;
    }
    else if(Table[index] -> author == key && Table[index] -> next == NULL)
    {
        Table[index] -> title = "";
        Table[index] -> author = "";
        Table[index] -> isbn = 0;
    }
    else if(Table[index] -> title == key)
    {
        DelTemp = Table[index];
        Table[index] = Table[index] -> next;
        delete DelTemp;
        cout << key << " was removed from the HashTable" << endl;
    }
    else if(Table[index] -> author == key)
    {
        DelTemp = Table[index];
        Table[index] = Table[index] -> next;
        delete DelTemp;
        cout << key << " was removed from the HashTable" << endl;
    }
    else
    {
        temp1 = Table[index] -> next;
        temp2 = Table[index];
        while(temp1 != NULL && temp1 -> title != key || temp1 -> author != key)
        {
            temp2 = temp1;
            temp1 = temp1 -> next;
        }
        if(temp1 == NULL && temp2 == NULL)
        {
            cout << key << " does not exist" << endl;
        }
        else
        {
            DelTemp = temp1;
            temp1 = temp1 -> next;
            temp2 -> next = temp1;

            delete DelTemp;
            cout << key << "was removed from the HashTable" << endl;
        }
    }
}

/*************      2       *****************/
/*************      2       *****************/
/*************      2       *****************/


int HashTable::findAuthor(string title)
{
    int index = hash(title);
    bool foundTitle = false;
    string author;
    int isbn;

    Nodeptr temp = Table[index];
    while (temp != NULL)
    {
        if(temp -> title == title)
        {
            foundTitle = true;
            author = temp -> author;
            isbn = temp -> isbn;
        }
        temp = temp -> next;
    }
    if(foundTitle == true)
    {
        cout << "The author: " << author << " is in index: ";
    }
    else
    {
        cout << "does not exist and the index number should be ";
    }
    return index;
}

int HashTable::numItemsAtIndex(int index)
{
    int count = 0;
    if (Table[index] -> title == "")
    {
        //cout << "numItemsAtIndex() is empty" << endl;
        return count;
    }
    else
    {
            count ++;
            Nodeptr temp = Table[index];
            while (temp -> next != NULL)
                {
                    count ++;
                    temp = temp -> next;
                }
    }
        return count;
}

/*************      3       *****************/
/*************      3       *****************/
/*************      3       *****************/

void HashTable::printBucket(int index)
{
    Nodeptr temp = Table[index];
    if(temp -> title == "")
    {
        cout << "The index: " << index << " is empty." << endl;
    }
    else
    {
        cout << "The index: " << index << " has the following item" << endl;
        while (temp != NULL)
        {
            cout << "-----------------\n";
            cout << temp -> title << endl;
            cout << temp -> author << endl;
            cout << temp -> isbn << endl;
            temp = temp -> next;
        }
        cout << "-----------------\n";
    }
}

void HashTable::printTable()
{
    int number;
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            number = numItemsAtIndex(i);
            cout << "========================\n";
            cout << "index = " << i << endl;
            cout << Table[i] -> title << endl;
            cout << Table[i] -> author << endl;
            cout << Table[i] -> isbn << endl;
            cout << "The number of item is: " << number << endl << endl;
        }
    }
}

/*************      4       *****************/
/*************      4       *****************/
