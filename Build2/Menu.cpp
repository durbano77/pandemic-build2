//
//  Menu.cpp
//  Build2
//
//  Created by Jasmine Leblond-Chartrand on 2017-04-17.
//  Copyright © 2017 Jasmine Leblond-Chartrand. All rights reserved.
//

#include "Menu.h"


Menu::Menu(){}


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

int Menu::options(int choice){
    int value=0;
    switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            ;
    
    
    }

    return value;

}

void Menu::displayMenu(){
    std::cout<<"**********MENU**********"<<std::endl;
    std::cout<<"Select one of the following options:"<<std::endl;
    
    

}

void setAction(int a){


}
