/*****************************
Sunjun Ahn
CIS 22C
Lab6
Jennifer Parrish
*******************************/


#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <string>
#include <cstdlib>


using namespace std;

template <class bstdata>
class BST
{
    private:
        struct Node
        {
                bstdata data;
                Node* left;
                Node* right;

                Node(): left(NULL), right(NULL){}
                Node(bstdata newdata): left(NULL), right(NULL), data(newdata){}
        };

        typedef struct Node* Nodeptr;



        Nodeptr root;
        int size;

                    /**Private helper functions*/

        void addValue(Nodeptr root, bstdata value);
        bstdata findMin(Nodeptr root);

        // bool containsValue(Nodeptr root, bstdata value);

        void printPreOrder(Nodeptr root);
        void printPostOrder(Nodeptr root);
        void printInOrder(Nodeptr root);

        void deleteTree(Nodeptr root);


/************** Public Func Def Start **********************/

    public:
        BST();
        ~BST();
        bool isEmpty();
        int getSize();
        bstdata getRoot();


        void add(bstdata value);
      //  bstdata minimum();


        void inOrderPrint();
        void preOrderPrint();
        void postOrderPrint();
    //    bool contains(bstdata value);

};


#endif // BST_H_INCLUDED



template <class bstdata>
void BST<bstdata>::addValue(Nodeptr root, bstdata value)
{
    if(root -> data == value)
    {
        cout << "addValue() : same data exists already" << endl;
        return ;
    }
    else if(root -> data > value)
    {
        if(root -> left == NULL)
        {
            root -> left = new Node(value);
            size ++;
        }
        else
        {
            addValue(root -> left, value);
        }
    }
    else
    {
        if(root -> right == NULL)
        {
            root -> right = new Node(value);
            size ++;
        }
        else
        {
            addValue(root -> right, value);
        }
    }

}


template <class bstdata>
void BST<bstdata>::printInOrder(Nodeptr root)
{
    if(root != NULL)
    {
        printInOrder(root -> left);
        cout << root -> data << " ";
        printInOrder(root -> right);
    }
}

template <class bstdata>
void BST<bstdata>::printPreOrder(Nodeptr root)
{
    if(root != NULL)
    {
        cout << root -> data << " ";
        printPreOrder(root -> left);
        printPreOrder(root -> right);
    }
}

template <class bstdata>
void BST<bstdata>::printPostOrder(Nodeptr root)
{
    if(root != NULL)
    {
        printPostOrder(root -> left);
        printPostOrder(root -> right);
        cout << root -> data <<" ";
    }
}

template<class bstdata>
void BST<bstdata>::deleteTree(Nodeptr root)
{
    if (root != NULL)
    {
        deleteTree(root -> left);
        deleteTree(root -> right);
        delete root;
    }

}




/************************** 1 *****************/

template <class bstdata>
BST<bstdata>::BST()
{
    root = NULL;
    size = 0;
}

template <class bstdata>
BST<bstdata>::~BST()
{
    deleteTree(root);
}


template <class bstdata>
bool BST<bstdata>::isEmpty()
{
    if(size == 0)
        return true;
    else
        return false;
}


template <class bstdata>
int BST<bstdata>::getSize()
{
    return size;
}

template <class bstdata>
bstdata BST<bstdata>::getRoot()
{
    if(root -> data == NULL)
    {
        cout << "getRoot(): is empty" << endl;
        exit (-1);
    }
    else
        return root -> data;
}

/********************** 2 **********************/



template <class bstdata>
void BST<bstdata>::add(bstdata value)
{
    if (root == NULL)
    {
        root = new Node(value); //if the tree is empty insert the value at the root
        size++;
    }
    else
        addValue(root, value); //otherwise call the helper function, passing it the root
}



/**
template <class bstdata>
int BST<bstdata>::minimum()
{

    if (root == NULL)
    {
        cout << "Minimum: Tree is empty" << endl;
        //will need to include cstdlib for exit below

        exit(-1); //you can also use assert here if desired
    }
    else
    {

        return findMin(root);

    }

}
**/

/**
template <class bstdata>
bool BST<bstdata>::contains(bstdata value)
{

    if (value == root->data)

            return true;

    else

        return containsValue(root, value);
}

**/





template <class bstdata>
void BST<bstdata>::inOrderPrint()
{
    if (root == NULL)
    {
       cout << "in_order_print(): Tree is empty. No element." << endl;
    }

    else
    {
        printInOrder(root);
    }
}

template <class bstdata>
void BST<bstdata>::preOrderPrint()
{
    if (root == NULL)
    {
       cout << "pre_order_print(): Tree is empty. No element." << endl;
    }
    else
    {
        printPreOrder(root);
    }
}

template <class bstdata>
void BST<bstdata>::postOrderPrint()
{
    if (root == NULL)
    {
       cout << "post_order_print(): Tree is empty. No element." << endl;
    }
    else
    {
        printPostOrder(root);
    }
}
