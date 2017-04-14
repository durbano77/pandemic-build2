//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//RoleCard.cpp

#include "RoleCard.h"
RoleCard::RoleCard(){
    Cards();
}

RoleCard::RoleCard(std::string title, std::string cardtextfront, std::string cardtextback) {
    Cards(title, cardtextfront, cardtextback);
}

DispatcherCard::DispatcherCard(){
    card_name="Dispatcher";
    card_textfront =
    "The Dispatcher may, as an action, either:\n"
    "-move any pawn, if its owner agrees, to any city containing another pawn, or\n"
    "-move another players pawn, if its owner agrees, as if it were his own.";
    card_textback="";
}

MedicCard::MedicCard(){
    card_name="Medic";
    card_textfront =
    "The Medic removes all cubes, not 1, of the same color when doing the Treat Disease action.\n"
    "If a disease has been cured, he automatically removes all cubes of that color from a city, \n"
    "simply by entering it or being there. This does not take an action.";
    card_textback="";
}

ScientistCard::ScientistCard(){
    card_name="Scientist";
    card_textfront =
    "The Scientist needs only 4 (not 5) City cards of the same disease color to Discover a Cure for that disease.";
    card_textback="";
}

ResearcherCard::ResearcherCard(){
    card_name="Researcher";
    card_textfront =
    "As an action, the Researcher may give any City card from her hand to another player in the same city as her, "
    "without this card having to match her city. The transfer must be from her hand to the other players hand, "
    "but it can occur on either players turn.";
    card_textback="";
}

OperationsexpertCard::OperationsexpertCard(){
    card_name="Operations Expert";
    card_textfront =
    "The Operations Expert may, as an action, either:"
    "-build a research station in his current city without discarding (or using) a City card, or"
    "-once per turn, move from a research station to any city by discarding any City card.";
    card_textback="";
}

QuarantinespecialistCard::QuarantinespecialistCard(){
    card_name="Quarantine Specialist";
    card_textfront =
    "The Quarantine Specialist prevents both outbreaks and the placement of disease cubes in the city "
    "she is in and all cities connected to that city. She does not affect cubes placed during setup.";
    card_textback="";
}

ContingencyplannerCard::ContingencyplannerCard(){
    card_name="Contingency Planner";
    card_textfront =
    "The Contingency Planner may, as an action, take an Event card from anywhere in the Player Discard Pile "
    "and place it on his Role card. Only 1 Event card can be on his role card at a time. "
    "It does not count against his hand limit.\n"
    "When the Contingency Planner plays the Event card on his role card, remove this Event card from the game "
    "(instead of discarding it).";
    card_textback="";
}
