/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: danie
 *
 * Created on May 31, 2020, 12:14 PM
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>  //Input/Output Library
#include <set>
#include <iterator>

#include <cstring>
using namespace std;

//User Libraries
struct Node{
        int hash2=-1;
        string name;
        float bet;
        Node* next=NULL;
        
        float data;//ie bet
        Node* left;
        Node* right;
        //Note: he uses struct to the left but why?
        
        int count=0;
};


#endif /* NODE_H */

