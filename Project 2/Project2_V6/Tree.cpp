/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on May 20, 2020, 8:00 AM
 * Purpose:  Tree Class Implementation
 */
#include "Tree.h"
//==============================================================================
//Branch Height
//==============================================================================
int Tree::height(Node *temp){
    int h=0;
    if(temp!=NULL){
        int l_height=height(temp->left);
        int r_height=height(temp->right);
        int max_height=max(l_height,r_height);
        h=max_height+1;
    }
    return h;
}
//==============================================================================
//Difference
//==============================================================================
int Tree::diff(Node *temp){
     int l_height=height(temp->left);
     int r_height=height(temp->right);
     int b_factor=l_height-r_height;
     return b_factor;
}
//==============================================================================
//Right Right
//==============================================================================
Node *Tree::rr(Node* parent){
    Node *temp;
    temp=parent->right;
    parent->right=temp->left;
    temp->left=parent;
    return temp;
}
//==============================================================================
//Left Left
//==============================================================================
Node *Tree::ll(Node *parent){
    Node *temp;
    temp=parent->left;
    parent->left=temp->right;
    temp->right=parent;
    return temp;
}
//==============================================================================
//Left Right
//==============================================================================
Node *Tree::lr(Node *parent){
    Node *temp;
    temp=parent->left;
    parent->left=rr(temp);
    return ll(parent);
}
//==============================================================================
//Right Left
//==============================================================================
Node *Tree::rl(Node *parent){
    Node *temp;
    temp=parent->right;
    parent->right=ll(temp);
    return rr(parent);
}
//==============================================================================
//Prints Reverse Inorder
//==============================================================================
void Tree::inorder(Node* node){
    if(node==NULL)return;
    inorder(node->right); //Flipped to print out greatest to smallest
    cout<<"$"<<node->data<<endl;
    inorder(node->left);
}
//==============================================================================
//Insert Into Tree
//==============================================================================
Node *Tree::insert(Node *root,int value){
       if (root == NULL){
        root = new Node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else if (value < root->data){
        root->left = insert(root->left, value);
        root = balance (root);
    }else if (value >= root->data){
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}
//==============================================================================
//Balance Tree
//==============================================================================
Node *Tree::balance(Node *temp){
    int bal_factor=diff(temp);
    if(bal_factor>1){
        if(diff(temp->left)>0)
            temp=ll(temp);
        else
            temp=lr(temp);
    }else if(bal_factor<-1){
        if(diff(temp->right)>0)
            temp=rl(temp);
        else
            temp=rr(temp);
    }
    return temp;
}
//==============================================================================
//Delete Root
//==============================================================================
void Tree::delet(){
    delete root;
}