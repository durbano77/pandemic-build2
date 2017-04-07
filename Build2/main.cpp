//**********************************************
//COMP345 BUILD 2
//Winter 2017
//Team Buffalos
//**********************************************
//
//main.cpp

#include <iostream>
#include <ctime>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <algorithm>
#include <random>
#include "GraphView.h"
#include "PlayerView.h"
//#include "CardsHeaders.h" (through PlayerView - Player - Subject - CardsHeaders)
//#include "SaveLoad.h"
#include "Global.h"


//ONLY FOR TEST (TO BE REMOVED)
City* atlantacity = new City("Atlanta", "blue");

void initCities() {
	//vector of city object pointers
	cities.insert(cities.end(), cityarr, cityarr + (sizeof(cityarr) / sizeof(cityarr[0])));
}
//END REMOVE HERE (SO WE KNOW EXACTLY WHERE TO STOP FOR ANY FURTHER TEST CASES WE MAY ADD)


void initInfectionDeck() {
    infectiondeck.insert(infectiondeck.end(), infectioncardarr, infectioncardarr + (sizeof(infectioncardarr) / sizeof(infectioncardarr[0])));
    
    shuffle(infectiondeck.begin(), infectiondeck.end(), std::default_random_engine(std::random_device()()));
}
void setInitPlayerDeck(){
    playerdeck.insert(playerdeck.end(), citycardarr, citycardarr+(sizeof(citycardarr)/sizeof(citycardarr[0])));
    playerdeck.insert(playerdeck.end(), eventcardarr, eventcardarr+(sizeof(eventcardarr)/sizeof(eventcardarr[0])));
    
    //Rnd Shuffle playerdeck
    shuffle(playerdeck.begin(), playerdeck.end(), std::default_random_engine(std::random_device()()));

}

