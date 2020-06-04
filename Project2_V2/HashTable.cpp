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
    Node temp;
    temp=ary[hash];
    cout<<"TEST BOI"<<temp.name<<endl;
        if (ary[hash].hash2==-1){
            ary[hash].hash2=hash;
            ary[hash].name=nam;
            ary[hash].bet=betC;
            //COME BACK SET BET
        }
        else{
            Node *newNde=new Node;
            newNde->hash2=hash;
            newNde->name=nam;
            newNde->bet=betC;
            ary[hash].next=newNde;
            
           // insert();
            
        }   
/*        cout<<"Hash = "<<ary[hash].hash2<<endl;
        cout<<"Name = "<<ary[hash].name<<endl;
        cout<<"Bet = "<<ary[hash].bet<<endl<<endl;
*/       
}
void HashTable::srch(string temp){
    
    cout<<"Test:"<<endl;
    cout<<ary[hash].name<<" ";
    cout<<ary[hash].bet<<endl;
    cout<<ary[hash].next->name<<" ";
    cout<<ary[hash].next->bet<<endl;
    //cout<<ary[hash].next->next->name<<" ";
    //cout<<ary[hash].next->next->bet<<endl;
    
    nam=temp;
    Node *newNde=new Node;
    newNde->next=ary[hash].next;
    do{
        newNde->name=ary[hash].name;
        newNde->next=ary[hash].next;
        newNde->bet=ary[hash].bet;
        if (newNde->name==nam){
            cout<<"Name = "<<newNde->name<<endl;
            cout<<"Bet = "<<newNde->bet<<endl;
        }
        newNde->next=newNde->next->next;
    }while(newNde->next!=NULL);
    //if(ary[hash].hash2==-1) cout<<"TEst"<<endl;
     
}