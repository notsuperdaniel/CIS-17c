/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on December 6th, 2019, 12:00 PM
 * Purpose:  Deck Class Specification
 */

#ifndef DECK_H
#define DECK_H
#include <algorithm>
#include <string>
#include <vector>
#include <array>
                #include <bits/stdc++.h> 
                #include <iostream>
                #include <queue>
using namespace std;
class Deck 
{
    protected:              //PROTECTED MEMBERS (15.1)
        string name; ///< Name of the card
        string suit; ///< Suit of the card
        int value;   ///< Value of the card
       static const int numCrds=52;                     //STATIC (14.1)
        Deck *cards[numCrds]; 
        array<int,numCrds> ary; ///< Array used for Index
        queue<int> q;
        
        
    public:
        //! Deck Constructor
        Deck();
        //! Sets Value
        void setVal(int);
        //! Returns the Suit
        string getSui(){return suit;}   //Inline Function (13.6)
        //! Returns The Name
        string getName(){return name;}
        //! Returns the Value
        int getVal(){return value;}
        //! Returns the vector
        //array<int,52> getAry(){return ary;}
        //! Creates a card for each index
        Deck fillDeck(int);
        //! Fills vector with index
        queue<int> fillQue(int);
        //! Shuffles The Deck
        void shuffle();
        queue<int> getQue(){return q;}
        
};
#endif /* DECK_H */

