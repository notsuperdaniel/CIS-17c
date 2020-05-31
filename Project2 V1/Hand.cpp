/* 
 * File:   main.cpp
 * Author: Daniel Garcia
* Created on April 26, 2020, 8:00 AM
 * Purpose:  Hand Class Implementation
 */
#include"Hand.h"
//==============================================================================
//Creates the Dealers and Users hand
//==============================================================================
void Hand::deal(Deck* c,queue<int> q){
    Deck* hand=new Deck[14];
    for (int i=0;i<14;i++){
        hand[i]=c[q.front()];
        q.pop();
    }
    Deck* h2=new Deck[14];
    for (int i=0;i<14;i++){
        h2[i]=c[q.front()];
        q.pop();
    }
    uHand=hand;
    dHand=h2;   
}