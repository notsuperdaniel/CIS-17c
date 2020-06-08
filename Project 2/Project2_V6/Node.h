/* 
 * File:   main.cpp
 * Author: Daniel Garcia
* Created on May 20, 2020, 8:00 AM
 * Purpose:  Node Struct
 */

#ifndef NODE_H
#define NODE_H
#include <iostream>  //Input/Output Library
#include <set>
#include <iterator>
#include <cstring>
using namespace std;
struct Node{
        int hash2=-1; ///< Initialize The Hash Number to -1
        string name; ///< Name in Node
        float bet; ///< Bet in Node
        Node* next=NULL; ///< Next Node Pointer
        float data; ///< Bet
        Node* left; ///< Left Child Node For Tree
        Node* right; ///< Right Child Node For Tree
        int count=0; 
};
#endif /* NODE_H */

