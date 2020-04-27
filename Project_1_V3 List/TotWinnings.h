/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on December 9th, 2019, 12:00 PM
 * Purpose:  TotWinnings Class Specification
 */
//This class will keep track in a file how much the player has won or lost.
#ifndef TOTWINNINGS_H
#define TOTWINNINGS_H
#include <fstream>
class TotWinnings{
    private:
        fstream data;
        ifstream in;
        ofstream out;
    public:
        void totMoneyWL(string, float);
        void monHist(string, float);
        
};

void TotWinnings::totMoneyWL(string result,float bet){
    float tot;
    in.open("TotMoneyWonLoss.txt");
    in>>tot;
    in.close();
    out.open("TotMoneyWonLoss.txt");
    
    if (result=="Win"){
        tot+=bet;
    }
  
     if(result=="Loss"){
        tot-=bet;
    }
    out<<tot;
    out.close();
    monHist(result,bet);
}

void TotWinnings::monHist(string result, float bet){
    data.open("MoneyHist.txt", ios::out | ios::app);
    if (result=="Win"){
        data<<bet<<endl;
        cout<<endl<<"OPENED WIN"<<endl;
    }
    cout<<endl<<result<<endl;
    if(result=="Loss"){
        data<<(bet)*-1<<endl;
        cout<<"OPENED LOSS"<<endl;
    }
    data.close();
    cout<<endl<<"Leaving Mon History"<<endl;
}
#endif /* TOTWINNINGS_H */