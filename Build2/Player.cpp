//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Player.cpp

#include "Player.h"
#include <iostream>
#include <typeinfo>
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


std::vector<PlayerCard*>  Player::getHand(){
    return player_hand;
}

void Player::addCardtoHand(PlayerCard* pc){
    player_hand.push_back(pc);
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


void Player::drawpcards(int nbcardsdraw, std::vector<PlayerCard*> &plyrdeck, std::vector<PlayerCard*> &discardpile, std::vector<PlayerCard*> &eventCardsAvail){
    
    Notify(4); //display pawn info to identify the player
    for(int k=0;k<nbcardsdraw;k++){
        if(plyrdeck.back()!=nullptr){
            std::string s1=plyrdeck.back()->getCardName();
            std::string s2="Event";
            if(s1=="Epidemic Card" ){
                Notify(3); //Notify EpidemicCard;
                //insert function triggers Epidemic Event
            }
            else if(s1.std::string::find(s2) != std::string::npos){
                eventCardsAvail.push_back(plyrdeck.back());
                player_hand.push_back(plyrdeck.back());
                //Notify( );
                //note: eventcard is pushed to a vector of event cards that can be played anytime
                //todo: when an eventcard is used by a player, discard it to the playercard discardpile
            }
            else{ //if it's not an epidemic card nor an event card, add it to player hand
                player_hand.push_back(plyrdeck.back());
            }
            plyrdeck.pop_back();
        }
        else{
            std::cout<<"ERR: player deck last card nullptr"<<std::endl;
        }
    }
   Notify(1); //display hand
    
    //Display all the event cards in the eventCardsAvail vector
//    if(eventCardsAvail.size()>0){
//        for(int j=0;j<eventCardsAvail.size();j++){
//            eventCardsAvail[j]->printCard();
//        }
//    }
    
       
    if(player_hand.size()>7){
        discardCards();
    }

}




void Player::discardCards(){
    
        int handsize=static_cast<int>(player_hand.size());
        while(handsize>7){
            
            Notify(2); //Notify DiscardHand
            
            int cardnb=handsize+2; //cardnb < handsize
            std::cout<<"Discard one card.";
            while (cardnb < 1 || cardnb > handsize) {
                std::cout << "Enter a valid number from 1 to "<< handsize << ":";
                std::cin >> cardnb;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            if(cardnb>=0 && cardnb<=handsize){
                string cardn= player_hand.at(cardnb-1)->getCardName();
                delete player_hand.at(cardnb-1);
                player_hand.erase(player_hand.begin() + (cardnb-1));
                std::cout<<cardn<<" was succesfully removed"<<std::endl;
            }
            
            
            
            handsize=static_cast<int>(player_hand.size());
            
        }
    
    Notify(1);

}

void Player::action(){
}

void Player::DirectFlight(City* acities[]){
    string currentcity=this->getPawn()->getPawnCity()->getCityName();
    for(int i=0;i<player_hand.size();i++){
        if(currentcity==player_hand[i]->getCardName()){
            int citychoice=0;
            std::cout<<"Direct Flight - What city do you want to fly to?"<<std::endl;
            for(int k=0; k<48;k++){
                std::cout<<"["<<k+1<<"] "<<acities[k]->getCityName()<<std::endl;
            }
            
            while(citychoice>48 || citychoice<1)
            {
                std::cout<<"Enter the number corresponding to the city you want to fly to: "<<std::endl;
                std::cin>>citychoice;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            
            string stringcity=acities[citychoice-1]->getCityName();
            this->getPawn()->setPawnCityString(stringcity, acities);
            
            delete player_hand[i];
            player_hand.erase(player_hand.begin() + (i));
        }
        
    }
    
    
    
}

void Player::CharterFlight(City* acities[]){
    
    std::cout<<"Charter Flight - What city do you want to fly to?"<<std::endl;
    std::cout<<"You can choose any city corresponding to one of your city cards in your hand."<<std::endl;
    for(int i=0;i<player_hand.size();i++){
        std::cout<<"["<<i+1<<"] " <<player_hand[i]->getCardName()<<std::endl;
    }
    int choice=0;
    
    while( choice>player_hand.size() || choice<1)
    {
        std::cout<<"Enter the number corresponding to the city you want to fly to: "<<std::endl;
        std::cin>>choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    
    
    
    string choicecity=player_hand[choice-1]->getCardName();
    this->getPawn()->setPawnCityString(choicecity, acities);
    
    delete player_hand[choice-1];
    player_hand.erase(player_hand.begin() + (choice-1));
    
    
}


//onlt to move to city with research station
/*void Player::shuttleFlight( vector<City*> citVec){
	vector<City*> cityWithResearchStation;
	int cityNum;
	for (int i = 0; i < citVec.size(); i++) {
		if (citVec[i]->getResearchStation())
		{
			
			cityWithResearchStation.push_back(citVec[i]);
		}
		
	}
	cout << "\n\n # of city with research station :  " << cityWithResearchStation.size()<<endl;
	
	if (cityWithResearchStation.size() > 0)
	{
		cout << "these are these cities with researchStation" << endl;
		for (int i = 0; i < cityWithResearchStation.size(); i++) {
			cout << i + 1 << " " << cityWithResearchStation[i]->getCityName() << endl;

		}
		
		do{
			cout << "enter the number  the city # you want to go to\n";
			cin >> cityNum; 
			while (cin.fail()) 
			{ 
				cout << "Integer wanted \n";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			    //return; 
			}
			
		} while (cityNum <0 || cityNum > cityWithResearchStation.size() );
		
		playerpawn->setPawnCity(cityWithResearchStation[cityNum-1]);
		cout << "players new city is: "<< playerpawn->getPawnCity()->getCityName()<<endl;

　
	}
	else
	{
		cout << "no cities with research station" << endl;
	}
	
	
	
}


void Player::buildResearchStation(vector<PlayerCard*> *discardPile){

	for (unsigned i = 0; i < player_hand.size(); i++)
	{
		if (playerpawn->getPawnCity()->getCityName() == (player_hand[i])->getCardName())

		{			

				discardPile->push_back(player_hand[i]);
				player_hand.erase(player_hand.begin() + i);
				playerpawn->getPawnCity()->addResearchStation();
				playerpawn->getPawnCity()->print();
				
				return;
		}
		
	}
	
	
}*/
void Player::buildResearchStation()
{}
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
		isEradicated[colorIndex] = true;
		//TODO: if eradicated, no new cubes are placed when infecting.
	}
}

void Player::ShareKnowledge(std::vector<Player*> vectorplayers){
//give the City card that matches the city you are in to another player
//or take the City card that matches the city you are in from another player

    City* cityplayer=this->getPawn()->getPawnCity();
    
    for(int i=0;i<vectorplayers.size();i++){
        City* cityotherplayer = vectorplayers[i]->getPawn()->getPawnCity();
        
        if(cityotherplayer==cityplayer && this!=vectorplayers[i]){
            //this player and another one are in the same city/they're not the same player
            //checking if one of them has the corresponding city card
            string cname = cityplayer->getCityName();
            
            //checks if the current player has the matching card in their hand
            int phs=player_hand.size();
            for(int j=0; j<phs;j++){
                if(player_hand[j]->getCardName()==cname){
                    Notify(4); //display pawn info
                    //trigger event matching cards
                    std::cout<< "You have the City card '"<<cname<<"' that matches the city you are in."<<std::endl;
                    char response='a';
                    do
                    {
                        std::cout<< "Do you want to give it to "<< vectorplayers[i]->getPlayerName()<<"? [y/n]"<<std::endl;
                        std::cin >> response;
                    }
                    while( !std::cin.fail() && response!='y' && response!='n' && response!='Y' && response!='N' );
                    
                    if(response=='y' || response=='Y'){
                        vectorplayers[i]->addCardtoHand(player_hand[j]);
                        delete player_hand[j];
                        player_hand.erase(player_hand.begin() + (j));
                        phs=player_hand.size(); //change size
                        std::cout<<"City card: "<<cname<<" was successfully given to "<<vectorplayers[i]->getPlayerName()<<std::endl;
                    }
                    else{
                        //player doesnt want to give the city card
                    }
                        
                }
             //phs=player_hand.size();
            }//for
            
            //now, compare the inverse [checks if other player has the matching card in their hand]
            int phs2=vectorplayers[i]->getHand().size();
            for(int k=0; k<phs2;k++){
                std::vector<PlayerCard*> otherplayershand =vectorplayers[i]->getHand();
                if(otherplayershand[k]->getCardName()==cname){
                    //trigger event matching cards
                    
//                    std::cout<< vectorplayers[i]->getPlayerName()<< "has the City card '"<<cname<<"' that matches the city you both are in."<<std::endl;
//                    char response='a';
//                    do
//                    {
//                        std::cout<< "Do you want take this card from "<< vectorplayers[i]->getPlayerName()<<"? [y/n]"<<std::endl;
//                        std::cin >> response;
//                    }
//                    while( !std::cin.fail() && response!='y' && response!='n' && response!='Y' && response!='N' );
//                    
//                    if(response=='y' || response=='Y'){
//                        this->addCardtoHand(otherplayershand[k]);
//                        //delete otherplayershand[k];
//                        otherplayershand.erase(otherplayershand.begin() + (k));
//                        phs2=vectorplayers[i]->getHand().size(); //change size
//                        std::cout<<"City card: "<<cname<<" was successfully taken from "<<vectorplayers[i]->getPlayerName()<<std::endl;
//                    }
//                    else{
//                        //player doesnt want to take the city card
//                    }

                    
                }//if
    
                
            }//for
           
        }
        

    }
    
}

void Player::discoverCure(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated){
//At any research station, discard 5 City cards of the same color from your hand to cure the disease of that color.
	//Determine which city cards/color to discard (what color do they have 5 of?)
	int cityColorCount[4] = { 0,0,0,0 };
	int theColor;	//will contain the index of the color to cure
	for (int j = 0; j<player_hand.size(); j++) {
		if (dynamic_cast<BlueCity*>(player_hand[j])) {
			cityColorCount[0]++;
			if (cityColorCount[0] == 5) {
				theColor = 0;
				break;
			}
		}
		else if (dynamic_cast<YellowCity*>(player_hand[j])) {
			cityColorCount[1]++;
			if (cityColorCount[1] == 5) {
				theColor = 1;
				break;
			}
		}
		else if (dynamic_cast<BlackCity*>(player_hand[j])) {
			cityColorCount[2]++;
			if (cityColorCount[2] == 5) {
				theColor = 2;
				break;
			}
		}
		else if (dynamic_cast<RedCity*>(player_hand[j])) {
			cityColorCount[3]++;
			if (cityColorCount[3] == 5) {
				theColor = 3;
				break;
			}
		}
		
	}
//Move the diseases cure marker to its Cure Indicator.
	isCured[theColor] = true;
//	If no cubes of this color are on the board, this disease is now eradicated.
	if (remainingDiseaseCubes[theColor] == 24) {
		isEradicated[theColor] = true;
	}
}


void buildResearchStation();
//if in same city as their player card, can build a research station there. if all research stations built, remove one from anywhere on the board




//Class Implementations for each RolePlayer : Player
//dispatcher, medic, scientist, researcher, operationsexpert, quarantinespecialist, contingencyplanner

//Dispatcher
Dispatcher::Dispatcher( ){
    Player();
}
Dispatcher::Dispatcher(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{playername="Dispatcher";}
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
{playername="Medic";}
Medic::Medic (Medic const& med){}
Medic::~Medic(){}
void Medic::treatDisease(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated) {
	//Remove all disease cubes from player's current city
	//get current city
	Pawn *pawn = this->getPawn();
	City *currentCity = pawn->getPawnCity();
	int cubesRemoved = currentCity->getCubes();
	currentCity->removeAllCubes();

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
	//Increment the diseasecube count of that color disease by however many removed
	remainingDiseaseCubes[colorIndex] += cubesRemoved;

	//If diseasecube count of that disease is back to 24, and disease is cured, disease is ERADICATED
	if (isCured[colorIndex] == true && remainingDiseaseCubes[colorIndex] == 24) {
		isEradicated[colorIndex] = true;
	}
}
void Medic::removeCuredCubes(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated) {
	//Whenever a medic visits a city, any cubes of a CURED DISEASE are automatically removed
	int cityCubes = this->getPawn()->getPawnCity()->getCubes();
	string dColor = this->getPawn()->getPawnCity()->getColor();
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
	if (cityCubes > 0 && isCured[colorIndex] == true) {
		//medic is in a city with disease cubes, and cure exists for the disease
		int cubesRemoved = this->getPawn()->getPawnCity()->getCubes();
		this->getPawn()->getPawnCity()->removeAllCubes();
		//add the removed cubes back to the pile
		remainingDiseaseCubes[colorIndex] += cubesRemoved;

		//If diseasecube count of that disease is back to 24, and disease is cured, disease is ERADICATED
		if (remainingDiseaseCubes[colorIndex] == 24) {
			isEradicated[colorIndex] = true;
		}
	}
}



//Scientist
Scientist::Scientist(){
    Player();
}
Scientist::Scientist(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{playername="Scientist";}
Scientist::Scientist (Scientist const& scient){}
Scientist::~Scientist(){}
void Scientist::discoverCure(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated) {
	//At any research station, discard 4 City cards of the same color from your hand to cure the disease of that color.
	//Determine which city cards/color to discard (what color do they have 4 of?)
	int cityColorCount[4] = { 0,0,0,0 };
	int theColor;	//will contain the index of the color to cure
	for (int j = 0; j<player_hand.size(); j++) {
		if (dynamic_cast<BlueCity*>(player_hand[j])) {
			cityColorCount[0]++;
			if (cityColorCount[0] == 4) {
				theColor = 0;
				break;
			}
		}
		else if (dynamic_cast<YellowCity*>(player_hand[j])) {
			cityColorCount[1]++;
			if (cityColorCount[1] == 4) {
				theColor = 1;
				break;
			}
		}
		else if (dynamic_cast<BlackCity*>(player_hand[j])) {
			cityColorCount[2]++;
			if (cityColorCount[2] == 4) {
				theColor = 2;
				break;
			}
		}
		else if (dynamic_cast<RedCity*>(player_hand[j])) {
			cityColorCount[3]++;
			if (cityColorCount[3] == 4) {
				theColor = 3;
				break;
			}
		}

	}
	//Move the diseases cure marker to its Cure Indicator.
	isCured[theColor] = true;
	//	If no cubes of this color are on the board, this disease is now eradicated.
	if (remainingDiseaseCubes[theColor] == 24) {
		isEradicated[theColor] = true;
	}
}

//Researcher
Researcher::Researcher(){
    Player();
}
Researcher::Researcher(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{playername="Researcher";}
Researcher::Researcher(Researcher const& research){}
Researcher::~Researcher(){}
void Researcher::giveCityCard(){} //argument: Citycard to give


//Operationsexpert
Operationsexpert::Operationsexpert(){
    Player();
}
Operationsexpert::Operationsexpert(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{playername="Operations Expert";}
Operationsexpert::Operationsexpert(Operationsexpert const& opexpert){}
Operationsexpert::~Operationsexpert(){}
void Operationsexpert::buildResearchStation()
{
	
	for (unsigned i = 0; i < player_hand.size(); i++)
	{
		
		
		if (playerpawn->getPawnCity()->getCityName() == (player_hand[i])->getCardName())
		{
			
			//player_hand.erase(player_hand.begin() + i);
			playerpawn->getPawnCity()->addResearchStation();
			playerpawn->getPawnCity()->print();
			return;
		}

	}



}
// moves from a city with researchstation to any city
void Operationsexpert::moveResearchstationCity(){}
/*void Operationsexpert::moveResearchstationCity(City* toCity, std::vector<PlayerCard*> *discardPile)
{
	for (unsigned i = 0; i < player_hand.size(); i++)

	{
		if (toCity->getCityName() == player_hand[i]->getCardName())
		{
		
			discardPile->push_back(player_hand[i]);

			player_hand.erase(player_hand.begin() + i);

			playerpawn->setPawnCity(toCity);

			playerpawn->getPawnCity()->print();

			return;

		}
			
		if (i == player_hand.size() - 1)

		{

			cout << "you dont have the city card of " << toCity->getCityName();

		}
	}


}*/

//Quarantinespecialist::
Quarantinespecialist::Quarantinespecialist(){
    Player();
}
Quarantinespecialist::Quarantinespecialist(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand):
Player(ppawn, refcard, rolecard, p_hand)
{playername="Quarantine Specialist";}
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
{playername="Contingency Planner";}
Contingencyplanner::Contingencyplanner(Contingencyplanner const& cplanner){}
Contingencyplanner::~Contingencyplanner(){}
void Contingencyplanner::takeEventCard(){}

