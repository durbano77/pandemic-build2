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

using namespace std;

class Pawn : public CObject {
public:
    Pawn();
    Pawn(CString color, City* c, CString playerName);
   // Pawn(CString color, Player* p);
    ~Pawn();
    void printPawn();
    CString getPawnColor();
	City* getPawnCity();
    void setPawnCity(City* newpawncity);
    void setPawnCityCString(CString cityCStringname, City* acities[]);
	CString getPlayerName();
	void setPlayerName(CString playerName);
    //Player* getPawnPlayer();
    //Player* p;


	DECLARE_SERIAL(Pawn)
	void Serialize(CArchive& archive);

protected:
    CString color;
    City* pawncity;
	CString playerName;
    
};

#endif /* PAWN_H_ */
