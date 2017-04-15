//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//PlayerCard.cpp

#include "PlayerCard.h"

PlayerCard::PlayerCard() {
    // PlayerCard (events, cities, epidemics)
    Cards();
    
}

PlayerCard::PlayerCard(std::string title, std::string cardtextfront, std::string cardtextback){
    Cards(title, cardtextfront, cardtextback);
}

void PlayerCard::EventAction(){

}
