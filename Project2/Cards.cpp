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

using namespace std;

Cards::Cards(){
    card_name="";
    card_textfront="";
    card_textback="";
}

Cards::Cards(CString cardname, CString cardtextfront, CString cardtextback){
    card_name=cardname;
    card_textfront=cardtextfront;
    card_textback=cardtextback;
}

Cards::~Cards(){

}


CString Cards::getCardName(){
    return card_name;
}

void Cards::setCardName(CString cardname){
    card_name=cardname;
}
CString Cards::getCardTextFront(){
    return card_textfront;
}
void Cards::setCardTextFront(CString cardtextfront){
    card_textfront=cardtextfront;
}
CString Cards::getCardTextBack(){
    return card_textback;
}
void Cards::setCardTextBack(CString cardtextback){
    card_textback=cardtextback;
}

void Cards::printCard(){
    cout<<"\n\n----------------------------------------"<<endl;
    cout<<this->getCardName()<<endl;
    cout<<this->getCardTextFront()<<endl;
    cout<<this->getCardTextBack()<<endl;
    cout<<"----------------------------------------\n\n"<<endl;
}

void Cards::printCardFront(){
    cout<<this->getCardName()<<endl;
    cout<<this->getCardTextFront()<<endl;
}

void Cards::printCardBack(){
    cout<<this->getCardName()<<endl;
    cout<<this->getCardTextBack();
}

