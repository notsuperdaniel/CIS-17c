/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on May 20, 2020, 8:00 AM
 * Purpose:  Menu Class Implementation
 */
#include "Menu.h"
//==============================================================================
//Display the Rules
//==============================================================================
 void Menu::rules(){
     
     cout<<"The objective of Blackjack is to get the sum of your cards as close \n"
             "to equalling 21 without going over. To beat the dealer, your sum\n"
             "has to be greater than theirs, while not exceeding 21. If the \n"
             "player/dealers sum of cards exceed 21 then they 'bust' and the other\n"
             "person wins. If the dealer and players sum both equal each other \n"
             "while being under 21, then the player 'pushes', resulting in a tie.\n"
             "Face cards hold a value of 10, and an ace can be worth a 1 or 11.\n";
 }
//==============================================================================
//Bet Money Function
//==============================================================================
 void Menu::betMon(){
     float mon;
     in.open("Money.txt");
     in>>mon;
     in.close();
     cout<<endl<<endl;
     do{
     cout<<"=================================================================="
             ""<<endl;
     cout<<"Enter the Amount of money you would like to bet."<<endl;
     cout<<"Minimum bet = $5-----------------Max Bet = $500"<<endl;
     cout<<"Bet = ";
     cin>>bet;
     if(bet>mon){
         cout<<"==============================================================="
                 "==="<<endl;
         cout<<"You have ($"<<mon<<") in your stash. Please bet a smaller amount"
                 "."<<endl;
     }
     }while(bet>mon);
         
     while(bet<5 || bet>500){
     cout<<"------------------------------------------------------------"<<endl;
     cout<<"Invalid Amount Entered."<<endl;
     cout<<"Minimum bet = $5-----------------Max Bet = $500"<<endl;
     cout<<"Bet = ";
     cin>>bet;
     }
 }
//==============================================================================
//Check The amount of money in the stash
//==============================================================================     
 void Menu::check(){
         float mon;
             in.open("Money.txt");
             in>>mon;
             in.close();
             cout<<endl<<endl;
             cout<<"============================================================"
                     "======"<<endl;
             cout<<"Money currently in your stash = $"<<mon<<endl;
             out.open("Money.txt");
             out<<mon;
             out.close();
             
      }
//==============================================================================
//Add Money To The Stash
//==============================================================================
 void Menu::add(){
         float mon,addMon;
             in.open("Money.txt");
             in>>mon;
             in.close();
             cout<<"==========================================================="
                     "======="<<endl;
             cout<<"How Much Money Would You Like To Add?"<<endl;
             cout<<"Warning: If you enter a letter, it will break :'("<<endl;
             cin>>addMon;
             mon+=addMon;
             out.open("Money.txt");
             out<<mon;
             out.close();
             cout<<"==========================================================="
                     "======="<<endl;
             cout<<"You added "<<addMon<<"$ to your stash of money!"<<endl;
             cout<<endl<<endl;   
 }
//==============================================================================
//Display the Money Function
//==============================================================================
void Menu::menu(){
    createArys();
    float mon;
    do{   
   cout<<"=================================================================="<<endl;
   cout<<"-To Play, Enter------------------------------------------(P)"<<endl;
   cout<<"-To Add Money To Play With, Enter------------------------(M)"<<endl;
   cout<<"-To Check The Amount Of Money In Your Stash, Enter-------(S)"<<endl;
   cout<<"-To Check Your Stats, Enter------------------------------(T)"<<endl;
   cout<<"-To Check The Leader Board, Enter------------------------(L)"<<endl;
   cout<<"-To Check The History Of Money Won/Lost Per Game, Enter--(H)"<<endl;
   cout<<"-To Display The Rules Of BlackJack, Enter----------------(R)"<<endl;
    cin>>choose;
    }while(choose != 'p' &&choose != 'P' && choose != 'm' && choose != 'M'
            && choose != 's' && choose != 'S' && choose !='R' &&choose!='r' &&
            choose !='T' && choose !='t' && choose !='L' && choose!= 'l' 
            && choose !='H' && choose!= 'h');
    
    if (choose=='M' || choose=='m'){ 
        add();
    }
    else if(choose=='R' || choose=='r'){
        rules();
    }
    else if(choose=='T' || choose=='t'){
         monWon();
    }
    else if(choose=='L' || choose=='l'){
      leadBrd();
    }
    else if(choose=='H' || choose=='h'){
      betHist();
    }
    else if(choose == 's' || choose == 'S'){
        check();
    }
    in.open("Money.txt");
    in>>mon;
    in.close();
     if(mon<5){
        throw lowMon();
        }
}
//==============================================================================
//Overloaded Operator to cout an object
//==============================================================================
 ostream &operator << (ostream &strm, const Menu &obj)  {
     float mon;
     ifstream in;
     ofstream out;
     in.open("Money.txt");
    in>>mon;
    in.close();
    strm << "Updated Amount of Money: $"<<mon<<endl;
    return strm;  
 }
