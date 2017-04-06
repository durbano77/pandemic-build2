//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Subject.h (Abstract class)


#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <algorithm>

#include "Observer.h"

#include "CardsHeaders.h"

class Subject {
public:
    virtual void Attach(Observer* observer);
    virtual void Detach(Observer* observer);
    virtual void Notify(int n);
   // virtual void NotifyHand();
   // virtual void NotifyDiscardHand();
   // virtual void NotifyEpidemicCard();
    Subject();
    ~Subject();
private:
    std::vector<Observer*> listobservers;
};


#endif //SUBJECT_H
