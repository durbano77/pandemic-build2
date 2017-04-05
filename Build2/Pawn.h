//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Pawn.h

#ifndef PAWN_H_
#define PAWN_H_


#include <iostream>
#include "City.h"

class Pawn {
public:
    Pawn();
    Pawn(std::string color, City* c);
   // Pawn(std::string color, Player* p);
    ~Pawn();
    void printPawn();
    std::string getPawnColor();
	City* getPawnCity();
    void setPawnCity(City* newpawncity);
    //Player* getPawnPlayer();
    //Player* p;
    
protected:
    std::string color;
    City* pawncity;
    
};

#endif /* PAWN_H_ */
