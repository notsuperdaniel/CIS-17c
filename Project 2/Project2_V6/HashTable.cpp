/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on May 20, 2020, 11:00 AM
 * Purpose: HashTable Class Implementation
 */
#include "HashTable.h"
//==============================================================================
//Create The Hash For The Name
//==============================================================================
//Note: This Hash Algorithm is from the website that had many different hashes
//that you said we could use.
void HashTable::ELFHash(string n) 
{
    nam=n;
   string &str=nam;
   hash = 0;
   unsigned int x    = 0;
   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = (hash << 4) + str[i];
      if((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }
      hash &= ~x;
      hash%=hshSz;
   }
}
//==============================================================================
//Delete The Data
//==============================================================================
HashTable::~HashTable(){
    delete []ary;
}
//==============================================================================
//Find The End
//==============================================================================
void HashTable::end(){
    Node *next=&ary[hash];
   
    while(next->next!=NULL){
        last=next;
        next=next->next;
        cout<<"?"<<endl;
    }
}
//==============================================================================
//Create The Hash Array
//==============================================================================
void HashTable::create(int n){
    hshSz=n;
    ary=new Node[hshSz];
    for(int i=0;i<size;i++){
        betC=bets[i];
        ELFHash(dat[i]);
        insert();
    }
}
//==============================================================================
//Hash Search
//==============================================================================
void HashTable::srch(string temp){
    nam=temp;
    Node *newNde=new Node;
    newNde=ary;
    newNde->name=ary[hash].name;
    newNde->next=ary[hash].next;
    newNde->bet=ary[hash].bet;
    int a=1;
    while(newNde!=NULL){
        if (newNde->name==nam){
            cout<<"Game "<<a<<": $"<<newNde->bet<<endl;
            a++;
        }
        newNde=newNde->next;
    }
    if(a==1) cout<<"No records found for "<<nam<<endl;
}
//==============================================================================
//Insert Data Into The Hash Array
//==============================================================================
void HashTable::insert(){
        if (ary[hash].hash2==-1){
            ary[hash].hash2=hash;
            ary[hash].name=nam;
            ary[hash].bet=betC;
        }
        else if(ary[hash].next==NULL){
            Node *newNde=new Node;
            newNde->hash2=hash;
            newNde->name=nam;
            newNde->bet=betC;
            ary[hash].next=newNde;
             }
        else if(ary[hash].next->next==NULL){
            Node *newNde=new Node;
            newNde->hash2=hash;
            newNde->name=nam;
            newNde->bet=betC;
            ary[hash].next->next=newNde;
        }
        else{
             Node *newNde=new Node;
            newNde->hash2=hash;
            newNde->name=nam;
            newNde->bet=betC;
            ary[hash].next->next->next=newNde;
        }
}