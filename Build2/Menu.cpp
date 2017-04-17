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





//int Menu::options(int choice){
//    int value=0;
//    switch(choice){
//        case 1:
//            break;
//        case 2:
//            break;
//        case 3:
//            break;
//        default:
//            ;
//    
//    
//    }
//    
//
//    return value;
//
//}

void Menu::displayMenu(City* acities[]){
    std::cout<<"**********MENU**********"<<std::endl;
    std::cout<<"Select one of the following options:"<<std::endl;
    

    
   std::cout<<"[1] Action Drive"<<std::endl;
//    if(!p->drive(vertex, false)){
//        std::cout<<"This option is not available to you right now"<<std::endl;
//    }
    std::cout<<std::endl;
    
    std::cout<<"[2] Action Direct Flight"<<std::endl;
    if(!p->directFlight(acities, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }
     std::cout<<std::endl;
    std::cout<<"[3] Action Charter Flight"<<std::endl;
    if(!p->charterFlight(acities, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }
     std::cout<<std::endl;
    std::cout<<"[4] Action Shuttle Flight"<<std::endl;
    if(!p->shuttleFlight(acities, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }
    
    std::cout<<std::endl;
    std::cout<<"[5] Action Build a Research Station"<<std::endl;
    if(!p->buildResearchStation(discardPile, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"[6] Action Treat Disease"<<std::endl;
//    if(!p->   (  , false)){
//        
//    }
    std::cout<<std::endl;
    std::cout<<"[7] Action Share Knowledge"<<std::endl;
    if(!p->shareKnowledge(vectorplayers, false)){
        std::cout<<"This option is not available to you right now"<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"[8] Action Discover a Cure"<<std::endl;
    //    if(!p->   (  , false)){
    //
    //    }
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
}
