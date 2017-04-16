//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//CityCard.h

#ifndef CityCard_h
#define CityCard_h

#include <stdio.h>
#include "PlayerCard.h"

#endif /* CityCard.h */

using namespace std;

class CityCard: public PlayerCard{
public:
    CityCard();
    CityCard(CString city, CString title, CString cardtextfront, CString cardtextback);
    ~CityCard();
protected:
    CString city; //to be changed for real city object

};

//NOTE: CString city parameter type has to be changed for the real City class

class BlueCity : public CityCard{
public:
    BlueCity();
    BlueCity(CString city, CString title, CString cardtextfront, CString cardtextback);
    ~BlueCity();
};

class YellowCity : public CityCard{
public:
    YellowCity();
    YellowCity(CString city, CString title, CString cardtextfront, CString cardtextback);
    ~YellowCity();
};

class BlackCity : public CityCard{
public:
    BlackCity();
    BlackCity(CString city, CString title, CString cardtextfront, CString cardtextback);
    ~BlackCity();
};

class RedCity : public CityCard{
public:
    RedCity();
    RedCity(CString city, CString title, CString cardtextfront, CString cardtextback);
    ~RedCity();
};

