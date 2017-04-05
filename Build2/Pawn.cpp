//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Pawn.cpp

#include "Pawn.h"
#include <string>




Pawn::Pawn(){}

Pawn::Pawn(std::string color, City* c) {
    this->color=color;
    this->pawncity=c;
}


//Pawn::Pawn(std::string color, Player* p) {
//    this->color=color;
//    this->p=p;
//    //pplayer=pplayer;
//}

Pawn::~Pawn(){

}

void Pawn::printPawn(){
    std::cout<<"----------------------------------------"<<std::endl;
    std::cout<<"Pawn: " << this->color <<std::endl;
    //std::cout<<getPlayerName()<<std::endl;
    std::cout<<"----------------------------------------\n\n"<<std::endl;
    
}

std::string Pawn::getPawnColor(){
    return color;
}


City* Pawn::getPawnCity(){
    return pawncity;
}

void Pawn::setPawnCity(City* newpawncity){
    pawncity=newpawncity;
}

