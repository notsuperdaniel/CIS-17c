/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on May 20, 2020, 12:36 PM
 * Purpose:  Tree Class Specification
 */

#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
using namespace std;
class Tree{
    public:
        //! Root Pointer
        Node* root; 
        //! Height Of Branch
        int height(Node *);
        //! Difference
        int diff(Node *); 
        //! Right Right
        Node *rr(Node *);
        //! Left Left
        Node *ll(Node *); 
        //! Left Right
        Node *lr(Node *); 
        //! Right Left
        Node *rl(Node *); 
        //! Balance
        Node *balance(Node *); 
        //! Insert
        Node *insert(Node *, int);
        //! Delete Root
        void delet();
        //! Print reverse Inorder
        void inorder(Node *); 
        //! Tree Constructor
        Tree(){root=NULL;}
};
#endif /* TREE_H */

