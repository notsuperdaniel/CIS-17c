/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on December 6th, 2019, 12:00 PM
 * Purpose:  Hand Class Specification
 */

#ifndef HAND_H
#define HAND_H
#include"Deck.h"
class Hand:public Deck{
    protected:
        Deck *uHand; ///< Users Hand       //AGGREGATION (14.7)
        Deck *dHand; ///< Dealers Hand
    public:
        //! Creates the Users and Dealers Hand
        void deal(Deck*,queue<int>);
        //! Returns the Users Hand
        Deck* getUhand(){return uHand;} //Return the users Hand
        //! Returns The Dealers Hand
        Deck* getDhand(){return dHand;} //Return the dealers Hand
};
#endif /* HAND_H */