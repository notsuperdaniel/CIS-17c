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
        int hshSz;
        string nam;
        string *dat;
        float* bets;
        float betC;
        
         Node *last;
    public:
        void setDat(string* str,int s,float* b){dat=str;size=s;bets=b;}
        void create(int);
        ~HashTable();
        void ELFHash(string);
        void insert();
        void srch(string);
        void end();
};