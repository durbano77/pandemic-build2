//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//EpidemicCard.h

#include "EpidemicCard.h"
#include <algorithm>
#include <random>
#include <iostream>

EpidemicCard::EpidemicCard(){
    card_name="Epidemic Card";
    card_textfront =
    "1-INCREASE \n"
    "Move the infection rate marker foward. \n"
    "2-INFECT \n"
    "Draw the bottom cards from the infection deck and put a cube on that city. Discard that card.\n"
    "3-INTENSIFY \n"
    "Shuffle the cards in the infection discard pile and put them on top of the infection deck.";
    card_textback="";
}

EpidemicCard::~EpidemicCard(){

}

void EpidemicCard::EventAction(int *remainingDiseaseCubes, bool* isEradicated, int& infectionRatePos, vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard	) {
    Increase(infectionRatePos);
    Infect(remainingDiseaseCubes, isEradicated, infectiondeck, infectiondeck_discard);
    Intensify(infectiondeck, infectiondeck_discard);

}

void EpidemicCard::Increase(int& infectionRatePos){
//Move the infection rate marker foward
	cout << "Increasing infection rate!" << endl;
	infectionRatePos++;
}

void EpidemicCard::Infect(int* remainingDiseaseCubes, bool* isEradicated, vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard){
//Draw the bottom cards from the infection deck and put a cube on that city. Discard that card.
	InfectionCard* curr_inf = infectiondeck.back();
	City* city = curr_inf->getCity();
	string color = curr_inf->getCardTextFront();
	//infect the city	
	curr_inf->Infect(remainingDiseaseCubes, isEradicated, city, color);
	//add drawn card to discard pile
	infectiondeck_discard.push_back(curr_inf);
	//remove card from infection deck
	infectiondeck.pop_back();
}

void EpidemicCard::Intensify(vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard){
//Shuffle the cards in the infection discard pile and put them on top of the infection deck
	shuffle(infectiondeck_discard.begin(), infectiondeck_discard.end(), std::default_random_engine(std::random_device()()));
	infectiondeck.insert(infectiondeck.end(), infectiondeck_discard.begin(), infectiondeck_discard.end());
	cout << "Intensifying! The infection card discard pile has been shuffled and placed on top of the infection deck." << endl;
	//clean up discard pile
	// <vector> infectiondeck_discard contains *InfectionCard
	int size = infectiondeck_discard.size();
	for (int i = 0; i<size; i++) {
		infectiondeck_discard.pop_back();
	}
}
