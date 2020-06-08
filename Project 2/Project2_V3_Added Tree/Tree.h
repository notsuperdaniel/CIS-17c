/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: danie
 *
 * Created on June 5, 2020, 3:25 PM
 */

#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
using namespace std;
class Tree{
    public:
        Node* root;
        int height(Node *);
        int diff(Node *);
        Node *rr(Node *);
        Node *ll(Node *);
        Node *lr(Node *);
        Node *rl(Node *);
        Node *balance(Node *);
        Node *insert(Node *, int);
        void delet();
        void display(Node *,int);
        void inorder(Node *);
        void preorder(Node *);
        void postorder(Node *);
        void level(Node *);
        void level(Node*,int);
        Tree(){root=NULL;}
};

#endif /* TREE_H */

