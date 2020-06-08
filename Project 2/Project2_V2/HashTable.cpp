/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "HashTable.h"


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

HashTable::~HashTable(){
    delete []ary;
   // delete []dat;
}
void HashTable::create(int n){
    hshSz=n;
    ary=new Node[hshSz];
    for(int i=0;i<size;i++){
        betC=bets[i];
        ELFHash(dat[i]);
        insert();
    }
}
void HashTable::insert(){
   // Node *temp=ary;
    //temp=ary[hash];
        if (ary[hash].hash2==-1){
            ary[hash].hash2=hash;
            ary[hash].name=nam;
            ary[hash].bet=betC;
            //COME BACK SET BET
        }
        else {
            Node *newNde=new Node;
            newNde->hash2=hash;
            newNde->name=nam;
            newNde->bet=betC;
            ary[hash].next=newNde;
/*
        if(ary[hash].next->hash2==-1)
        {
            Node *newNde=new Node;
            newNde->hash2=hash;
            newNde->name=nam;
            newNde->bet=betC;
            ary[hash].next->next=newNde;
        }
*/
        }
        
}
void HashTable::end(){
    Node *next=&ary[hash];
   
    while(next->next!=NULL){
        last=next;
        next=next->next;
        cout<<"?"<<endl;
    }
}
void HashTable::srch(string temp){
/*
    cout<<"Test:"<<endl;
    cout<<ary[hash].name<<" ";
    cout<<ary[hash].bet<<endl;
    cout<<ary[hash].next->name<<" ";
    cout<<ary[hash].next->bet<<endl;
    //cout<<ary[hash].next->next->name<<" ";
    //cout<<ary[hash].next->next->bet<<endl;
*/ 
    nam=temp;
    Node *newNde=new Node;
    newNde=ary;
    newNde->name=ary[hash].name;
    newNde->next=ary[hash].next;
    newNde->bet=ary[hash].bet;
    //FIX INSERTION OVER 2, newNde=newNde->next might be the key
    while(newNde!=NULL){
        if (newNde->name==nam){
            cout<<"Name = "<<newNde->name<<endl;
            cout<<"Bet = "<<newNde->bet<<endl;
        }
        newNde=newNde->next;
         
    }
    //if(ary[hash].hash2==-1) cout<<"TEst"<<endl;
     
}