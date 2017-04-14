//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//RefCard.cpp
#include "RefCard.h"

RefCard::RefCard() {
    Cards::card_name="ACTIONS";
    Cards::card_textfront =
    "Drive/Ferry \n "
    "Move to a city connected by a white line to the one you are in.\n\n"
    "Direct Flight \n "
    "Discard a City card to move to the city named on the card. \n\n"
    "Charter Flight \n "
    "Discard the City card that matches the city you are in to move to any city. \n\n"
    "Shuttle Flight \n "
    "Move from a city with a research station to any other city that has a"
    "research station. \n\n";
    Cards::card_textback=
    "Build a Research Station\n"
    "Discard the City card that matches the city you are in to place a research"
    "station there. Take the research station from the pile next to the board. If all"
    "6 research stations have been built, take a research station from anywhere"
    "on the board.\n\n"
    "Treat Disease \n"
    "Remove 1 disease cube from the city you are in, placing it in the cube"
    "supply next to the board. If this disease color has been cured (see"
    "Discover a Cure below), remove all cubes of that color from the city you"
    "are in. "
    "\nIf the last cube of a cured disease is removed from the board, this disease"
    "is eradicated. Flip its cure marker from its vial side to its  side\n\n"
    "Share Knowledge \n"
    "You can do this action in two ways:"
    "\ngive the City card that matches the city you are in to another player, or"
    "\ntake the City card that matches the city you are in from another player."
    "\nThe other player must also be in the city with you. Both of you need to"
    "agree to do this."
    "\nIf the player who gets the card now has more than 7 cards, that player must"
    "immediately discard a card or play an Event card (see Event Cards on page 7).\n\n"
    "Discover a Cure \n"
    "At any research station, discard 5 City cards of the same color from your"
    "hand to cure the disease of that color. Move the diseases cure marker to its"
    "Cure Indicator."
    "\nIf no cubes of this color are on the board, this disease is now eradicated."
    "Flip its cure marker from its vial side to its  side.\n";
}




