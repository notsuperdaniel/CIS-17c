/* 
 * File:   main.cpp
 * Author: Daniel Garcia
 * Created on April 26, 2020, 8:00 AM
 * Purpose:  Player Class Implementation
 */
#include "Player.h"
//==============================================================================
//Overloaded Prefix ++ Operator to increment games
//==============================================================================
void Player::operator ++(){
   ++games;
  
}
//==============================================================================
//Overloaded Postfix ++ Operator to increment offset
//==============================================================================
 void Player::operator ++(int){
    offSet++;
}


//==============================================================================
//Write Game History to text
//==============================================================================
void Player::inFile(int &fileCnt){
        //if count=1 then open with out, if more then open with ios::out | ios::app
    if (fileCnt==1){
         dataFile.open("GameHistory.txt", ios::out);
         dataFile<<"Game 1:"<<endl;                             
         dataFile<<"Your score"<<setw(7)<<"= "<<sum<<endl;
         dataFile<<"Dealer's score"<<" = "<<dSum<<endl;
         dataFile<<"Result"<<setw(11)<<"= "<<result<<endl;
    }
    else if (fileCnt>1){
        dataFile.open("GameHistory.txt", ios::out | ios::app);
        dataFile<<endl<<"Game "<<fileCnt<<":"<<endl;
        dataFile<<"Your score"<<setw(7)<<"= "<<sum<<endl;       
        dataFile<<"Dealer's score"<<" = "<<dSum<<endl;
        dataFile<<"Result"<<setw(11)<<"= "<<result<<endl;
    }
    fileCnt++;
    dataFile.close();
    int played;
    in.open("totGame.txt");
    in>>played;
    in.close();
    played+=1;
    out.open("totGame.txt");
    out<<played;
    out.close();
    
}

