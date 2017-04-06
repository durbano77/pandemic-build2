//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Player.cpp

#include "Player.h"
#include <iostream>
using namespace std;


//CONSTRUCTORS & DESTRUCTORS of Class PLAYER

//Player - Default Constructor
Player::Player(){
    this->playername="";
    playerpawn=nullptr;
    reference_card=nullptr;
    role_card=nullptr;
}


//Player - Constructor
Player::Player(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand){
    playerpawn=ppawn;
    reference_card=refcard;
    role_card=rolecard;
    player_hand=p_hand;
    this->playername="";
}


 Player::Player(Player const& theplayer){
     playername=theplayer.playername;
     playerpawn=theplayer.playerpawn;
 reference_card=theplayer.reference_card;
 role_card=theplayer.role_card;
 player_hand=theplayer.player_hand;
 }


//Player - Destructor
Player::~Player() {
    //player_hand
    for(int i=0;i<player_hand.size();i++){
        delete player_hand[i];
    }
    
    player_hand.clear();
}


//ACCESSORS & MUTATORS for Member Variables of Class PLAYER

Pawn * Player::getPawn() const{
    return playerpawn;
}

void Player::setPawn(Pawn &pw){
    playerpawn=&pw;
}

RefCard * Player::getRefCard() const{
    return reference_card;
}
void Player::setRefCard(RefCard &refc){
    reference_card=&refc;
}

void Player::printRefCard(){
    if (reference_card != nullptr){reference_card->printCard();}
}

Cards * Player::getRoleCard() const{
    return role_card;
}

void Player::setRoleCard(Cards &rc){
    role_card=&rc;
}

void Player::printRoleCard(){
    if (role_card != nullptr){
        role_card->printCard();}
}


std::string  Player::getPlayerName() const{
    return playername;
}
void Player::printPlayerName() {
	cout << playername;
}


std::vector<PlayerCard*>  Player::getHand() const{
    return player_hand;
}

void Player::setHand(std::vector<PlayerCard*> &ha){
    player_hand=ha;
    Notify(0);
}

void Player::printHand(){
    for(int i=0; i<player_hand.size();i++){
        if (player_hand[i] != nullptr){
            player_hand[i]->printCard();}
    }
}


void Player::draw2pcards(std::vector<PlayerCard*> &plyrdeck){
    
    for(int k=0;k<2;k++){
        player_hand.push_back(plyrdeck.back());
        plyrdeck.pop_back();
        if((player_hand.back())->getCardName()=="Epidemic Card" ){
            Notify(3); //Notify EpidemicCard;
             //insert function triggers Epidemic Event
            player_hand.pop_back(); //remove this epidemic card from player hand
        };
        
    }
    Notify(4); //display pawn info to identify the player
    Notify(1); //display hand
    
    if(player_hand.size()>7){
        discardCards();
    }

}

void Player::discardCards(){
    //Player chooses which cards to discard
    
        int handsize=static_cast<int>(player_hand.size());
        while(handsize>7){
            
            Notify(2); //Notify DiscardHand
            
            int cardnb=handsize+2; //cardnb < handsize
            std::cout<<"Discard one card."<<std::endl;
            //std::cin>>cardnb;
            while (cardnb < 1 || cardnb > handsize) {
                std::cout << "Enter a valid number from 1 to "<< handsize << ":";
                std::cin >> cardnb;
            }
            
            if(cardnb>=0 && cardnb<=handsize){
                string cardn= player_hand.at(cardnb-1)->getCardName();
                player_hand.erase(player_hand.begin() + (cardnb-1));
                std::cout<<cardn<<" was succesfully removed"<<std::endl;
            }
            
                //delete player_hand.at(cardnb-1);
            
            handsize=static_cast<int>(player_hand.size());
            
        }
    
    Notify(1);

}

void Player::action(){
}

void Player::buildResearchStation(){
}

