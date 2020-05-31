/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "HashTable.h"

void HashTable::insert(){
    //for(int i=0;i<size;i++){
        cout<<"1: "<<ary[hash].hash2<<endl;
        if (ary[hash].hash2==-1){
            ary[hash].hash2=hash;
            ary[hash].name=nam;
            //COME BACK SET BET
        }
        else{
            Node *newNde=new Node;
            newNde->hash2=hash;
            newNde->name=nam;
            //COME BACK SET BET
            ary[hash].next=newNde;
        }   
        cout<<"2: "<<ary[hash].hash2<<endl;

    //}
}
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
      hash%=size;
   }
}

HashTable::~HashTable(){
    delete []ary;
}
void HashTable::create(int n){
    
    ary=new Node[n];
    for(int i=0;i<size;i++){
        ELFHash(dat[i]);
        insert();
    }
}
