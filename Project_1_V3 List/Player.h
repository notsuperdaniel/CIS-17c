/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on December 6th, 2019, 12:00 PM
 * Purpose:  Player Class Specification
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>
class Player:public Hand{
    protected:
        Deck *users;    ///< Users Hand
        Deck *dealers;  ///< Dealers Hand
        Deck *binCards;
        Deck *cards;    ///< The Whole Deck
        int count,sum,dSum,games,offSet;
        string result, name;
        char choice;
        float bet;  ///< Users Bet
        bool dble;  ///< If they double Down
        
        fstream dataFile, totGame, binFile, record;
        ifstream in;
        ofstream out;
        
        
    public:
        //! Player Constructor
         Player(Deck *,Deck *,int);
         //! Player Constructor
         Player(Deck *,Deck *,int,string);
         //! Player Constructor
         Player(Player &);
         //! Overload ++ Operator
         void operator ++();                //OPERATOR OVERLOADING (14.5)
         //! Overload int++ Operator
         void operator ++(int);             //OPERATOR OVERLOADING (14.5)

        //! Set Users Hand
        void setUsers(Deck *);
        //! Set Dealers Hand
        void setDealers(Deck *);
        //! Return Users Sum of Cards
        int getUsum(){return sum;}
        //! Return Dealers sum of cards
        int getDsum(){return dSum;}
        //! Get Users Choice
        char getChoice(){return choice;}
        //! Return Users Hand
        Deck *usersH(){return users;}
        //! Return Dealers Hand
        Deck *dealersH(){return dealers;}
        //! Start Playing
        void play();
        //! Decide Value if User Has an Ace
        void isAce();
        //! Display Users and Dealers Cards in Play
        void display();
        //! Math to decide if the Dealer Hits
        void dCards();
        //! Display the result
        void winLoss();
        //! Write Game History in text file: i.e. wins and losses
         void inFile(int &);
         void wrtRcrd();
        //! To Double Down
        void dblDown();
        string getRes(){return result;}
        float getBet(){return bet;}
        int getCount(){return count;}
        
};
 
#endif /* PLAYER_H */