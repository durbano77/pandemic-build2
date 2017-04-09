//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//InfectionCard.cpp


#include "InfectionCard.h"
#include <iostream>
using namespace std;

InfectionCard::InfectionCard() {
    color="";
	   Cards();
}
InfectionCard::InfectionCard(City* theCity, string title, string cardtextfront, string cardtextback) {
	city = theCity;
	card_name = title;
  color = cardtextfront;
	card_textfront = cardtextfront;		//holds the color to infect with
	card_textback = cardtextback;
	Cards(title, cardtextfront, cardtextback);
}
InfectionCard::~InfectionCard() {

}

std::string InfectionCard::getColor() const{
    return color;
}


void InfectionCard::Infect(int* remainingDiseaseCubes, bool* isEradicated, City* theCity, string color) {
	//takes a city object and color
	//are there enough remaining disease cubes?
	bool enoughCubes = true;
	int colorIndex = 0;
	if (color == "blue" && remainingDiseaseCubes[0] == 0) {
		enoughCubes = false;
		colorIndex = 0;
	}
	else if (color == "yellow" && remainingDiseaseCubes[1] == 0) {
		enoughCubes = false;
		colorIndex = 1;
	}
	else if (color == "black" && remainingDiseaseCubes[2] == 0) {
		enoughCubes = false;
		colorIndex = 2;
	}
	else if (color == "red" && remainingDiseaseCubes[3] == 0) {
		enoughCubes = false;
		colorIndex = 3;
	}

	//Has disease been eradicated?
	if (isEradicated[colorIndex] == true) {
		//skip placing the cubes.
	}
	else {
		//place cubes (if enough remain)
		if (enoughCubes) {
			cout << "Infecting " << theCity->getCityName() << " with the " << color << " disease!" << endl;
			//outbreak scenario?
			if (city->getCubes() == 3) {
				// outbreak

			}
			else {
				//	increment city's disease counter by 1
				city->addCubes();
				//	decrease remaining disease cubes of COLOR by 1
				remainingDiseaseCubes[colorIndex]--;
			}
		}
		else {
			cout << "There are no more " << color << " disease cubes! Game over!" << endl;
			//todo: handle gameover
		}
	}
}
City* InfectionCard::getCity() {
	return city;
}
