/**

* Sunjun Ahn

* CIS 22C

* List.h

*/


#ifndef JAN6-1_H_INCLUDED
#define JAN6-1_H_INCLUDED
#include <cstddef>
#include <cstdlib>
#include <iostream>

using namespace std;

template <class listitem> //note I used listitem for the class name here, not the commmon T
class List
{

    private:
        struct Node
        {
            listitem data;
            Node* nextnode;
            Node* previousnode;

            Node(): nextnode(NULL), previousnode(NULL){}
            Node(listitem newdata): nextnode(NULL), previousnode(NULL), data(newdata){}
        };

        typedef struct Node* Nodeptr;

    Nodeptr first;
    Nodeptr last;
    Nodeptr current; //the iterator
    int size;
    int index;


void reverse(Nodeptr node)
{
    if(node -> nextnode != NULL)
    {
        reverse(node -> nextnode);
    }
    cout << node -> data << " ";
}




//Helper function for the public printReverse() function.
//Recursively prints the data in a List in reverse.




public:

/**Constructors and Destructors*/

List();
//Default constructor; initializes and empty list
//Postcondition: List should be empty

~List();
//Destructor. Frees memory allocated to the list
//Postcondition: list should be empty and left we head and the tail which compiler takes care of

List(const List &list);
//Copy construcor. Initializes list to have the same elements as another list
//Postcondition:

/**Accessors*/

listitem get_last();
//Returns the last element in the list
//Precondition:


listitem get_current();
//Returns the element pointed to by the iterator
//Precondition:


bool is_empty();
//Determines whether a list is empty.

listitem get_first(); //this function now returns generic data
//Returns the first element in the list
//Precondition:

bool off_end();
//Determines if the iterator is off the end of the list


int get_size();
//Returns the length of the list

int get_Index();


/**Manipulation Procedures*/

void begin();
//Moves the iterator to point to the first element in the list
//If the list is empty, the iterator remains NULL
//Postcondition:


void insert_current(listitem data);
//Inserts a new element into the list in the position after the iterator
//Precondition: there has to be a data
//Postcondition: it has to point the one that next to the current

void remove_last();
//Removes the value of the last element in the list
//Precondition:
//Postcondition:

void remove_first();
//Removes the value of the first element in the list
//Precondition:
//Postcondition:

void insert_last(listitem data);
//Inserts a new element at the end of the list
//If the list is empty, the new element becomes both head and tail
//Postcondition:it has to point the Null

void insert_first(listitem data); //this function now takes in generic data
//Inserts a new element at the front of the list
//If the list is empty, the new element becomes both head and tail
//Postcondition: has to get the address from the head and point it


void delete_current();
//Removes the element after the element pointed at by the iterator
//Precondition:
//Postcondition:

void scroll();
//Moves the iterator forward by one element in the list
//Has no effect if the iterator is offend or the list is empty
//Postcondition:


/**Additional List Operations*/

void print();
//Prints to the console the value of each element in the list sequentially
//and separated by a blank space
//Prints nothing if the list is empty

bool operator == (const List& list);


void printReverse();

void scrollToIndex(int index);
//Wrapper function that calls the reverse helper function to print a list in reverse
//prints nothing if the List is empty

int linear_search(listitem item);

int binary_search(int low, int high, listitem item);


};

/***********
template <class listitem>
int List<listitem>::binary_search(int low, int high, listitem item)
{
    int mid;
    low = first -> data;
    high = last -> data;
    mid = (low + high) / 2;


    // get_current should point to the same data as item
    List<listitem>::get_current();

    if(low > high)
    {
        return (-1);
    }
    else if(get_current() == item) // if get
    {
        return get_Index();
    }
    else if(get_current() < mid)
    {
        return mid-1;
    }
    cout << get_Index();

}
*******************************/


