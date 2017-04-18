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
#include "Menu.h"
#include "Global.h"


BlueCity* atlantatest=new BlueCity("atlanta", "Atlanta", "", ""); //test city card for player actions

void clearScreen(){
    cout<<"\n\n\nPress enter to continue";
    cin.ignore();
    for(int i = 0; i<100; i++){
        cout << "    " << endl;
    }
}

void initInfectionDeck() {
    infectiondeck.insert(infectiondeck.end(), infectioncardarr, infectioncardarr + (sizeof(infectioncardarr) / sizeof(infectioncardarr[0])));
    
    shuffle(infectiondeck.begin(), infectiondeck.end(), std::default_random_engine(std::random_device()()));
}
void setInitPlayerDeck(){
    playerdeck.insert(playerdeck.end(), citycardarr, citycardarr+(sizeof(citycardarr)/sizeof(citycardarr[0])));
    playerdeck.insert(playerdeck.end(), eventcardarr, eventcardarr+(sizeof(eventcardarr)/sizeof(eventcardarr[0])));
    
    shuffle(playerdeck.begin(), playerdeck.end(), std::default_random_engine(std::random_device()()));
    
    playerdeck.push_back(atlantatest);

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
    }
    
    
    // FOR EACH PAWN (PLAYER)...
    // Distributes actual role with switch(rndnumber)
    // Call corresponding Role Player constructor
    // then distribute PlayerCard's with drawpcards
    // arrayOfPlayer[i] points to the role player object created to keep track of all players
    // creates playerview object (observer) for each player (subject)
    // Then NOTIFY();
    for (int i = 0; i < numPlayers; i++) {
        cout<<"               PLAYER "<<i+1<<endl;
        switch(arrcheck[i]){
            case 0:{
                Dispatcher* dispatcher = new Dispatcher(&dispatcherpawn, &referencecards[i], &dispatchercard1, dispatcherhand);
                dispatcher->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
                arrayofPlayerViews.push_back(new PlayerView(dispatcher));
                arrayofPlayers.push_back(dispatcher);
                break;
            }
            case 1:{
                Medic* medic=new Medic(&medicpawn, &referencecards[i], &mediccard1, medichand);
                medic->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
				arrayofPlayerViews.push_back(new PlayerView(medic));
                arrayofPlayers.push_back(medic);
                break;
            }
            case 2:{
                Scientist* scientist=new Scientist(&scientistpawn, &referencecards[i], &scientistcard1, scientisthand);
                scientist->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
				arrayofPlayerViews.push_back(new PlayerView(scientist));
                arrayofPlayers.push_back(scientist);
                break;
            }
            case 3:{
                Researcher* researcher=new Researcher(&researcherpawn, &referencecards[i], &researchercard1, researcherhand);
                researcher->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
				arrayofPlayerViews.push_back(new PlayerView(researcher));
                arrayofPlayers.push_back(researcher);
                break;
            }
            case 4:{
                Operationsexpert* operationsexpert=new Operationsexpert(&operationsexpertpawn, &referencecards[i], &operationsexpertcard1, operationsexperthand);
                operationsexpert->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
				arrayofPlayerViews.push_back(new PlayerView(operationsexpert));
                arrayofPlayers.push_back(operationsexpert);
                break;
            }
            case 5:{
                Quarantinespecialist* quarantinespecialist=new Quarantinespecialist(&quarantinespecialistpawn, &referencecards[i], &quarantinespecialistcard1, quarantinespecialisthand);
               quarantinespecialist->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
				arrayofPlayerViews.push_back(new PlayerView(quarantinespecialist));
                arrayofPlayers.push_back(quarantinespecialist);
                break;
            }
            case 6:{
                Contingencyplanner* contingencyplanner=new Contingencyplanner(&contingencyplannerpawn, &referencecards[i], &contingencyplannercard1,  contingencyplannerhand);
                contingencyplanner->drawpcards(4, playerdeck, discardpile,eventCardsAvail);
				arrayofPlayerViews.push_back(new PlayerView(contingencyplanner));
                arrayofPlayers.push_back(contingencyplanner);
                break;
            }
            default:{
                break;
            }
        }
        arrayofPlayers[i]->Notify(0);
        clearScreen();
    }
    
    cout<<"Roles are now distributed to the "<< numPlayers<<" players\n"<<endl;
    cout<<"Turns will begin where each player performs 4 actions, draws 2 cards from the player cards pile and infect cities\n"<<endl;
    cout<<"Order between players: "<<endl;
    for(int i=0;i<numPlayers;i++){
        std::cout<<i+1<<" - "<<arrayofPlayers[i]->getPlayerName() <<std::endl;
    
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
				//curr_inf->Infect(remainingDiseaseCubes, isEradicated, curr_inf->getCity(), color);
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
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (pCount < 2 || pCount > 4) {
		cout << "Please enter a valid number of players (2-4):";
		cin >> pCount;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	//clear the screen
	system("cls");
	return pCount;
}

void turn(Player* p){
    Menu m(p, arrayofPlayers, &discardpile);
    vertex* x;
    
    while(m.getnbactionstodo()>0){
        x = cityMap.at(p->getPawn()->getPawnCity()); //update adj cities
        vector <City*> adjCities = x->getAdjCities();
        m.setAdjCity(adjCities);
        
        m.doMenu(cityarr, remainingDiseaseCubes, isCured, isEradicated);
        clearScreen();
    }

    p->drawpcards(2, playerdeck, discardpile,eventCardsAvail);
   
    
    
 //INFECTION
//    for(int i=0;i<infectionRate;i++){
//        InfectionCard* ic=infectiondeck.back();
//        
//       // Notify(6);   display infection card and infection
//        ic->printCard();
//        
//        string iccolor=ic->getColor();
//        
//        for(int j=0;j<48;j++){
//            //c[j].getCityName();
//        }
//        
//       //HERE:
//		//ic->Infect(remainingDiseaseCubes, isEradicated, ic->getCity(), iccolor);
//        
//        
//        infectiondeck.pop_back();
//    }
//    

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

	initialInfection();
    
    createRoles();
    
    addEpCardsPlayerDeck();
    
    
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
    
    
}

int main(){
    
    //  Graph myGraph;
   // GraphView gView(&myGraph);
  //  myGraph.createMap(cityarr);
    cout<<"PANDEMIC"<<endl;
    cout<<"\n\n\n"<<endl;
    cout<<"\n\n\nPress enter to start a new game";
    cin.ignore();
    
    cout<<"Initializing the map... "<<endl;
    myGraph->createMap(cityarr, vertexarr);
    myGraph->cityAndConnection();
    cin.clear(); // reset any error flags
    clearScreen();
    
    initGame();
    clearScreen();
 

    //while  -> do this until the game ends!
    for(int i=0;i<numPlayers;i++){
        turn(arrayofPlayers[i]);
    }
    

    
    
//    vector <City*> vtest = vertexarr[0]->getAdjCities();
//    vector <City*> vtest1 = vertexarr[1]->getAdjCities();
//    
//    //vertex_Atlanta->getAdjCities();
//    city_Atlanta->addResearchStation();
//    city_Bagdad->addResearchStation();



    



   // Save savestate = Save();
   // savestate.save_game();
   // system("pause");
   // savestate.load_game();
    endGame();
    
}
