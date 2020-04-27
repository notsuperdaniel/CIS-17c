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
template<class T>
class TotWinnings{
    private:
        T mon;
        ifstream in;
        ofstream out;
    public:
        void totMoneyWL(string, float);
        
};
template<class T>
void TotWinnings<T>::totMoneyWL(string result,float bet){
    T tot;
    in.open("TotMoneyWonLoss.txt");
    in>>tot;
    in.close();
    out.open("TotMoneyWonLoss.txt");
        
    if (result=="Win"){
        tot+=bet;
        
    }
    else if(result=="Loss"){
        tot-=bet;
    }
    out<<tot;
    out.close();
    
}
#endif /* TOTWINNINGS_H */