template <class listitem>
int List<listitem>::linear_search(listitem item)
{
    if (List<listitem>::is_empty())
        {
            cout << "is_empty() : off end" << endl;
        }
        else if(item > List<listitem>::get_last())
            {
                cout << "Out side of the List";
            }
            else
                {
                    List<listitem>::begin();
            for (int i = 1; i < List<listitem>::get_size(); i++)
                {
                    List<listitem>::scroll();
                if (item == List<listitem>::get_current() )
                    {
                        return get_Index();
                }
                }
                return (1);
                }
}



template <class listitem>
void List<listitem>::printReverse()
{
    if(List<listitem>::is_empty())
    {
        cout << " ";
    }
    else
    {
    Nodeptr temp = new Node;
    temp = first;
    cout << "Print Reverse is : ";
    reverse(temp);
    temp = NULL;
    delete temp;
    }
}

template <class listitem>
int List<listitem>::get_Index()
{
    if (List<listitem>::off_end())
       {
        cout << "This is off end" << endl;
        return (-1);
       }
       else
       {
           Nodeptr temp = first -> nextnode;
           int count = 1;
           while (temp != current)
           {
               temp = temp -> nextnode;
               count ++;
           }
           return count+1;
       }
}



template <class listitem>
void List<listitem>::scrollToIndex(int index)
{
    if (List<listitem>::is_empty())
        {
            cout << "EMPTY" << endl;
        }
        else if (index > List<listitem>::get_size())
        {
            cout << "It's not on the list" << endl;
        }
        else
        {
            List<listitem>::begin();
            for (int i=1; i < index; i++)
                {
                    List<listitem>::scroll();
                }
                cout << "The number of order " << index << " is: " << List<listitem>::get_current();
        }
}


















template <class listitem>
List<listitem>::List() // constructor
{
    first = last = current = NULL; // initialize everything empty
    size = 0; // make list empty

}


template <class listitem>
List<listitem>::List(const List &list): size(list.size)
{
    if(list.first == NULL) //If the original list is empty, make an empty list for this list
    {
        first = last = current = NULL;
    }
    else
    {
        first = new Node(list.first->data); //using Node constructor
        Nodeptr temp = new Node; //Why must I create the temp Node here?
        temp = list.first;
        current = first; //set iterator to point to first so I can scroll through the list

        while(temp->nextnode != NULL)
        {

            current->nextnode = new Node;
            current = current->nextnode;
            temp = temp->nextnode;
            current->data = temp->data;

        }

        last = current; //Why do I need this line of code?

    }
}


template <class listitem>
// this function will delete everything step by step until it gets the last which is the NULL to make the list empty
List<listitem>::~List() // destructor
{
    current = first;
    Nodeptr temp;
    while(current != NULL)
    {
        temp = current->nextnode;

        delete current;

        current = temp;

    }
}


/*****************************************************/
/*********           1               ******************/
/*********           1               ******************/
/*****************************************************/

template <class listitem>
void List<listitem>::begin()
{
    current = first;
}


template <class listitem>
void List<listitem>::insert_first(listitem data)
{
    if (size==0)
    {
        Nodeptr newNode = new Node(data);
        first = last = newNode;
    }
    else
    {
        Nodeptr newNode = new Node(data);
        newNode->nextnode = first;
        first->previousnode = newNode;
        first = newNode;
    }
    size++;
}

template <class listitem>
void List<listitem>::insert_current(listitem data)
{
    if (List<listitem>::off_end())
       {
        cout << "This is off end, the current is 0" << endl;
       }

     else if (current == last)
     {
         List::insert_last(data);
     }

     else
     {
        Nodeptr newNode = new Node(data);
        newNode -> nextnode = current ->nextnode;
        newNode -> previousnode = current;
        current -> nextnode -> previousnode = newNode;
        current -> nextnode = newNode;



    size++;

     }
}