//==============================================================================
//Display Low Money Warning
//==============================================================================
 void Menu::warn(){
     cout<<"==================================================================\n";
     cout<<"WARNING: Low money in your stash. Add money to play."<<endl;
 }
//==============================================================================
//Net Amount Of Money Won or Loss from Previous Games
//==============================================================================
 void Menu::monWon(){
     float mon=0;
     int games=0;
     createList();
     createMap();
     
     multimap <string,float>::iterator itr;         //Map Iterator
     for (itr=mp2.begin();itr!=mp2.end();itr++){
          if(name==itr->first){
              s.insert(itr->second);                //Insert into set
          }
     }
     multiset <float>::iterator it;                 //Set Iterator
      for (it=s.begin();it!=s.end();it++){
          mon+=*it;
      }
     s.clear();
    
     for (itr=mp2.begin();itr!=mp2.end();itr++){
          if(name==itr->first){
              stak.push(1);         //Push onto the stack
          }
     }
     games=stak.size();             //Size of the stack
     
     lst2.clear();      //Clears List
     for(itr=mp2.begin();itr!=mp2.end();itr++){
         if(name==itr->first)lst2.push_back(itr->second);
     }
     
     cout<<"==================================================================\n";
     cout<<"Number of Wins        = "<<count_if(lst2.begin(),lst2.end(),        //Count Algorithm
             [](int i){return i>0;})<<endl;
     cout<<"Number of Losses      = "<<count_if(lst2.begin(),lst2.end(),
             [](int i){return i<0;})<<endl;
             if(*max_element(lst2.begin(),lst2.end())>0){
                 cout<<"Biggest Win           = $"<<*max_element(lst2.begin(),  //Max Algorithm
                         lst2.end())<<endl;
             }
             if(*min_element(lst2.begin(),lst2.end())<0){
                 cout<<"Biggest Loss           = $"<<*min_element(lst2.begin(), //Min Algorithm
                         lst2.end())<<endl;
             }
     cout<<"Net Money Won/Loss    = $"<<mon<<endl;
     cout<<"Over a Total of         "<<games<<" Games."<<endl;
 }
//==============================================================================
//Create the List 
//==============================================================================
 void Menu::createList(){
     float temp;
     lst.clear();
     data.open("MoneyHist.txt", ios::in);  
     while(!data.eof()){
         data>>temp;
         lst.push_front(temp);
     }
      lst.pop_front();
     data.close();
 }
//==============================================================================
//Bet History
//==============================================================================
 void Menu::betHist(){
     char pick;
     do{
     cout<<"==================================================================\n";
     cout<<"If You Would Like To Search a Record By Name, Enter--------------(N)"<<endl;
     cout<<"To Check Your History, Enter-------------------------------------(M)"<<endl;
     cin>>pick;
     }while(pick != 'N' &&pick != 'n' && pick != 'M' && pick != 'm');
     if (pick=='N' || pick=='n') hashSrch();
     if (pick=='M' || pick=='m'){
         createList();
         createMap();
         float temp;
         int count=1;
         cout<<"==================================================================\n";
         cout<<"Money Won/Loss History:"<<endl;
         cout<<"(Note: If you haven't played a game under your name yet, nothing"<<endl;
         cout<<"will show up here)"<<endl;
         multimap <string,float>::iterator itr;                //Map Iterator
         for (itr=mp2.begin();itr!=mp2.end();itr++){
             if(name==itr->first){
             cout<<"Game "<<count<<" = $"<<itr->second<<endl;
             count++;
             }
         }
     }
 }
//==============================================================================
//Fill Arrays With Data
//==============================================================================
 void Menu::createArys(){
      float temp;
     while (!scores.empty()){ //Make sure they're clear
         scores.pop();
     }
      while (!names.empty()){
         names.pop();
     }
     data.open("MoneyHist.txt", ios::in);  
     while(!data.eof()){
         data>>temp;
         scores.push(temp);
     }
     data.close();
     string temp2;
     data.open("Names.txt", ios::in);  
     while(!data.eof()){
         data>>temp2;
         names.push(temp2);
     }
     data.close();
     size=scores.size()-1;
     scor=new float[size];
     scor2=new float[size];
     nam=new string[size];;
     for(int i=0;i<size;i++){
         scor[i]=scores.front();
         scores.pop();
         nam[i]=names.front();
         names.pop();
     }
 }
