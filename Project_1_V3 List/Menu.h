/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on December 6th, 2019, 12:00 PM
 * Purpose:  Menu Class Specification
 */

#ifndef MENU_H
#define MENU_H
#include"Player.h"
#include <list>
#include <iterator>
#include <fstream>
class Menu{
    private:                //PRIVATE DATA MEMBERS (13.4)
        char choose; ///< Users choice
        float bet;   ///< Users Bet Amount
        ifstream in; 
        ofstream out;
        
        fstream data;
        list <float> lst;
        
    public:
        //! Displays the start menu
        void menu();
        //! Add Money to Stash
        void add();
        //! Check Money in Stash
        void check();
        //! Bet Money
        void betMon();
        //! Return the Users Bet
        float getBet(){return bet;}
        //! Return The Users Choice
        char getChse(){return choose;}
        //! Warn of Low Money in Stash
        void warn();
        //! Displays the Total Amount Won or Loss from past times played
        void monWon();
        //! Displays the Rules of BlackJack
        void rules();
        //! To throw an exception outside of the class & into main
        class lowMon{}; 
        //! Overloaded Operator
        friend ostream &operator << (ostream &, const Menu &); //FRIEND (14.2)
        
        void createList();
};


#endif /* MENU_H */