void createRoles(){
    // Method for distributing roles
    srand(static_cast<unsigned int>(time(nullptr)));
    int arrcheck[nbplayers];
    for (int i = 0; i < numPlayers; i++) {
        arrcheck[i] = numPlayers + 2;		// initialize test array elements with values
        // numPlayers + 2  just to make sure that this value is never reached
    }
    
    for (int i = 0; i < numPlayers; i++) {		// Method for giving role (by number)
        bool check;
        int nb;
        do {
            nb = rand() % 6;				// rnd nb goes from 0 to 6
            check = true;
            for (int j = 0; j <= i; j++) {
                if (nb == arrcheck[j]) {
                    check = false;
                    break;
                }
            }
            
        } while(!check);
        arrcheck[i] = nb;
        // std::cout<<arrcheck[i]<<std::endl;    // test method output rand nb
    }
    
    
    // FOR EACH PAWN (PLAYER)...
    // Distributes actual role with switch(rndnumber)
    // Call corresponding Role Player constructor
    // then distribute PlayerCard's from the <vector> playerdeck to the <vector> player hand
    // arrayOfPlayer[i] points to the role player object created to keep track of all players
    // creates playerview object (observer) for each player (subject)
    // Set playercard*'s in player_hand's  - Then NOTIFY();
    for (int i = 0; i < numPlayers; i++) {        
        switch(arrcheck[i]){
            case 0:{
                Pawn dispatcherpawn("pink", atlantacity);
                Dispatcher* dispatcher = new Dispatcher(&dispatcherpawn, &referencecards[i], &dispatchercard1, dispatcherhand);
                //This drawpcards function does not work here for each player.. will be implemented
               // dispatcher->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
                for (int k = 0; k < nbcardsplayer; k++) {
                    dispatcherhand.push_back(playerdeck.back());
                    playerdeck.pop_back();
                }
                arrayofPlayerViews.push_back(new PlayerView(dispatcher));
                dispatcher->setHand(dispatcherhand);
                arrayofPlayers.push_back(dispatcher);
                break;
            }
            case 1:{
                Pawn medicpawn("orange", atlantacity);
                Medic* medic=new Medic(&medicpawn, &referencecards[i], &mediccard1, medichand);
                //medic->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
                for(int k=0;k<nbcardsplayer;k++){
                    medichand.push_back(playerdeck.back());
                    playerdeck.pop_back();
                }
				arrayofPlayerViews.push_back(new PlayerView(medic));
                medic->setHand(medichand);
                arrayofPlayers.push_back(medic);
                break;
            }
            case 2:{
                Pawn scientistpawn("white", atlantacity);
                Scientist* scientist=new Scientist(&scientistpawn, &referencecards[i], &scientistcard1, scientisthand);
//                scientist->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
                for(int k=0;k<nbcardsplayer;k++){
                    scientisthand.push_back(playerdeck.back());
                    playerdeck.pop_back();
                }
				arrayofPlayerViews.push_back(new PlayerView(scientist));
                scientist->setHand(scientisthand);
                arrayofPlayers.push_back(scientist);
                break;
            }
            case 3:{
                Pawn researcherpawn("brown", atlantacity);
                Researcher* researcher=new Researcher(&researcherpawn, &referencecards[i], &researchercard1, researcherhand);
//                researcher->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
                for(int k=0;k<nbcardsplayer;k++){
                    researcherhand.push_back(playerdeck.back());
                    playerdeck.pop_back();
                }
				arrayofPlayerViews.push_back(new PlayerView(researcher));
                researcher->setHand(researcherhand);
                arrayofPlayers.push_back(researcher);
                break;
            }
            case 4:{
                Pawn operationsexpertpawn("palegreen", atlantacity);
                Operationsexpert* operationsexpert=new Operationsexpert(&operationsexpertpawn, &referencecards[i], &operationsexpertcard1, operationsexperthand);
               // operationsexpert->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
                for(int k=0;k<nbcardsplayer;k++){
                    operationsexperthand.push_back(playerdeck.back());
                    playerdeck.pop_back();
                }
				arrayofPlayerViews.push_back(new PlayerView(operationsexpert));
                operationsexpert->setHand(operationsexperthand);
                arrayofPlayers.push_back(operationsexpert);
                break;
            }
            case 5:{
                Pawn quarantinespecialistpawn("darkgreen", atlantacity);
                Quarantinespecialist* quarantinespecialist=new Quarantinespecialist(&quarantinespecialistpawn, &referencecards[i], &quarantinespecialistcard1, quarantinespecialisthand);
              //  quarantinespecialist->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
                for(int k=0;k<nbcardsplayer;k++){
                    quarantinespecialisthand.push_back(playerdeck.back());
                    playerdeck.pop_back();
                }
				arrayofPlayerViews.push_back(new PlayerView(quarantinespecialist));
                quarantinespecialist->setHand(quarantinespecialisthand);
                arrayofPlayers.push_back(quarantinespecialist);
                break;
            }
            case 6:{
                Pawn contingencyplannerpawn("aqua", atlantacity);
                Contingencyplanner* contingencyplanner=new Contingencyplanner(&contingencyplannerpawn, &referencecards[i], &contingencyplannercard1,  contingencyplannerhand);
                //contingencyplanner->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
                for(int k=0;k<nbcardsplayer;k++){
                    contingencyplannerhand.push_back(playerdeck.back());
                    playerdeck.pop_back();
                }
				arrayofPlayerViews.push_back(new PlayerView(contingencyplanner));
                contingencyplanner->setHand(contingencyplannerhand);
                arrayofPlayers.push_back(contingencyplanner);
                break;
            }
            default:{
                break;
            }
        }
    }
    
    
}

void addEpCardsPlayerDeck(){
    //insert Epidemic card after initial PlayerCard's were distributed to players
    playerdeck.insert(playerdeck.end(), epcardarr, epcardarr+(sizeof(epcardarr)/sizeof(epcardarr[0])));
    
    //Rnd Shuffle PlayerDeck
    shuffle(playerdeck.begin(), playerdeck.end(), std::default_random_engine(std::random_device()()));
}
void initialInfection() {
    //draw 3, then 2, then 1 infection cards and infect according to their city and color
    int i = 3;
    while (i >= 1) {
        for (int k = 3; k > 0; k--) {
            //draw infection card from infection deck
            InfectionCard* curr_inf = infectiondeck.back();
            string city = curr_inf->getCardName();
            string color = curr_inf->getCardTextFront();
            //infect the city
            for (int j = 1; j <= i; j++) {
                curr_inf->Infect(remainingDiseaseCubes, curr_inf->getCity(), color);
            }
            //add drawn card to discard pile
            infectiondeck_discard.push_back(curr_inf);
            //remove card from infection deck
            infectiondeck.pop_back();
        }
        i--;
    }
    system("pause");
}
int getPlayerCount() {
	//get the number of players playing, validate, and return as int.
	int pCount;	
	cout << "Please enter the number of players (2-4):";
	cin >> pCount;
	while (pCount < 2 || pCount > 4) {
		cout << "Please enter a valid number of players (2-4):";
		cin >> pCount;
	}
	//clear the screen
	system("cls");
	return pCount;
}