//==============================================================================
//Leader Board Menu
//==============================================================================
 void Menu::leadBrd(){
     char pick;
     do{
         cout<<"=================================================================="<<endl;
         cout<<"For Your Personal Leader Board, Enter----------------------------(P)"<<endl;
         cout<<"For The All-Time Leader Board Using Quick Sort, Enter------------(L)"<<endl;
         cout<<"For The All-Time Leader Board Using a Tree, Enter----------------(T)"<<endl;
    cin>>pick;
    }while(pick != 'P' && pick != 'p'
            && pick != 'L' && pick != 'l' && pick !='T' &&pick!='t');
    cout<<"==================================================================\n";
    cout<<"Ranking From Most Money Won On A Single Bet, To Most Money Lost:"<<endl;
    cout<<"==================================================================\n";    
    if(pick=='P' || pick=='p'){
         personal();
    }
    if(pick=='L' || pick=='l'){
        allTime();
    }
    if(pick=='T' || pick=='t'){
        trePrac();
    }
 }
//==============================================================================
//Personal Leader Board
//==============================================================================
void Menu::personal(){
    cout<<"Personal Leader Board:\n";
    int j=0;
    for(int i=0;i<size;i++){
        if (name==nam[i]){
            scor2[j]=scor[i];
            j++;
        }
    }
    inSrt(scor2,j);
    int a=1;
    for(int i=j-1;i>=0;i--){
        cout<<a<<": $"<<scor2[i]<<endl;
        a++;
    }
}
//==============================================================================
//All Time Leader Board
//==============================================================================
void Menu::allTime(){
    quickSort(scor,0,size-1);
    cout<<"All Time Leaderboard: \n";
    int k=1;
    for(int i=size-1;i>=0;i--){
        cout<<k<<": $"<<scor[i]<<endl;
        k++;
    }
}
//==============================================================================
//Create Map
//==============================================================================
 void Menu::createMap(){
      string temp;
      mp.clear();   //Clears the map
      mp2.clear();  //Clears the map
     int count=0;
     file.open("Names.txt", ios::in);
     while(!file.eof()){
         file>>temp;
         count++;
     }
     file.close();
     count-=1;
     file.open("Names.txt", ios::in);
     for(int i=0;i<count;i++){
         file>>temp;
         mp2.insert(pair <string, float> (temp, lst.back()));   //Inserting in Maps
         mp.insert(pair <float, string> (lst.back(), temp));
         lst.pop_back();
     }
     file.close();
 }
//==============================================================================
//Ask For the User's Name
//==============================================================================
  void Menu::askName(){
   cout<<"=================================================================="<<endl;
   cout<<"Welcome to BlackJack!"<<endl;
   cout<<"Please Enter Your Name: ";
   cin>>name;
 }
  void Menu::swap(float* a, float* b){
      float t=*a;
      *a=*b;
      *b=t;
  }
  int Menu::partition(float arr[], int low, int high){
      int pivot=arr[high];
      int i=(low-1);
      for(int j=low;j<=high-1;j++){
          if (arr[j]<pivot){
              i++;
              swap(&arr[i],&arr[j]);
          }  
      }
      swap(&arr[i+1],&arr[high]);
      return i+1;  
}  
//==============================================================================
//Quick Sort
//==============================================================================
  void Menu::quickSort(float arr[], int low, int high){
      if(low<high){
          int pi=partition(arr,low,high);
          quickSort(arr,low,pi-1);
          quickSort(arr,pi+1,high);
      } 
  }
//==============================================================================
//Insertion Sort
//==============================================================================
  void Menu::inSrt(float arr[], int n){
      if(n<=1) return;
      inSrt(arr,n-1);
      int last=arr[n-1];
      int j=n-2;
      while(j>=0 && arr[j]>last){
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=last;
  }
//==============================================================================
//Menu Destructor
//==============================================================================
  Menu::~Menu(){
      delete[]nam;
      delete[]scor;
      delete[]scor2;
  }
//==============================================================================
//Calls Hash Table Functions to Create and Search The Table
//==============================================================================
  void Menu::hashSrch(){ 
      table.setDat(nam,size,scor);
      table.create(200);
      string temp;
      cout<<"Enter a name: "<<endl;
      cin>>temp;
      table.ELFHash(temp);
      table.srch(temp);
  }
//==============================================================================
//Creates and Prints The Tree From Greatest to Smallest
//==============================================================================
  void Menu::trePrac(){
      Tree tre;
      for(int i=0;i<size;i++){
          tre.root=tre.insert(tre.root,scor[i]);
      }
      cout<<"Printing from Tree:"<<endl;
      tre.inorder(tre.root);
  }
  