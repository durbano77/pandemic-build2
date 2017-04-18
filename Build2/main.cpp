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

void endGame();
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
    int arrcheck[4]; //4: max of players possible.. because array must be fixed
    for (int i = 0; i < 4; i++) {
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
    
    int nbcardstodistribute=0;
    if(numPlayers==4){nbcardstodistribute=2;}
    else if(numPlayers==3){nbcardstodistribute=3;}
    else if(numPlayers==2){nbcardstodistribute=4;}
    else {cout<<"ERROR: number of players is invalid. Cannot distribute cards."<<endl;}
    
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
                dispatcher->drawpcards(nbcardstodistribute, playerdeck, discardpile,eventCardsAvail);
                arrayofPlayerViews.push_back(new PlayerView(dispatcher));
                arrayofPlayers.push_back(dispatcher);
                break;
            }
            case 1:{
                Medic* medic=new Medic(&medicpawn, &referencecards[i], &mediccard1, medichand);
                medic->drawpcards(nbcardstodistribute, playerdeck, discardpile,eventCardsAvail);
                arrayofPlayerViews.push_back(new PlayerView(medic));
                arrayofPlayers.push_back(medic);
                break;
            }
            case 2:{
                Scientist* scientist=new Scientist(&scientistpawn, &referencecards[i], &scientistcard1, scientisthand);
                scientist->drawpcards(nbcardstodistribute, playerdeck, discardpile,eventCardsAvail);
                arrayofPlayerViews.push_back(new PlayerView(scientist));
                arrayofPlayers.push_back(scientist);
                break;
            }
            case 3:{
                Researcher* researcher=new Researcher(&researcherpawn, &referencecards[i], &researchercard1, researcherhand);
                researcher->drawpcards(nbcardstodistribute, playerdeck, discardpile,eventCardsAvail);
                arrayofPlayerViews.push_back(new PlayerView(researcher));
                arrayofPlayers.push_back(researcher);
                break;
            }
            case 4:{
                Operationsexpert* operationsexpert=new Operationsexpert(&operationsexpertpawn, &referencecards[i], &operationsexpertcard1, operationsexperthand);
                operationsexpert->drawpcards(nbcardstodistribute, playerdeck, discardpile,eventCardsAvail);
                arrayofPlayerViews.push_back(new PlayerView(operationsexpert));
                arrayofPlayers.push_back(operationsexpert);
                break;
            }
            case 5:{
                Quarantinespecialist* quarantinespecialist=new Quarantinespecialist(&quarantinespecialistpawn, &referencecards[i], &quarantinespecialistcard1, quarantinespecialisthand);
                quarantinespecialist->drawpcards(nbcardstodistribute, playerdeck, discardpile,eventCardsAvail);
                arrayofPlayerViews.push_back(new PlayerView(quarantinespecialist));
                arrayofPlayers.push_back(quarantinespecialist);
                break;
            }
            case 6:{
                Contingencyplanner* contingencyplanner=new Contingencyplanner(&contingencyplannerpawn, &referencecards[i], &contingencyplannercard1,  contingencyplannerhand);
                contingencyplanner->drawpcards(nbcardstodistribute, playerdeck, discardpile,eventCardsAvail);
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
void Infect(City* theCity, vector <City*> alreadyOutbreak) {
    //takes a city object, and empty vector of city* (on first call. subsequent recursive calls will populate alreadyOutbreak
    //are there enough remaining disease cubes?
    bool enoughCubes = true;
    int colorIndex = 0;
    string color = theCity->getColor();
    if (color == "blue") {
        colorIndex = 0;
        if (remainingDiseaseCubes[0] == 0) {
            enoughCubes = false;
        }
    }
    else if (color == "yellow") {
        colorIndex = 1;
        if (remainingDiseaseCubes[1] == 0) {
            enoughCubes = false;
        }
    }
    else if (color == "black") {
        colorIndex = 2;
        if (remainingDiseaseCubes[2] == 0) {
            enoughCubes = false;
        }
    }
    else if (color == "red") {
        colorIndex = 3;
        if(remainingDiseaseCubes[3] == 0){
            enoughCubes = false;
        }
    }
    
    //Has disease been eradicated?
    if (isEradicated[colorIndex] == true) {
        //skip placing the cubes.
    }
    else {
        //does city to infect have a quarantinespecialist?
        bool quarantineSpec = false;
        for (int i = 0; i < arrayofPlayers.size(); i++) {
            if (theCity == arrayofPlayers[i]->getPawn()->getPawnCity() && arrayofPlayers[i]->getPlayerName() == "Quarantine Specialist") {
                //don't infect city
                quarantineSpec = true;
                cout << "Quarantine Specialist has prevented " << theCity->getCityName() << " from being infected!" << endl;
            }
        }
        if (!quarantineSpec) {
            //place cubes (if enough remain)
            if (enoughCubes) {
                cout << "Infecting " << theCity->getCityName() << " with the " << color << " disease!" << endl;
                //outbreak scenario?
                if (theCity->getCubes() == 3) {
                    // outbreak
                    outbreakMarker++;
                    if (outbreakMarker > 7) {
						for (int i = 0; i<100; i++) {
							cout << "    " << endl;
						}
                        cout << "The outbreak marker is at 8, you lose the game!" << endl;
                        system("pause");
                        endGame();
                    }
                    //in order to prevent a city from having outbreak twice, keep track of those outbreaked
                    alreadyOutbreak.push_back(theCity);
                    vertex* x;
                    x = cityMap.at(theCity);
                    vector <City*> adjCities = x->getAdjCities();
                    //remove any cities in alreadyOutbreak from adjCities to prevent re-outbreak
                    for (City* c : adjCities) {
                        if (std::find(adjCities.begin(), adjCities.end(), c) != adjCities.end()) {
                            //do not infect again
                        }
                        else {
                            Infect(c, alreadyOutbreak);
                        }
                    }
                }
                else {
                    //	increment city's disease counter by 1
                    theCity->addCubes();
                    //	decrease remaining disease cubes of COLOR by 1
                    remainingDiseaseCubes[colorIndex]--;
                }
            }
            else {
				for (int i = 0; i<100; i++) {
					cout << "    " << endl;
				}
                cout << "There are no more " << color << " disease cubes! Game over!" << endl;
                system("pause");
                endGame();
            }
        }
    }
}
void initialInfection() {
    cout<<"---------- Initial Infection ----------\n\n"<<endl;
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
                vector <City*> alreadyOutbreak;
                Infect(curr_inf->getCity(), alreadyOutbreak);
            }
            //add drawn card to discard pile
            infectiondeck_discard.push_back(curr_inf);
            //remove card from infection deck
            infectiondeck.pop_back();
        }
        i--;
    }
   // system("pause");
    clearScreen();
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
    cout<<"Initializing "<<pCount<<" players..."<<endl;
    clearScreen();
   // system("cls");
    return pCount;
}

