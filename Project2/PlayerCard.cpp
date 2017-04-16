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

PlayerCard::PlayerCard(CString title, CString cardtextfront, CString cardtextback){
    Cards(title, cardtextfront, cardtextback);
}

void PlayerCard::EventAction(){

}
