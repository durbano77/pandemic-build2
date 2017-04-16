//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//EventCard.cpp

#include "EventCard.h"

using namespace std;

EventCard::EventCard(){
    Cards();
}

EventCard::EventCard(CString title, CString cardtextfront, CString cardtextback) {
    Cards(title, cardtextfront, cardtextback);
}

EventCard::~EventCard(){
}


//All 5 event cards


Airlift::Airlift(){
    card_name="Event card: Airlift";
    card_textfront =
        "";
    card_textback="";

}

Airlift::~Airlift(){

}

void Airlift::EventAction(){
}





OneQuietNight::OneQuietNight(){
    card_name="Event card: One Quiet Night";
    card_textfront =
    "";
    card_textback="";

}

OneQuietNight::~OneQuietNight(){

}


void OneQuietNight::EventAction(){

}




GovernmentGrant::GovernmentGrant(){
    card_name="Event card: Government Grant";
    card_textfront =
    "";
    card_textback="";
    
}

GovernmentGrant::~GovernmentGrant(){
    
}


void GovernmentGrant::EventAction(){
    
}




ResilientPopulation::ResilientPopulation(){
    card_name="Event card: Resilient Population";
    card_textfront =
    "";
    card_textback="";
    
}

ResilientPopulation::~ResilientPopulation(){
    
}


void ResilientPopulation::EventAction(){
    
}





Forecast::Forecast(){
    card_name="Event card: Forecast";
    card_textfront =
    "";
    card_textback="";
    
}

Forecast::~Forecast(){
    
}


void Forecast::EventAction(){
    
}
