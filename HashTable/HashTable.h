
#ifndef HASHTABLE_H_
#define HASHTABLE_H_
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class HashTable {

public:
    HashTable();

    ~HashTable();
    //Will write as part of Lab 6

    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //the ASCII values of each character % the table size

    void addItem(string title, string author, int isbn);
    //inserts a new item into the table
    // calls the hash function on the key title to determine the correct bucket

    void removeItem(string key);
    //Will write as part of Lab 6
    //removes the item with the given key

    int numItemsAtIndex(int index);
    //Helper function to printTable
    //Counts the number of items in each bucket

    void printTable();
    //prints the first item of each bucket
    //includes the number of items stored at that bucket

    void printBucket(int index);
    //Will write as part of Lab 6
    //Prints all items stored at a particular bucket

    int findAuthor(string title);
    //Searches for an author in the table using the key
    //returns the index under which the author is stored
    //returns -1 if the author is not found

private:

    struct Node
    {
        string title;
        string author;
        int isbn;
        Node* next;
        Node(): title(""), author(""), isbn(0), next(NULL){}
        Node(string ntitle, string nauthor, int nisbn): title(ntitle), author(nauthor), isbn(nisbn), next(NULL) {}
    };

    typedef struct Node* Nodeptr;

    static const int TABLE_SIZE = 10;
    Nodeptr Table[TABLE_SIZE];

};

#endif /* HASHTABLE_H_ */
