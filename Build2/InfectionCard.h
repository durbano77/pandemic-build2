//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//InfectionCard.h

#pragma once
#include <string>
#include <vector>
#include "Cards.h"
#include "City.h"
using namespace std;

class InfectionCard : public Cards {
public:
	//constructor,destructor
	InfectionCard();
	InfectionCard(City* theCity, string title, string cardtextfront, string cardtextback);
	~InfectionCard();
	

	//action
	void Infect(int* remainingDiseaseCubes, City* theCity, string color);

protected:
	City* city;
};
