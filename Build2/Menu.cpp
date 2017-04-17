//
//  Menu.cpp
//  Build2
//
//  Created by Jasmine Leblond-Chartrand on 2017-04-17.
//  Copyright © 2017 Jasmine Leblond-Chartrand. All rights reserved.
//

#include "Menu.h"

//display menu each time (so it evaluates conditions)

Menu::Menu(){}

Menu::Menu(Player* pl, vector<City*> &vc,  std::vector<Player*> &vectorplayer,  std::vector<PlayerCard*> *dPile){
    this->p=pl;
    this->vcities=vc;

    this->vectorplayers=vectorplayer;
    this->discardPile=dPile;
  
    //cityMap.find(p->getPawn()->getPawnCity())->second;  to be called from main
    
}


Menu::~Menu(){
    p=nullptr;
    delete p;

}



void Menu::setPlayer(Player* pl){
    this->p=pl;

}


Player* Menu::getPlayer(){
    return p;
}

//add options to pick a event card anytime

//display options graph, player, cities

void Menu::doMenu(City* acities[]){

    displayMenu(acities);

    int choice=inChoice();
    
    doAction(choice, acities);

  
}



void Menu::displayMenu(City* acities[]){
    cout.clear();
    
    p->getPawn()->printPawn();
    p->printHandTitles();
    
    std::cout<<"\n\n***************MENU***************"<<std::endl;
    std::cout<<"Select one of the following options:\n\n\n"<<std::endl;
    
    std::cout<<"-----DISPLAY-----\n"<<std::endl;
    std::cout<<p->getPlayerName()<<" information"<<std::endl;
    std::cout<<"[1] Reference card"<<std::endl;
    std::cout<<"[2] Role card"<<std::endl;
    std::cout<<"[3] Player hand\n"<<std::endl;
    
    int a=4;
    std::cout<<"Players information"<<std::endl;
    for(int i=0;i<vectorplayers.size();i++){
        std::cout<<"["<<a<<"] "<<vectorplayers[i]->getPlayerName()<<std::endl;
        a++;
    }
    
    std::cout<<"\nCity information"<<std::endl;
    std::cout<<"["<<a<<"] One city to display"<<std::endl; a++;
    std::cout<<"["<<a<<"] All the cities"<<std::endl; a++;

    std::cout<<"-----ACTIONS-----\n"<<std::endl;
    if(nbactionstodo>0){
        std::cout<<"You can still perform "<<nbactionstodo<<" actions.\n"<<std::endl;
        std::cout<<"["<<a<<"] Drive"<<std::endl; a++;
        //    if(!p->drive(vertex, false)){
        //        std::cout<<"This option is not available to you right now"<<std::endl;
        //    }else{possible.push_back(a);}
        
        
        std::cout<<"["<<a<<"] Direct Flight"<<std::endl; a++;
        if(!p->directFlight(acities, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(a);}
        
        
        std::cout<<"["<<a<<"] Charter Flight"<<std::endl; a++;
        if(!p->charterFlight(acities, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(a);}
        
        
        std::cout<<"["<<a<<"] Shuttle Flight"<<std::endl; a++;
        if(!p->shuttleFlight(acities, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(a);}
        
        
        std::cout<<"["<<a<<"] Build a Research Station"<<std::endl; a++;
        if(!p->buildResearchStation(discardPile, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(a);}
        
        
        std::cout<<"["<<a<<"] Treat Disease"<<std::endl; a++;
        //    if(!p->   (  , false)){
        //
        //    }else{possible.push_back(a);}
        
        
        std::cout<<"["<<a<<"] Share Knowledge"<<std::endl; a++;
        if(!p->shareKnowledge(vectorplayers, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(a);}
        
        
        std::cout<<"["<<a<<"] Discover a Cure"<<std::endl; a++;
        //    if(!p->   (  , false)){
        //
        //    }else{possible.push_back(a);}
    
    
    }
    else{
        std::cout<<"You dont have any actions left.\n"<<std::endl;}
    
//    cout<<"POSSIBLE AFTER ORIGINAL DISPLAY: "<<possible.size();
//    for(int i=0;i<possible.size();i++){
//        cout<<possible[i];
//        
//    }

}

int Menu::inChoice(){
    int actionchoice=0;
    
    
    std::set<int> setofchoices(std::make_move_iterator(possible.begin()),
                               std::make_move_iterator(possible.end()));
    
    do {
        std::cout<<" Enter your choice #: ";
        while(!(std::cin >> actionchoice)) {
            std::cout<<" # of your choice? ";
            std::cout<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(!setofchoices.count(actionchoice)){
            std::cout<<"The number you entered doesn't match one of the possible choices."<<std::endl;
        }
    } while(!setofchoices.count(actionchoice));
    
   
    //possible.clear();
//     cout<<"POSSIBLE AFTER GETTING INCHOICE: "<<possible.size();
//    for(int i=0;i<possible.size();i++){
//        cout<<possible[i];
//    
//    }
    
    return actionchoice;
}

void Menu::doAction(int a, City* acities[]){
    int ai=vectorplayers.size()+4;
    
    if(a==1){  p->printRefCard();}
    else if(a==2){ p->printRoleCard();}
    else if(a==3){p->printHand();}
    
    for(int i=0;i<vectorplayers.size();i++){
        if(a==4+i){
            vectorplayers[i]->getPawn()->printPawn();
            vectorplayers[i]->printRoleCard();
            vectorplayers[i]->printHand();
        }
    }
    
    ai-=1;
    
    if(a==ai+1){/*function to show one city info*/}
    else if(a==ai+2){/*function to show all the cities info*/}
    
    else if(a==ai+3){
        // p->drive(vertex, true);
        nbactionstodo-=1;
    }
    else if(a==ai+4){
         p->directFlight(acities, true);
        nbactionstodo-=1;
    }
    else if(a==ai+5){
        p->charterFlight(acities, true);
        nbactionstodo-=1;
    }
    else if(a==ai+6){
        p->shuttleFlight(acities, true);
        nbactionstodo-=1;
    }
    else if(a==ai+7){
         p->buildResearchStation(discardPile, true);
        nbactionstodo-=1;
    }
    else if(a==ai+8){
        //treat disease
        nbactionstodo-=1;
    }
    else if(a==ai+9){
        p->shareKnowledge(vectorplayers, true);
        nbactionstodo-=1;
    }
    else if(a==ai+10){
        //discover cure
        nbactionstodo-=1;
    }
    
    p->getPawn()->printPawn();
    p->printHandTitles();
    
    doMenu(acities);

}
