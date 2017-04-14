//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Cards.cpp

#include <stdio.h>
#include <iostream>
#include "Cards.h"

Cards::Cards(){
    card_name="";
    card_textfront="";
    card_textback="";
}

Cards::Cards(std::string cardname, std::string cardtextfront, std::string cardtextback){
    card_name=cardname;
    card_textfront=cardtextfront;
    card_textback=cardtextback;
}

Cards::~Cards(){

}


std::string Cards::getCardName(){
    return card_name;
}

void Cards::setCardName(std::string cardname){
    card_name=cardname;
}
std::string Cards::getCardTextFront(){
    return card_textfront;
}
void Cards::setCardTextFront(std::string cardtextfront){
    card_textfront=cardtextfront;
}
std::string Cards::getCardTextBack(){
    return card_textback;
}
void Cards::setCardTextBack(std::string cardtextback){
    card_textback=cardtextback;
}

void Cards::printCard(){
    std::cout<<"\n\n----------------------------------------"<<std::endl;
    std::cout<<this->getCardName()<<std::endl;
    std::cout<<this->getCardTextFront()<<std::endl;
    std::cout<<this->getCardTextBack()<<std::endl;
    std::cout<<"----------------------------------------\n\n"<<std::endl;
}

void Cards::printCardFront(){
    std::cout<<this->getCardName()<<std::endl;
    std::cout<<this->getCardTextFront()<<std::endl;
}

void Cards::printCardBack(){
    std::cout<<this->getCardName()<<std::endl;
    std::cout<<this->getCardTextBack();
}

