//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Subject.cpp  (Abstract class)

#include "Subject.h"

Subject::Subject(){
    std::vector<Observer*>  listobservers;
}
Subject::~Subject(){
    //delete listobservers; (?)
}
void Subject::Attach(Observer* observer){
    listobservers.push_back(observer);
};
void Subject::Detach(Observer* observer){
    listobservers.erase(std::remove(listobservers.begin(), listobservers.end(), observer), listobservers.end());
};
void Subject::Notify(int n){
    std::vector<Observer *>::iterator i = listobservers.begin();
    for (; i !=listobservers.end(); ++i)
        (*i)->Update(n);
};
//void Subject::NotifyHand(){
//    std::vector<Observer *>::iterator i = listobservers.begin();
//    for (; i !=listobservers.end(); ++i)
//        (*i)->UpdateHand();
//}
//void Subject::NotifyDiscardHand(){
//    std::vector<Observer *>::iterator i = listobservers.begin();
//    for (; i !=listobservers.end(); ++i)
//        (*i)->UpdateDiscardHand();
//}
//void Subject::NotifyEpidemicCard( ){
//    std::vector<Observer *>::iterator i = listobservers.begin();
//    for (; i !=listobservers.end(); ++i)
//        (*i)->UpdateEpidemicCard();
//}
