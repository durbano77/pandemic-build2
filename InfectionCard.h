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

	City* getCity();
	string getColor() const;

	//action
	void Infect(int* remainingDiseaseCubes, bool* isEradicated, City* theCity, string color);

protected:
    std::string color="";
		City* city;
};
