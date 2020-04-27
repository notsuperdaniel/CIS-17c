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
        fstream data,file,dat;
    public:
        void totMoneyWL(string, float, string);
        void monHist(string, float, string);
        
};

void TotWinnings::totMoneyWL(string result,float bet, string name){
    
   // dat.open("WonLoss.txt", ios::out | ios::app);
   
    monHist(result,bet,name);
}

void TotWinnings::monHist(string result, float bet, string name){
    data.open("MoneyHist.txt", ios::out | ios::app);
     file.open("Names.txt", ios::out | ios::app);
    if (result=="Win"){
        data<<bet<<endl;
        
        file<<name<<endl;
    }
    if(result=="Loss"){
        data<<(bet)*-1<<endl;
        
        file<<name<<endl;
    }
    data.close();
    file.close();
}
#endif /* TOTWINNINGS_H */