/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on May 20, 2020, 12:36 PM
 * Purpose:  Hash Table Class Specification
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
        unsigned int hash; ///< Hash Number
        Node *ary; ///< Pointer To Hold The Data
        int size; ///< Number of Hashes
        int hshSz; ///< Size Of Hash Array
        string nam; ///< Name 
        string *dat; ///< Pointer to Hold The Names
        float* bets; ///< Pointer to Hold The Bets
        float betC; ///< Bet This Time Around
         Node *last; ///< Pointer to point to the end 
    public:
        //! Set The Data 
        void setDat(string* str,int s,float* b){dat=str;size=s;bets=b;}
        //! Create The Has Array
        void create(int);
        //! HashTable Destructor
        ~HashTable();
        //! Create The Hash From The Name
        void ELFHash(string);
        //! Insert Data Into Hash Table
        void insert();
        //! Hash Search
        void srch(string);
        //! Finds The End
        void end();
};