void turn(){
    //check if there is an event card, if so: possibility to use event card
    //action 1
    //if there is an event card, possibility to use event card
    //action 2
    //if there is an event card, possibility to use event card
    //action 3
    //if there is an event card, possibility to use event card
    //action 4
    //if there is an event card, possibility to use event card
    
    //draw 2 cards arrayofPlayers[0]->draw2pcards(playerdeck);
    //(check #2) if there is an event card, if so: possibility to use event card
    
    
 //infection
    for(int i=0;i<infectionRate;i++){
        InfectionCard* ic=infectiondeck.back();
        
       // Notify(6);   display infection card and infection
        ic->printCard();
        
        string iccolor=ic->getColor();
        
        for(int j=0;j<48;j++){
            //c[j].getCityName();
        }
        
       //HERE:
        ic->Infect(remainingDiseaseCubes, "", iccolor);
        
        
        infectiondeck.pop_back();
    }
    

    //infect city 1
    //(check #2) if there is an event card, possibility to use event card
    //infect city 2
    //(check #2) if there is an event card, possibility to use event card
    //infect city 3
}
void initGame(){

	numPlayers = getPlayerCount();
    
    initInfectionDeck();
    
    setInitPlayerDeck();
    
    createRoles();
    
    addEpCardsPlayerDeck();
    
    initialInfection();
    
}

void endGame(){
    
    // <vector> arrayofPlayerViews contains all *PlayerView (1 per player)
    for(int i=0; i<numPlayers;i++){
        arrayofPlayerViews[i]=nullptr;
        delete arrayofPlayerViews[i];
    }
    
    // <vector> arrayofPlayers contains all *Player
    for(int i=0; i<numPlayers;i++){
        arrayofPlayers[i]=nullptr;
        delete arrayofPlayers[i];
    }
    
    // <vector> playerdeck contains *PlayerCard
    for(int i=0;i<playerdeck.size();i++){
        playerdeck[i]=nullptr;
        delete playerdeck[i];
    }
    // <vector> discardpile contains *Playercard
    for(int i=0;i<discardpile.size();i++){
        discardpile[i]=nullptr;
        delete discardpile[i];
    }
    
    // <vector> infectiondeck contains *InfectionCard
    for (int i = 0; i<infectiondeck.size(); i++) {
        infectiondeck[i] = nullptr;
        delete infectiondeck[i];
    }
    // <vector> infectiondeck_discard contains *InfectionCard
    for (int i = 0; i<infectiondeck_discard.size(); i++) {
        infectiondeck_discard[i] = nullptr;
        delete infectiondeck_discard[i];
    }
	// <vector> cities contains *City
	for (int i = 0; i < cities.size(); i++) {
		cities[i] = nullptr;
		delete cities[i];
	}
    
    
}




int main(){
    
    Graph myGraph;
    GraphView gView(&myGraph);

	initCities();
    myGraph.createMap(cityarr);
    //myGraph.printGraph();
    
    cin.clear(); // reset any error flags
   // cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
   // cin.get(); // get one more char from the user

    
    initGame();
    
    //test lines (draw cards)
   arrayofPlayers[0]->drawpcards(2, playerdeck, discardpile,eventCardsAvail);
    arrayofPlayers[0]->drawpcards(2, playerdeck, discardpile,eventCardsAvail);
    arrayofPlayers[0]->drawpcards(2, playerdeck, discardpile,eventCardsAvail);
    arrayofPlayers[0]->drawpcards(2, playerdeck, discardpile,eventCardsAvail);
    arrayofPlayers[0]->drawpcards(2, playerdeck, discardpile,eventCardsAvail);

    
    //arrayofPlayers[0]->ShareKnowledge(arrayofPlayers);
    
   // Save savestate = Save();
   // savestate.save_game();
   // system("pause");
   // savestate.load_game();
    endGame();
    
}
