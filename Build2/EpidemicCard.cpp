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

void EpidemicCard::EventAction(int *remainingDiseaseCubes, int& infectionRate, vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard) {
    Increase(infectionRate);
    Infect(remainingDiseaseCubes, infectiondeck, infectiondeck_discard);
    Intensify(infectiondeck, infectiondeck_discard);

}

void EpidemicCard::Increase(int& infectionRate){
//Move the infection rate marker foward
	infectionRate++;
}

void EpidemicCard::Infect(int *remainingDiseaseCubes, vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard){
//Draw the bottom cards from the infection deck and put a cube on that city. Discard that card.
	InfectionCard* curr_inf = infectiondeck.back();
	string city = curr_inf->getCardName();
	string color = curr_inf->getCardTextFront();
	//infect the city	
	curr_inf->Infect(remainingDiseaseCubes, city, color);
	//add drawn card to discard pile
	infectiondeck_discard.push_back(curr_inf);
	//remove card from infection deck
	infectiondeck.pop_back();
}

void EpidemicCard::Intensify(vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard){
//Shuffle the cards in the infection discard pile and put them on top of the infection deck
	shuffle(infectiondeck_discard.begin(), infectiondeck_discard.end(), std::default_random_engine(std::random_device()()));
	infectiondeck.insert(infectiondeck.end(), infectiondeck_discard.begin(), infectiondeck_discard.end());

	//clean up discard pile
	// <vector> infectiondeck_discard contains *InfectionCard
	for (int i = 0; i<infectiondeck_discard.size(); i++) {
		infectiondeck_discard[i] = nullptr;
		delete infectiondeck_discard[i];
	}
}