void Player::treatDisease(int *remainingDiseaseCubes, bool* isCured, bool* isEradicated){
	//Remove 1 disease cube from player's current city
	//get current city
	Pawn *pawn = this->getPawn();
	City *currentCity = pawn->getPawnCity();
	currentCity->removeCubes();
	
	//Increment the diseasecube count of that color disease by 1
	//get disease color (blue 0, yellow 1, black 2, red 3)
	string dColor = currentCity->getColor();
	int colorIndex;
	if (dColor == "blue") {
		colorIndex = 0;
	}
	else if (dColor == "yellow") {
		colorIndex = 1;
	}
	else if (dColor == "black") {
		colorIndex = 2;
	}
	else {//red
		colorIndex = 3;
	}
	if (remainingDiseaseCubes[colorIndex] < 24) {
		//re-add a disease cube to the "pile" of its color
		remainingDiseaseCubes[colorIndex]++;
	}
	//If this disease color is cured, remove all cubes of that color from player's current city
	int cubesRemoved = 1;
	if (isCured[colorIndex] == true) {
		cubesRemoved = currentCity->getCubes();
		currentCity->removeAllCubes();
		remainingDiseaseCubes[colorIndex] += cubesRemoved;
		if (remainingDiseaseCubes[colorIndex] > 24) {
			remainingDiseaseCubes[colorIndex] = 24;
		}
	}
	//If diseasecube count of that disease is back to 24, and disease is cured, disease is ERADICATED
	if (isCured[colorIndex] == true && remainingDiseaseCubes[colorIndex] == 24) {
		isEradicated[colorIndex] == true;
		//TODO: if eradicated, no new cubes are placed when infecting.
	}
}

void Player::ShareKnowledge(){
}

void Player::discoverCure(){
}

void action();
void buildResearchStation();
//if in same city as their player card, can build a research station there. if all research stations built, remove one from anywhere on the board
void treatDisease();
//remove 1 cube, if disease cured remove all 3 cubes

void ShareKnowledge();
//give the City card that matches the city you are in to another player
//or take the City card that matches the city you are in from another player


void discoverCure();
//"At any research station, discard 5 City cards of the same color from your"
//"hand to cure the disease of that color. Move the diseases cure marker to its"
//"Cure Indicator."
//"If no cubes of this color are on the board, this disease is now eradicated."
//"Flip its cure marker from its vial side to its  side"



//Class Implementations for each RolePlayer : Player
//dispatcher, medic, scientist, researcher, operationsexpert, quarantinespecialist, contingencyplanner

//Dispatcher
Dispatcher::Dispatcher( ){
    Player();
}
Dispatcher::Dispatcher(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{}
Dispatcher::Dispatcher(Dispatcher const& disp){}
Dispatcher::~Dispatcher(){}
void Dispatcher::moveAnyPawn(){}
void Dispatcher::moveAnotherPlayerPawn(){}


//Medic
Medic::Medic(){
    Player();
}
Medic::Medic(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{}
Medic::Medic (Medic const& med){}
Medic::~Medic(){}
void Medic::removeCubesColor(){}
void Medic::curedRemoveCubesColor(){}


//Scientist
Scientist::Scientist(){
    Player();
}
Scientist::Scientist(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{}
Scientist::Scientist (Scientist const& scient){}
Scientist::~Scientist(){}
void Scientist::discoverCure(){} //base method will be overridden

//Researcher
Researcher::Researcher(){
    Player();
}
Researcher::Researcher(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{}
Researcher::Researcher(Researcher const& research){}
Researcher::~Researcher(){}
void Researcher::giveCityCard(){} //argument: Citycard to give


//Operationsexpert
Operationsexpert::Operationsexpert(){
    Player();
}
Operationsexpert::Operationsexpert(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{}
Operationsexpert::Operationsexpert(Operationsexpert const& opexpert){}
Operationsexpert::~Operationsexpert(){}
void Operationsexpert::buildResearchStation(){}
void Operationsexpert::moveResearchstationCity(){}

//Quarantinespecialist::
Quarantinespecialist::Quarantinespecialist(){
    Player();
}
Quarantinespecialist::Quarantinespecialist(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{}
Quarantinespecialist::Quarantinespecialist(Quarantinespecialist const& qspecialist){}
Quarantinespecialist::~Quarantinespecialist(){}
void Quarantinespecialist::preventOutbreaks(){}
void Quarantinespecialist::preventCubes(){}

//Contingencyplanner::
Contingencyplanner::Contingencyplanner(){
    Player();
}
Contingencyplanner::Contingencyplanner(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{}
Contingencyplanner::Contingencyplanner(Contingencyplanner const& cplanner){}
Contingencyplanner::~Contingencyplanner(){}
void Contingencyplanner::takeEventCard(){}

