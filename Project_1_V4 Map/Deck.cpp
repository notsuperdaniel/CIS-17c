
/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on December 6th, 2019, 12:00 PM
 * Purpose:  Deck Class Implementation
 */
#include"Deck.h"
//==============================================================================
//Set Value
//==============================================================================
void Deck::setVal(int i){
    value=i;
}
//==============================================================================
//Shuffle the Array
//==============================================================================
void Deck::shuffle(){
    for (int i=0;i<7;i++)
    random_shuffle ( ary.begin(), ary.end());     //STL(16.5)
}
//==============================================================================
//Fill The Queue with 0-51 To Use As Index
//==============================================================================
queue<int> Deck::fillQue( int n){
    for (int i=0;i<n;i++){
        ary[i]=i;
    }
    shuffle();
    shuffle();
    for (int i=0;i<n;i++){
        q.push(ary[i]);
    }
   return q;
}
//==============================================================================
//Deck Constructor
//==============================================================================
Deck::Deck(){
    name="";
    suit="";
    value=0;
}
//==============================================================================
//Create The Cards
//==============================================================================
Deck Deck::fillDeck(int i){
    Deck tempDeck;
        if (i<13) tempDeck.suit= "Spades";
        if (i>=13 && i<26) tempDeck.suit= "Hearts";
        if (i>=26 && i<39) tempDeck.suit= "Diamonds";
        if (i>=39 && i<52) tempDeck.suit= "Diamonds";
   
   
        if ((i+1)%13==1)tempDeck.name= "Ace";
        else if ((i+1)%13==2)tempDeck.name= "Two";
        else if ((i+1)%13==3)tempDeck.name= "Three";
        else if ((i+1)%13==4)tempDeck.name= "Four";
        else if ((i+1)%13==5)tempDeck.name= "Five";
        else if ((i+1)%13==6)tempDeck.name= "Six";
        else if ((i+1)%13==7)tempDeck.name= "Seven";
        else if ((i+1)%13==8)tempDeck.name= "Eight";
        else if ((i+1)%13==9)tempDeck.name= "Nine";
        else  if ((i+1)%13==10)tempDeck.name= "Ten";
        else if ((i+1)%13==11)tempDeck.name= "Jack";
        else  if ((i+1)%13==12)tempDeck.name= "Queen";
        else if ((i+1)%13==0)tempDeck.name= "King";
   
          if ((i+1)%13==1)tempDeck.value= 1;
        else if ((i+1)%13==2)tempDeck.value= 2;
        else if ((i+1)%13==3)tempDeck.value= 3;
        else if ((i+1)%13==4)tempDeck.value= 4;
        else if ((i+1)%13==5)tempDeck.value= 5;
        else if ((i+1)%13==6)tempDeck.value= 6;
        else if ((i+1)%13==7)tempDeck.value= 7;
        else if ((i+1)%13==8)tempDeck.value= 8;
        else if ((i+1)%13==9)tempDeck.value= 9;
        else  if ((i+1)%13==10)tempDeck.value= 10;
        else if ((i+1)%13==11)tempDeck.value= 10;
        else  if ((i+1)%13==12)tempDeck.value= 10;
        else if ((i+1)%13==0)tempDeck.value= 10;
       
        return tempDeck;
      }