/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on January 2, 2019, 12:36 PM
 * Purpose:  Creation of Template to be used for all
 *           future projects
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <set>
#include <iterator>

#include <cstring>
using namespace std;

//User Libraries
#include "Node.h"
class HashTable{
    private:
        unsigned int hash;
        Node *ary;
        int size;
        string nam;
        string *dat;
        float* bets;
    public:
        void setDat(string* str,int s){dat=str;size=s;}
        void create(int);
        ~HashTable();
        void ELFHash(string);
        void insert();
};