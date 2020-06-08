/* 
 * File:   main.cpp
 * Author: Daniel Garcia
* Created on April 26, 2020, 8:00 AM
 * Purpose:  Menu Class Specification
 */

#ifndef MENU_H
#define MENU_H
#include "Player.h"
#include "HashTable.h"
#include "Tree.h"
#include <cstdlib>
#include <list>
#include <iterator>
#include <fstream>
#include <map>
#include <algorithm>
#include <bits/stdc++.h> 
#include <set>
#include <queue>

class Menu{
    private:               
        char choose; ///< Users choice
        float bet;   ///< Users Bet Amount
        ifstream in; 
        ofstream out;
        
        fstream data, file;
        list <float> lst,lst2; ///< Lists for the Users Money Won/Loss history
        multimap <float,string> mp; ///< Map For Leader Board
        multimap <string, float> mp2; ///< Map for Users Money Won/Loss history
        multiset <float> s; ///< Set for net money won/loss
        stack <int> stak;  ///< Stack for total games played as the user
        string name;
        char choice;
        queue<string> names;
        queue<int> scores;
        int size;
        
        float *scor;
        float *scor2;
         //int array[size];
        string *nam;
        HashTable table;
        
        
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
        friend ostream &operator << (ostream &, const Menu &); 
        ///! Create List
        void createList();
        ///! LeaderBoard
        void leadBrd();
        ///! Ask User's Name
        void askName();
        ///! Return User's Name
        string getName(){return name;}
        ///! Users Betting History
        void betHist();
        ///! Create Map
        void createMap();
        void swap(float*,float*);
        int partition(float [],int,int);
        void quickSort(float [],int,int);
        void createArys();
        void shellSrt(float [], int);
        ~Menu();
        void hashSrch();
        
        void trePrac();
        void personal();
        void allTime();
        
};


#endif /* MENU_H */