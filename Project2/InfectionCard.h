//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//InfectionCard.h

#pragma once
#include <CString>
#include <vector>
#include "Cards.h"
#include "City.h"
using namespace std;

class InfectionCard : public Cards {
public:
	//constructor,destructor
	InfectionCard();
	InfectionCard(City* theCity, CString title, CString cardtextfront, CString cardtextback);
	~InfectionCard();

	City* getCity();
	CString getColor() const;

	//action
	void Infect(int* remainingDiseaseCubes, bool* isEradicated, City* theCity, CString color);

protected:
    CString color="";
		City* city;
};
