/*****************************
Sunjun Ahn
CIS 22C
Lab6
Jennifer Parrish
*******************************/


#include <iostream>
#include "BST.h"


using namespace std;

int main()
{

    BST<int> tree;

    cout << "in_order_print : ";
    tree.inOrderPrint();
    cout << endl;

    cout << "pre_order_print : ";
    tree.preOrderPrint();
    cout << endl;

    cout << "post_order_print : ";
    tree.postOrderPrint();
    cout << endl << endl;

    cout << "================" << endl;
    cout << "isEmpty() : should say 1 : " << tree.isEmpty() << endl;
    cout << "===============" << endl;
    cout << "tree.getSize() is : " << tree.getSize() << endl << endl;


    tree.add(40);


    cout << "should say : 'addValue() : same data exists already' " << endl;
    tree.add(40);

    tree.add(25);
    tree.add(32);
    tree.add(10);
    tree.add(78);

    cout << "================" << endl;
    cout << "isEmpty() : should say 0 : " << tree.isEmpty() << endl;
    cout << "===============" << endl;


    cout << "in_order_print : ";
    tree.inOrderPrint();
    cout << endl;

    cout << "pre_order_print : ";
    tree.preOrderPrint();
    cout << endl;

    cout << "post_order_print : ";
    tree.postOrderPrint();
    cout << endl;

    cout << "tree.getRoot() is : " << tree.getRoot() << endl;
    cout << "tree.getSize() is : " << tree.getSize() << endl;

    return 0;
}


/******* Result ***************

in_order_print : in_order_print(): Tree is empty. No element.

pre_order_print : pre_order_print(): Tree is empty. No element.

post_order_print : post_order_print(): Tree is empty. No element.


================
isEmpty() : should say 1 : 1
===============
tree.getSize() is : 0

should say : 'addValue() : same data exists already'
addValue() : same data exists already
================
isEmpty() : should say 0 : 0
===============
in_order_print : 10 25 32 40 78
pre_order_print : 40 25 10 32 78
post_order_print : 10 32 25 78 40
tree.getRoot() is : 40
tree.getSize() is : 5

Process returned 0 (0x0)   execution time : 0.000 s
Press any key to continue.

********************************************************************/
