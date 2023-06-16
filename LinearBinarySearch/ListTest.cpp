/**

* Sunjun Ahn

* CIS 22C

* ListTest.cpp

*/


#include <iostream>
#include "List.h"
#include <cstddef>

using namespace std;


int main()
    {


    List<int> Lint;
    List<char> Lchar;
    List<double> Ldouble;
    List<string> Lstring;

    Lint.insert_first(1);
    cout << "Should print 1\n";
    Lint.print();

    Lint.insert_last(2);
    cout << "Should print 1 2\n";
    Lint.print();

    Lint.insert_last(3);
    cout << "Should print 1 2 3\n";
    Lint.print();

    Lint.insert_last(4);
    cout << "Should print 1 2 3 4\n";
    Lint.print();

    Lint.insert_last(5);
    cout << "Should print 1 2 3  4 5\n";
    Lint.print();
    Lint.insert_last(6);
    cout << "Should print 1 2 3  4 5\n";
    Lint.print();
    Lint.insert_last(7);
    cout << "Should print 1 2 3  4 5\n";
    Lint.print();
    Lint.insert_last(8);
    cout << "Should print 1 2 3  4 5\n";
    Lint.print();
    Lint.insert_last(9);
    cout << "Should print 1 2 3  4 5\n";
    Lint.print();
    Lint.insert_last(10);
    cout << "Should print 1 2 3  4 5\n";
    Lint.print();
    cout << endl << endl << endl;


    cout << "==============" << endl;
    cout << "linear_search(7) is at : ";
    cout << Lint.linear_search(7);
    cout << "th" << endl;
    cout << "===============" << endl;
    cout << Lint.linear_search(20);
    cout << "===============" << endl;

    Lint.printReverse();


    }




















    /**
    cout << "Should print 3 4 5 6 7:\n";
    Lint.print();
    Lint.insert_last(8);
    cout << "Should print 3 4 5 6 7 8:\n";
    Lint.print();
    Lint.insert_last(9);
    cout << "Should print 3 4 5 6 7 8 9:\n";
    Lint.print();
    Lint.insert_last(10);
    cout << "Should print 3 4 5 6 7 8 9 10:\n";
    Lint.print();
    Lint.insert_last(11);
    cout << "Should print 3 4 5 6 7 8 9 10 11:\n";
    Lint.print();
    Lint.insert_last(15);
    cout << "Should print 3 4 5 6 7 8 9 10 11 15:\n";
    Lint.print();
    Lint.insert_last(20);
    cout << "Should print 3 4 5 6 7 8 9 10 11 15 20:\n";
    Lint.print();
    **/

    /**
    Lint.begin();
    Lint.scroll(); // 1
    Lint.scroll(); // 2
    Lint.scroll(); // 3
    Lint.scroll(); // 4
    Lint.scroll(); // 5
    Lint.scroll(); // 6
    Lint.scroll(); // 7
    Lint.scroll(); // 8
    Lint.scroll(); // 9
    Lint.insert_current(13);

    cout << "My current is on : " << Lint.get_current() << endl;
    cout << "My index is located at : " << Lint.get_Index() << "th" << endl;
    cout << "My List Size is : " << Lint.get_size() << endl << endl;
    cout << "My List has : ";
    Lint.print();
    cout << " !! " << endl;
    Lint.scrollToIndex(1);
    cout << endl;
    Lint.scrollToIndex(2);
    cout << endl;
    Lint.scrollToIndex(3);
    cout << endl;
    Lint.scrollToIndex(4);
    cout << endl;
    Lint.scrollToIndex(5);
    cout << endl;


    cout << "=========================" << endl;
    Lint.printReverse();
    cout << endl;
    cout << "=========================" << endl;
 //   Lint.linear_search(1);
    cout << "=========================" << endl;
    **/








/******
    List<int> Lint;
    List<char> Lchar;
    List<double> Ldouble;
    List<string> Lstring;

    cout << "Should print 3 error messages below iterator off end in pop_front, pop_back, current: \n";
//will need to test these one-by-one as they should each call the exit() function.
//comment out each one after it has been tested
    // Lint.remove_first();
     // Lint.remove_last();
    Lint.delete_current();

    Lint.insert_first(5);
    cout << "Should print 5:\n";
    Lint.print();
    Lint.insert_last(6);
    cout << "Should print 5 6:\n";
    Lint.print();
    Lint.begin();
    Lint.insert_current(7);
    cout << "Should print 5 7 6:\n"; //note these should all print on a single line separated by spaces
    Lint.print();
    List<int> Lint2(Lint); //copy constructor
    cout << "Should print 5 7 6:\n";
    Lint2.print();

    cout << "Should print lists are equal: " << endl;
    if (Lint==Lint2)
        cout << "Lists are equal" << endl;
    else
        cout << "Lists are not equal" << endl;

    cout << "Size of list should be 0: "<< Lchar.get_size() << endl;
    Lchar.insert_first('a');
    Lchar.remove_first();
    cout << "Size of list should be 0: "<< Lchar.get_size() << endl;
    cout << "List should be empty. Nothing printed to screen: "<< endl;
    //Should print nothing and move to a new line.
    //Should NOT print an error message or any other message
    Lchar.print();

    cout << "Should print error message for scroll iterator is off the end of the list: \n";
    Ldouble.scroll();
    cout << "Should print error message that iterator off the end of list in insert: \n";
    Ldouble.insert_current(-8.9); //should not insert this value

    Ldouble.insert_last(8.8);
    Ldouble.insert_last(9.9);
    cout << "Should print 8.8 9.9:\n";
    Ldouble.print();

    cout << "Should print iterator is off the end of the List:\n";
    if(Ldouble.off_end())
    {
        cout <<"Iterator is off end\n";
    }
    else
    {
        cout << "Iterator is not off end\n";
    }
    Ldouble.begin();
    Ldouble.scroll();
    cout << "Should print 9.9:\n";
    cout << Ldouble.get_current() << endl;
    Ldouble.scroll();
    cout << "Should print error message when calling current iterator off end:\n";
    // cout << Ldouble.get_current() << endl;
    Ldouble.remove_last();
    cout << "Should print 8.8:\n";
    Ldouble.print();
}

***/

