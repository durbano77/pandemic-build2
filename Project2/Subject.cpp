//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Subject.cpp  (Abstract class)

#include "Subject.h"

using namespace std;

Subject::Subject(){
    vector<Observer*>  listobservers;
}
Subject::~Subject(){
    //delete listobservers; (?)
}
void Subject::Attach(Observer* observer){
    listobservers.push_back(observer);
};
void Subject::Detach(Observer* observer){
    listobservers.erase(remove(listobservers.begin(), listobservers.end(), observer), listobservers.end());
};
void Subject::Notify(int n){
    vector<Observer *>::iterator i = listobservers.begin();
    for (; i !=listobservers.end(); ++i)
        (*i)->Update(n);
};
//void Subject::NotifyHand(){
//    vector<Observer *>::iterator i = listobservers.begin();
//    for (; i !=listobservers.end(); ++i)
//        (*i)->UpdateHand();
//}
//void Subject::NotifyDiscardHand(){
//    vector<Observer *>::iterator i = listobservers.begin();
//    for (; i !=listobservers.end(); ++i)
//        (*i)->UpdateDiscardHand();
//}
//void Subject::NotifyEpidemicCard( ){
//    vector<Observer *>::iterator i = listobservers.begin();
//    for (; i !=listobservers.end(); ++i)
//        (*i)->UpdateEpidemicCard();
//}