//==============================================================================
//Display Result
//==============================================================================
void Player::winLoss(){
    char ask[]= "Would you like to play again?";        
    string prompt= "Enter (Y) for YES, enter (N) for NO."; 
    

    ifstream in;
    ofstream out;
    float mon;
     if(sum>21 && dSum<=21){           
        result="Loss";                           
        cout<<"You bust, the dealer Wins! :("<<endl;  
        cout<<"You lost "<<bet<<" $"<<endl;
        in.open("Money.txt");
        in>>mon;
        in.close();
        mon-=bet;
        out.open("Money.txt");
        out<<mon;
        out.close();
   }                                                                                                                           
    if (sum==dSum){
        result="Tie";                                   
        cout<<"It's a tie!"<<endl;       
        cout<<"You keep your "<<bet<<" $"<<" bet!"<<endl;
    }                                  
    if(sum>dSum && sum<=21){
        result="Win";
        cout<<"Congrats, you win!!"<<endl;       
        cout<<"You won "<<bet<<" $"<<endl;
        in.open("Money.txt");
        in>>mon;
        in.close();
        mon+=bet;
        out.open("Money.txt");
        out<<mon;
        out.close();
    }      
    if(sum<=21 && dSum>21){     
         result="Win";                                  
         cout<<"The Dealer busts. Congrats, you win!!"<<endl;  
          cout<<"You won "<<bet<<" $"<<endl;
        in.open("Money.txt");
        in>>mon;
        in.close();
        mon+=bet;
        out.open("Money.txt");
        out<<mon;
        out.close();
    }                                                                  
    if (dSum>sum && dSum<=21){    
  result="Lose";
        cout<<"You lose. :("<<endl;  
        cout<<"You lost "<<bet<<" $"<<endl;
        in.open("Money.txt");
        in>>mon;
        in.close();
        mon-=bet;
        out.open("Money.txt");
        out<<mon;
        out.close();
    }
    for (int i=0;i<strlen(ask);i++){                
        cout<<ask[i];
    }
    do{
    cout<<endl<<prompt<<endl;
    cin>>choice;
     }while(choice != 'Y' && choice != 'y' &&  choice != 'N' && choice!='n');
    cout<<"=================================================================="<<endl;
}
//==============================================================================
//Math to decide if Dealer hits
//==============================================================================
void Player::dCards(){
    int dcount=2;
    char ent;
    do{
        dSum=0;
        cout<<"Enter any key to continue."<<endl;
        cin.ignore();
         cout<<"==================================================================\n";
    for (int i=0;i<dcount;i++){
    cout<<"Dealers Card #"<<i+1<<" = "<<dealers[i].getName()<<endl;
        if (dealers[i].getName()=="Ace" && dSum<=10) dealers[i].setVal(11);
        if (dealers[i].getName()=="Ace" && dSum>10) dealers[i].setVal(1);
        dSum+=dealers[i].getVal();
       }
    if (dSum<17){cout<<"The Dealer Hits."<<endl;
        dcount++;
    }
    }while (dSum<17);
    cout<<"Dealers Sum = "<<dSum<<endl;
    cout<<"Your Sum = "<<sum<<endl;
}
//==============================================================================
//Display The Users cards in play
//==============================================================================
void Player::display(){
    if(sum>21){
        string bust;
        throw bust;     
    }
    for (int i=0;i<count;i++){
        cout<<"Card "<<i+1<<" = "<<users[i].getVal()<<endl;
    }
    cout<<"Sum = "<<sum<<endl;
    cout<<"Dealers Card = "<<dealers[0].getName()<<" of "<<dealers[0].getSui()<<endl;
}
//==============================================================================
//Decide the value of Ace if the user has an Ace in Play
//==============================================================================
void Player::isAce(){
    cout<<"==================================================================\n";
    char choose;
    for (int i=0;i<count;i++){
        if(users[i].getName()=="Ace"){
            do{
            cout<<"Card "<<i+1<<" is an "<<users[i].getName()<<"!"<<endl;
            cout<<"If you would like the value to = '11', input (Y). If you would "
            "like the value to = '1', input (N)."<<endl;
            cin>>choose;
            }while(choose != 'Y' && choose != 'y' &&  choose != 'N' && choose!='n');
            if (choose == 'Y' || choose == 'y') users[i].setVal(11);
        }
        sum+=users[i].getVal();
    }
    
}
//==============================================================================
//Double Down
//==============================================================================
void Player::dblDown(){
    char choose;
    float mon;
    in.open("Money.txt");
    in>>mon;
    in.close();
    do{
        cout<<"================================================================"
                "=="<<endl;
    cout<<"Would you like to double down?"<<endl;
    cout<<"-Input (Y) for yes, or (N) for no."<<endl;
    cin>>choose;
            cout<<"============================================================"
                    "======\n";

    }while(choose != 'Y' && choose != 'y' &&  choose != 'N' && choose!='n');
    if (choose=='Y'|| choose=='y'){
        if(bet*2>mon){
            cout<<"You don't have enough money in your stash to double down."
                    <<endl;
        }
        else{
            dble=false;
        bet=bet*2;
        cout<<"You decided to double down."<<endl;
        cout<<"Your total bet is now ($"<<bet<<") "<<endl;
        }
    }
}
//==============================================================================
//Start Playing
//==============================================================================
void Player::play(){
    char hit;
    dble=true;
    do{
    cout<<"==================================================================\n";   
    for (int i=0;i<count;i++){
    cout<<"Card "<<i+1<<" = "<<users[i].getName()<<" of "<<users[i].getSui()<<endl;
    }
    cout<<"Dealers Card = "<<dealers[0].getName()<<" of "<<dealers[0].getSui()<<endl;
    if(count==2) dblDown();                   
    if(dble==true){
        do{
            cout<<"Would you like to hit?-Input (Y) for yes, and (N) for no."<<endl;
            cin>>hit;
            }while(hit != 'Y' && hit != 'y' &&  hit != 'N' && hit!='n');
            if (hit=='y' || hit=='Y') count++;
            if (hit=='n'|| hit=='N'){
                cout<<"==================================================================\n";
                cout<<"You decided to stay."<<endl;
            }
    }
    if (dble==false){
        hit='n';
        count++;
        for (int i=0;i<count;i++){
            cout<<"Card "<<i+1<<" = "<<users[i].getName()<<" of "<<users[i].getSui()<<endl;
        }
        cout<<"Dealers Card = "<<dealers[0].getName()<<" of "<<dealers[0].getSui()<<endl;   
    }
    }while (hit == 'Y' || hit == 'y' && hit !='N' && hit != 'n');
    if (hit=='y' || hit=='Y') cout<<"=========================================="
            "========================\n";
    isAce();
    try{
        display();
        dCards();
    }catch(string bust){};
    winLoss();
   // inFile();
}
//==============================================================================
//Player Constructor
//==============================================================================
Player::Player(Deck *c,Deck *card, int i){
    users=c;
    cards=card;
    bet=i;
    count=2;
    sum=0;
    dSum=0;
}
//==============================================================================
//Player Constructor
//==============================================================================
Player::Player(Deck *c,Deck *card, int i,string nam){
    users=c;
    cards=card;
    bet=i;
    name=nam;
    count=2;
    sum=0;
    dSum=0;
}
//==============================================================================
//Set Dealers Hand
//==============================================================================
void Player::setDealers(Deck* c){
    dealers=c;
    play();
}
//==============================================================================
//Set Players Hand
//==============================================================================
void Player::setUsers(Deck* c){
    users=c;
}
//==============================================================================
//Copy Constructor
//==============================================================================
Player::Player(Player& obj){        
    users=obj.users;
    cards=obj.cards;
    bet=obj.bet;
    name=obj.name;
    count=obj.count;
    sum=obj.sum;
    dSum=obj.dSum;
    offSet=obj.offSet;
    games=obj.games;
}
//==============================================================================
//Money History
//==============================================================================
void Player::monHist(string result, float bet, string name){
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