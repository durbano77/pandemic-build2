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
    std::cout<<"**********MENU**********"<<std::endl;
    std::cout<<"Select one of the following options:"<<std::endl;
    

    
   std::cout<<"[1] Action Drive"<<std::endl;
//    if(!p->drive(vertex, false)){
//        std::cout<<"This option is not available to you right now"<<std::endl;
//    }else{possible.push_back(1);}
    std::cout<<std::endl;
    
    std::cout<<"[2] Action Direct Flight"<<std::endl;
    if(!p->directFlight(acities, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }else{possible.push_back(2);}
     std::cout<<std::endl;
    
    std::cout<<"[3] Action Charter Flight"<<std::endl;
    if(!p->charterFlight(acities, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }else{possible.push_back(3);}
     std::cout<<std::endl;
    
    std::cout<<"[4] Action Shuttle Flight"<<std::endl;
    if(!p->shuttleFlight(acities, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }else{possible.push_back(4);}
    std::cout<<std::endl;
    
    std::cout<<"[5] Action Build a Research Station"<<std::endl;
    if(!p->buildResearchStation(discardPile, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }else{possible.push_back(5);}
    std::cout<<std::endl;
    
    std::cout<<"[6] Action Treat Disease"<<std::endl;
//    if(!p->   (  , false)){
//        
//    }else{possible.push_back(6);}
    std::cout<<std::endl;
    
    std::cout<<"[7] Action Share Knowledge"<<std::endl;
    if(!p->shareKnowledge(vectorplayers, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }else{possible.push_back(7);}
    std::cout<<std::endl;
    
    std::cout<<"[8] Action Discover a Cure"<<std::endl;
    //    if(!p->   (  , false)){
    //
    //    }else{possible.push_back(8);}
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
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(!setofchoices.count(actionchoice)){
            std::cout<<"The number you entered doesn't match one of the possible choices."<<std::endl;
        }
    } while(!setofchoices.count(actionchoice));
    
    
    possible.clear();
    
    return actionchoice;
}

void Menu::doAction(int a, City* acities[]){

    switch(a){
        case 1:
           // p->drive(vertex, true);
            break;
        case 2:
            p->directFlight(acities, true);
             break;
        case 3:
            p->charterFlight(acities, true);
            break;
        case 4:
            p->shuttleFlight(acities, true);
            break;
        case 5:
            p->buildResearchStation(discardPile, true);
            break;
        case 6:
            //treat disease
            break;
        case 7:
            p->shareKnowledge(vectorplayers, true);
            break;
        case 8:
           //discover cure
            break;
        default:
            cout<<"Menu ERROR: Cannot execute player action"<<endl;
    
    }
    
    p->getPawn()->printPawn();
    p->printHandTitles();

}
