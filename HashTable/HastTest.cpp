#include "HashTable.h"
#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
    HashTable table;



    table.addItem("Aaaa Aaaa", "Zzzz Zzzz", 11111111);
    table.addItem("Bbbb Bbbb", "Yyyy Yyyy", 22222222);
    table.addItem("Cccc Ccccc", "Xxxx Xxxx", 33333333);
    table.addItem("Ddddd Dddddr", "Wwww Wwww", 44444444);
    table.addItem("Eeee Eeee", "Vvvv Vvvve", 55555555);
    table.addItem("Ffff Ffff", "Uuuu Uuuu", 66666666);

    table.addItem("Ggggg Ggggg", "Tttt Tttt", 77777777);
    table.addItem("Hhhh Hhhh", "Ssss Ssss", 88888888);
    table.addItem("Iiii Iiii", "Rrrr Rrrr", 99999999);
    table.addItem("Jjjj Jjjj", "Qqqq Qqqq", 99999999);
    table.addItem("Kkkk Kkkk", "Pppp Pppp", 88888888);
    table.addItem("Llll Llll", "Oooo Oooo", 77777777);

    table.addItem("Mmmm  Mmmm", "Nnnn Nnnn", 66666666);
    table.addItem("Nnnn Nnnn", "Mmmm Mmmm", 55555555);
    table.addItem("Oooo Oooo", "Llll Llll", 44444444);
    table.addItem("Pppp Pppp", "Kkkk Kkkk", 33333333);
    table.addItem("Qqqq Qqqq", "Jjjj Jjjj", 22222222);
    table.addItem("Rrrr Rrrr", "Iiii Iiii", 11111111);


    table.printTable();
    cout << "=====================================" << endl;

    cout << table.numItemsAtIndex(1) << endl;
    cout << table.numItemsAtIndex(2) << endl;
    cout << table.numItemsAtIndex(3) << endl;
    cout << table.numItemsAtIndex(4) << endl;
    cout << table.numItemsAtIndex(5) << endl;
    cout << table.numItemsAtIndex(6) << endl;
    cout << table.numItemsAtIndex(7) << endl;
    cout << "=====================================" << endl;

    table.printBucket(0);
    cout << endl;
    table.printBucket(1);
    cout << endl;
    table.printBucket(2);
    cout << endl;
    table.printBucket(3);
    cout << endl;
    table.printBucket(4);
    cout << endl;
    table.printBucket(5);
    cout << endl;
    table.printBucket(6);
    cout << endl;
    table.printBucket(7);
    cout << endl;
    table.printBucket(8);
    cout << endl;
    table.printBucket(9);
    cout << endl;


    cout << table.findAuthor("Aaaa 1") << endl;

    return 0;
}
