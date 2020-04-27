/*
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on December 9, 2019, 9:00 AM
 * Purpose:  BlackJack Project 2 V8
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

//User Libraries
#include"Menu.h"
#include "TotWinnings.h"
//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void wrteBin(fstream &, int);
void wrtRcrd(fstream &, Deck *, Deck *, int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
     srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const int NUMCARDS=52;
    Deck cards[NUMCARDS];           //ARRAYS OF CLASS OBJECTS((13.12)
    Deck binCards[NUMCARDS]; 
    fstream binFile, record;
    int fileCnt, count;    
    char choose;    
    bool low;       
    queue<int> que; //index 
    fileCnt=1;
    TotWinnings  mon; //Vector used for templates
    Deck *userHan;
    do{
      Menu menu;                    //INSTANCE OF A CLASS (13.1/2/3)
      do{
          do{
              low=true;
              try{  //EXCEPTIONS (16.1)
                  menu.menu();               //Display The Menu
                  }catch(Menu::lowMon){     // Catch if not enough money to play
                      low=false;
                      menu.warn();
                  }
            }while(!low);
        //Repeat until user enters p
        }while(menu.getChse() != 'P' && menu.getChse() != 'p');
        menu.betMon();
        que=cards[0].fillQue(NUMCARDS);   
        for (int i=0;i<NUMCARDS;i++){
            cards[i]=cards[0].fillDeck(i);         //Arrays/Pointers (9.3)
        }
        Hand hand;
        hand.deal(cards,que);
        userHan=hand.getUhand();
        Player dealer(hand.getUhand(),cards,menu.getBet());
        ++dealer;   //Overloaded Operator
        dealer++;   //Overloaded Operator
        Player user=dealer;         //COPY CONSTRUCTOR (14.4)
        user.setDealers(hand.getDhand());
        cout<<menu;     //Overloaded Operator, couts an object directly
        count=user.getCount();
        user.inFile(fileCnt);
        choose=user.getChoice();
        mon.totMoneyWL(user.getRes(),user.getBet(),menu.getName());
    }while(choose == 'Y' || choose== 'y');
    wrteBin(binFile,fileCnt-1);
    wrtRcrd(record,userHan,binCards,count);
    //Exit stage right or left!
    return 0;
}
void wrtRcrd(fstream &file, Deck *hand1, Deck *bin, int count){ // Recs with Structs (12.8)
    cout<<endl<<"If you would have hit, these would've been your next cards:";
    for (int i=0+count;i<7;i++){
    file.open("BinaryRecord.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&(hand1)), sizeof(hand1[0]));
    file.close();
    
   //Tests if the Users Hand was inserted correctly to the binary file.
    file.open("BinaryRecord.dat", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(&(bin)), sizeof(hand1[0]));
    cout<<endl<<bin[i].getName();
    file.close();
  
    }
}
void wrteBin(fstream &file, int count){                     //Binary Files (12.7)
    char prompt[22]="Total Games Played = ";
    file.open("TotGamesBinary.dat", ios::out | ios::binary);
    file.write(reinterpret_cast<char *>(&prompt), sizeof(prompt));
    file.write(reinterpret_cast<char *>(&count), sizeof(count));
    file.close();
    char bin[sizeof(prompt)];
    int num;
    cout<<endl<<"Reading From Binary File:"<<endl;
    file.open("TotGamesBinary.dat", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(bin), sizeof(prompt));
    file.read(reinterpret_cast<char *>(&num), sizeof(num));
    for (int i=0;i<sizeof(bin);i++){
        cout<<bin[i];
    }
    cout<<num;
    file.close();
}