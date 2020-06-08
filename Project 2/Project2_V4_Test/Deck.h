/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on April 26, 2020, 8:00 AM
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
    protected:              
        string name; ///< Name of the card
        string suit; ///< Suit of the card
        int value;   ///< Value of the card
       static const int numCrds=52;                     
        Deck *cards[numCrds]; 
        array<int,numCrds> ary; ///< Array used for Index
        queue<int> q; ///< Queue used for the deck of cards
        
        
    public:
        //! Deck Constructor
        Deck();
        //! Sets Value
        void setVal(int);
        //! Returns the Suit
        string getSui(){return suit;}   
        //! Returns The Name
        string getName(){return name;}
        //! Returns the Value
        int getVal(){return value;}
        //! Creates a card for each index
        Deck fillDeck(int);
        //! Fills vector with index
        queue<int> fillQue(int);
        //! Shuffles The Deck
        void shuffle();
        //! Returns the queue
        queue<int> getQue(){return q;}
        
};
#endif /* DECK_H */