/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on April 26, 2020, 8:00 AM
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
        Deck *cards;    ///< The Whole Deck
        int count,sum,dSum,games,offSet;
        string result, name;
        char choice; ///< Choice for if the User wants to play again
        float bet;  ///< Users Bet
        bool dble;  ///< If they double Down
        fstream dataFile, totGame, binFile, record, data, file;;
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
        void operator ++();                
        //! Overload int++ Operator
        void operator ++(int);             
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
        //! Return result of the game
        string getRes(){return result;}
        //! Return bet of the game
        float getBet(){return bet;}
        int getCount(){return count;}
        //! Write Name and Bet to file
        void monHist(string, float, string);
};
 
#endif /* PLAYER_H */