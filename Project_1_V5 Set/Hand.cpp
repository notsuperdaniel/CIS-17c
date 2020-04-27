/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on December 6th, 2019, 12:00 PM
 * Purpose:  Hand Class Implementation
 */
#include"Hand.h"
//==============================================================================
//Creates the Dealers and Users hand
//==============================================================================
void Hand::deal(Deck* c,queue<int> q){
    Deck* hand=new Deck[7];
    for (int i=0;i<7;i++){
        hand[i]=c[q.front()];
        q.pop();
    }
    Deck* h2=new Deck[7];
    for (int i=0;i<7;i++){
        h2[i]=c[q.front()];
        q.pop();
    }
    uHand=hand;
    dHand=h2;   
}