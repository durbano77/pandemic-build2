//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//PlayerView.h

#ifndef PlayerView_h
#define PlayerView_h

#include <iostream>
#include <string>
//#include "City.h"
#include "Player.h"

#include <vector>
#include <iterator>


class PlayerView : public Observer{
public:
    PlayerView(); //default constructor
    PlayerView(Player *plyr);
    ~PlayerView();
    void Update(int u);
    //void UpdateHand();
   // void UpdateDiscardHand();
   // void UpdateEpidemicCard();
    void display(int t);
    void displayAll();
    void displayHand();
    void displayDiscardHand();
    void displayEpidemicCard();
    void displayPawn();
    
    void clearScreen();
protected:
    Player* p;

};
#endif /* PlayerView_h */
