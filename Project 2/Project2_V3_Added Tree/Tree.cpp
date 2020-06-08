/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Tree.h"

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
int Tree::diff(Node *temp){
     int l_height=height(temp->left);
     int r_height=height(temp->right);
     int b_factor=l_height-r_height;
     return b_factor;
}
Node *Tree::rr(Node* parent){
    Node *temp;
    temp=parent->right;
    parent->right=temp->left;
    temp->left=parent;
    return temp;
}
Node *Tree::ll(Node *parent){
    Node *temp;
    temp=parent->left;
    parent->left=temp->right;
    temp->right=parent;
    return temp;
}
Node *Tree::lr(Node *parent){
    Node *temp;
    temp=parent->left;
    parent->left=rr(temp);
    return ll(parent);
}
Node *Tree::rl(Node *parent){
    Node *temp;
    temp=parent->right;
    parent->right=ll(temp);
    return rr(parent);
}

void Tree::inorder(Node* node){
    if(node==NULL)return;
    inorder(node->right);
    cout<<node->data<<endl;
    inorder(node->left);
}
void Tree::preorder(Node* node){
    if(node==NULL)return;
    cout<<node->data<<" ";
    inorder(node->left);
    preorder(node->left);
    preorder(node->right);
}
void Tree::level(Node* root){
    int h=height(root);
    for(int i=1;i<=h;i++) level(root,i);
}
void Tree::level(Node* root, int lev){
    if(root==NULL)return;
    if(lev==1) cout<<root->data<<" ";
    else if(lev>1){
        level(root->left,lev-1);
        level(root->right,lev-1);
    }
}
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
void Tree::display(Node* ptr, int level){
     int i;
    if (ptr!=NULL){
        display(ptr->right, level + 1);
        cout<<endl;
        if (ptr == root)
        cout<<"R -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"     ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}
void Tree::delet(){
    delete root;
}
