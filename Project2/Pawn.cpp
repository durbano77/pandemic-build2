//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Pawn.cpp

#include "Pawn.h"
#include <CString>

using namespace std;


Pawn::Pawn(){}

Pawn::Pawn(CString color, City* c, CString playerName) {
    this->color=color;
    this->pawncity=c;
	this->playerName = playerName;
}


//Pawn::Pawn(CString color, Player* p) {
//    this->color=color;
//    this->p=p;
//    //pplayer=pplayer;
//}

Pawn::~Pawn(){

}

void Pawn::printPawn(){
    cout<<"----------------------------------------"<<endl;
    cout<<"Pawn: " << this->color <<endl;
    cout<<"Player: " << this->playerName <<endl;
    cout<<"Location: "<<pawncity->getCityName()<<endl;
    cout<<"----------------------------------------\n\n"<<endl;
    
}

CString Pawn::getPawnColor(){
    return color;
}


City* Pawn::getPawnCity(){
    return pawncity;
}

void Pawn::setPawnCity(City* newpawncity){
    pawncity=newpawncity;
}

void Pawn::setPawnCityCString(CString cityCStringname, City* acities[]){

    for(int i=0;i<48;i++){
        if(cityCStringname==acities[i]->getCityName()){
           this->setPawnCity(acities[i]);
        }
    }
    
}


CString Pawn::getPlayerName() {
	return playerName;
}
void Pawn::setPlayerName(CString playerName) {
	this->playerName = playerName;
}
