
/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on April 26, 2020, 8:00 AM
 * Purpose:  Hand Class Specification
 */

#ifndef HAND_H
#define HAND_H
#include"Deck.h"
class Hand:public Deck{
    protected:
        Deck *uHand; ///< Users Hand       
        Deck *dHand; ///< Dealers Hand
    public:
        //! Creates the Users and Dealers Hand
        void deal(Deck*,queue<int>);
        //! Returns the Users Hand
        Deck* getUhand(){return uHand;} 
        //! Returns The Dealers Hand
        Deck* getDhand(){return dHand;} 
};
#endif /* HAND_H */