/*
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on May 26, 2020, 8:00 AM
 * Purpose:  BlackJack Project 2 V1 Added stack
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
//User Libraries
#include"Menu.h"
//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
//Function Prototypes
//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
     srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const int NUMCARDS=52;
    Deck cards[NUMCARDS];           
    int fileCnt, count;    
    char choose;    
    bool low;      
    string name;
    queue<int> que; //Queue for Index
    fileCnt=1;
    Deck *userHan;
    do{
      Menu menu;                            //Menu Constructor         
      if (choose != 'Y' || choose!= 'y')menu.askName(); //Ask for the User's Name
      do{ 
          do{
              low=true;
              try{  
                  menu.menu();               //Display The Menu
                  }catch(Menu::lowMon){     // Catch if not enough money to play
                      low=false;
                      menu.warn();          //Warn if low money in account
                  }
            }while(!low);                   //Warn while money is low
        //Repeat until user enters p
        }while(menu.getChse() != 'P' && menu.getChse() != 'p');
        menu.betMon();                      //User enters bet
        que=cards[0].fillQue(NUMCARDS);     //Fills Index
        for (int i=0;i<NUMCARDS;i++){
            cards[i]=cards[0].fillDeck(i);  //Creates a card for each index       
        }
        Hand hand;                          //Hand Constructor
        hand.deal(cards,que);               //Fills the hand
        userHan=hand.getUhand();            //Returns the users hand
        Player dealer(hand.getUhand(),cards,menu.getBet()); //Player Constructor
        ++dealer;   
        dealer++;   
        Player user=dealer;         
        user.setDealers(hand.getDhand());           //Set Dealer's Hand
        cout<<menu;     //Overloaded Operator, couts an object directly
        count=user.getCount();                      //Return Count
        user.inFile(fileCnt);
        choose=user.getChoice();                    //Getter
        user.monHist(user.getRes(),user.getBet(),menu.getName());//Write to file
    }while(choose == 'Y' || choose== 'y');
    //Exit stage right or left!
    return 0;
}