void turn(Player* p){

    Menu m(p, arrayofPlayers);
    vertex* x;

    std::cout<<"Player: "<<p->getPlayerName()<<std::endl;
    std::cout<<"STEP 1: Do 4 actions"<<std::endl;
     clearScreen();
    while(m.getnbactionstodo()>0){
        x = cityMap.at(p->getPawn()->getPawnCity()); //update adj cities
        vector <City*> adjCities = x->getAdjCities();
        m.setAdjCity(adjCities);
        
        m.doMenu(cityarr, remainingDiseaseCubes, isCured, isEradicated, eventCardsAvail, &discardpile,  valladjcities);
		//check for passive actions from medic
		if (p->getPlayerName() == "Medic") {
			Medic* medic = static_cast<Medic*>(p);
			medic->removeCuredCubes(remainingDiseaseCubes, isCured, isEradicated, true);
		}
        clearScreen();
    }
    std::cout<<"Player: "<<p->getPlayerName()<<std::endl;
    std::cout<<"STEP 2: Drawing 2 player cards"<<std::endl;
     clearScreen();

	 /*			Epidemic Card Handling		*/
	//peek at next 2 cards, to check for epidemic card
	 int epidemicCardsDrawn = 0;	//how many to pop after
	 if (playerdeck.end()[-1]->getCardName() == "Epidemic Card") {		 
		 //top card is epidemic
		 //trigger epidemic
		 p->Notify(3);
		 //increase
		 static_cast<EpidemicCard*>(playerdeck.back())->Increase(infectionRatePos);
		 //infect
		 InfectionCard* currInf = infectiondeck.back();
		 vector <City*> alreadyOutbreak;
		 //add drawn card to discard pile
		 infectiondeck_discard.push_back(currInf);
		 //remove card from infection deck
		 infectiondeck.pop_back();
		 Infect(currInf->getCity(), alreadyOutbreak);
		 //intensify
		 static_cast<EpidemicCard*>(playerdeck.back())->Intensify(infectiondeck, infectiondeck_discard);
		 //pop_back playerdeck
		 playerdeck.pop_back();
		 //epidemic cards drawn++
		 epidemicCardsDrawn++;
		 //check new top of deck
		 if (playerdeck.end()[-1]->getCardName() == "Epidemic Card") {
			 //top card is epidemic
			 //trigger epidemic
			  p->Notify(3);
			 //increase
			 static_cast<EpidemicCard*>(playerdeck.back())->Increase(infectionRatePos);
			 //infect
			 InfectionCard* currInf = infectiondeck.back();
			 //add drawn card to discard pile
			 infectiondeck_discard.push_back(currInf);
			 //remove card from infection deck
			 infectiondeck.pop_back();
			 vector <City*> alreadyOutbreak;
			 Infect(currInf->getCity(), alreadyOutbreak);
			 //intensify
			 static_cast<EpidemicCard*>(playerdeck.back())->Intensify(infectiondeck, infectiondeck_discard);
			 //pop_back playerdeck
			 playerdeck.pop_back();
			 //epidemic cards drawn++
			 epidemicCardsDrawn++;
		 }
	 }
	 //firts card in deck wasn't epidemic, check next
	 else {
		 if (playerdeck.end()[-2]->getCardName() == "Epidemic Card") {
			 //draw top card, since it isnt epidemic
			 p->drawpcards(1, playerdeck, discardpile, eventCardsAvail);
			 epidemicCardsDrawn++;
			 //pop_back playerdeck
			 playerdeck.pop_back();
			 //top card is epidemic
			 p->Notify(3);
			 //trigger epidemic
			 //increase
			 static_cast<EpidemicCard*>(playerdeck.back())->Increase(infectionRatePos);
			 //infect
			 InfectionCard* currInf = infectiondeck.back();
			 vector <City*> alreadyOutbreak;
			 //add drawn card to discard pile
			 infectiondeck_discard.push_back(currInf);
			 //remove card from infection deck
			 infectiondeck.pop_back();
			 Infect(currInf->getCity(), alreadyOutbreak);
			 //intensify
			 static_cast<EpidemicCard*>(playerdeck.back())->Intensify(infectiondeck, infectiondeck_discard);
			 //pop_back playerdeck
			 playerdeck.pop_back();
			 //epidemic cards drawn++
			 epidemicCardsDrawn++;
		 }
	 }	
	 
	//draw however many more cards to make it 2 in total (depends on how many epidemic cards were found)
    p->drawpcards(2-epidemicCardsDrawn, playerdeck, discardpile,eventCardsAvail);
    clearScreen();
    
    std::cout<<"Player: "<<p->getPlayerName()<<std::endl;
    std::cout<<"STEP 3: Infect cities"<<std::endl;
    //Infect
    int infCardsToDraw = infectionRateMarker[infectionRatePos];		//{2,2,2,3,3,4,4}, index determined by infectionRatePos
    for (int i = 0; i < infCardsToDraw; i++) {
        InfectionCard* curr_inf = infectiondeck.back();
        string city = curr_inf->getCardName();
        string color = curr_inf->getCardTextFront();
        //infect the city
        vector <City*> alreadyOutbreak;
        Infect(curr_inf->getCity(), alreadyOutbreak);
        //add drawn card to discard pile
        infectiondeck_discard.push_back(curr_inf);
        //remove card from infection deck
        infectiondeck.pop_back();
    }
    clearScreen();
    
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
    isgameover=true;
    
    cout<<"GAME OVER"<<endl;
    clearScreen();
    
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
    exit(0);
    
    
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
    for(int i=0;i<48;i++){ //filling in vector with all cities' adjacent cities
        valladjcities.push_back((cityMap.at(cityarr[i]))->getAdjCities()); //vector< vector <City*> >
    }
    cin.clear(); // reset any error flags
    clearScreen();
    
    initGame();

    clearScreen();
 
    
    while(!isgameover){
        for(int i=0;i<numPlayers;i++){
            turn(arrayofPlayers[i]);
        }
    }

    
    

    
    
    
    // Save savestate = Save();
    // savestate.save_game();
    // system("pause");
    // savestate.load_game();
    endGame();
    
}
