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
InfectionCard::InfectionCard(string city, string title, string cardtextfront, string cardtextback) {
	city = city;
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

void InfectionCard::Infect(int* remainingDiseaseCubes, string city, string color) {
	//takes a city string and color
	//are there enough remaining disease cubes?
	bool enoughCubes = true;
	if (color == "blue" && remainingDiseaseCubes[0] == 1) {
		enoughCubes = false;
	}
	else if (color == "yellow" && remainingDiseaseCubes[1] == 1) {
		enoughCubes = false;
	}
	else if (color == "black" && remainingDiseaseCubes[2] == 1) {
		enoughCubes = false;
	}
	else if (color == "red" && remainingDiseaseCubes[3] == 1) {
		enoughCubes = false;
	}
	//todo: change to city object
	if (enoughCubes) {
		cout << "Infecting " << city << " with the " << color << " disease!" << endl;
		//outbreak scenario?
		//if(city) has 3 cubes{
		// outbreak
		//}
		//else{
		//	increment city's disease counter by 1
		//	decrease remaining disease cubes of COLOR by 1
		//}
	}
	else {
		cout << "There are no more " << color << " disease cubes! Game over!" << endl;
		//todo: handle gameover 
	}
}