template <class listitem>
void List<listitem>::insert_last(listitem data)
{
    if (size == 0)
    {
        Nodeptr newNode = new Node(data);
        last = first = newNode;
    }
    else
    {
        Nodeptr newNode = new Node(data);
        newNode ->data =data;
        newNode ->previousnode = last;
        last->nextnode = newNode;
        last = newNode;
    }
    size ++;
}

/******************************************************************/
/**************         2               ***************************/
/**************         2               ***************************/
/******************************************************************/

template <class listitem>
int List<listitem>::get_size()
{
    return size;
}

template <class listitem>
listitem List<listitem>::get_first()
{
    if (List<listitem>::is_empty())
    {
        cout << "get_first(): List is empty. No first element" << endl;
        exit(-1); //What is wrong with this approach???

    }
    else
    {
        return first -> data;
    }
}

template <class listitem>
listitem List<listitem>::get_current()
{
    if(List<listitem>::off_end())
    {
        cout << "get_current(): List is empty. No current element" << endl;
        return (-1);

    }
    else
    {
        return current -> data;
    }
}

template <class listitem>
listitem List<listitem>::get_last()
{
    if (List<listitem>::is_empty())
    {
       cout << "get_last(): List is empty. No last element." << endl;
       exit(-1);
    }
    else
    {
        return last -> data;
    }
}


/**************************************************/
/**************        3                ***********/
/**************        3                ***********/
/**************************************************/

template <class listitem>
void List<listitem>::remove_first()
{
    if (size==0) //or make a call to the is_empty() function
    {
        cout << "remove_first: List is empty. Cannot remove first element." << endl;
    }
    else if (size==1)
    {
        delete first;
        first = last = current = NULL;

        size = 0;
    }
    else
    {
        Nodeptr temp = first; //store original first node in a temporary variable
        first = first->nextnode;
        delete temp;

        size--;
    }
}

template <class listitem>
void List<listitem>::remove_last()
{
    if (size==0) //or make a call to the is_empty() function
    {
        cout << "remove_last: List is empty. Cannot remove last element." << endl;
    }
    else if (size==1)
    {
        delete last;
        last = first = current = NULL;

        size = 0;
    }
    else
    {
        Nodeptr temp = last; //store original first node in a temporary variable
        last -> previousnode -> nextnode = NULL;
        delete temp;

        size--;
    }
}

template <class listitem>
void List<listitem>::delete_current()
{
    if (List<listitem>::off_end())
    {
        cout << "delete_current(): current is NULL" << endl;
       // exit(-1);
    }
    else if (current == first)
    {
        cout << "The current is pointing to the first node" << endl;
        List<listitem>::remove_first();
    }
    else if (current == last)
    {
        cout << "The current is pointing to the last node" << endl;
        List<listitem>::remove_last();
    }
     else
     {
        current -> previousnode -> nextnode;
        current -> nextnode;
        current -> nextnode -> previousnode;
        current -> previousnode;
        delete current;
        current = NULL;

        size--;
      }
}


/**************************************************/
/**************        4                ***********/
/**************        4                ***********/
/**************************************************/

template <class listitem>
bool List<listitem>::is_empty()
{
    return (size==0);
}

template <class listitem>
bool List<listitem>::off_end()
{
    if (current == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class listitem>
bool List<listitem>::operator==(const List& list)
{
    if(size != list.size)
        return false;
    current = first;
    Nodeptr temp = list.first;
    while(current != NULL)
    {
        if(current->data!=temp->data)
            return false;
        temp = temp->nextnode;
        current = current -> nextnode;
    }
    return true;
}

template <class listitem>
void List<listitem>::print()
{
    current = first;
    while (current != NULL)
    {
    cout << current->data << " ";
    current = current->nextnode;
    }
    cout << endl;
}

template <class listitem>
void List<listitem>::scroll()
{
    if (List<listitem>::off_end())
       {
        cout << "This is off end, the current is 0" << endl;
       }
     else
     {
        current = current -> nextnode;
     }

}



#endif // JAN6-1_H_INCLUDED



