//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//EventCard.h

#ifndef EventCard_h
#define EventCard_h

#include <stdio.h>
#include <algorithm>
#include "PlayerCard.h"

#endif /* EventCard_h */

class EventCard : public PlayerCard{
public:
    EventCard();
    EventCard(std::string title, std::string cardtextfront, std::string cardtextback);
    ~EventCard();
};

//All 5 event cards

class Airlift : public EventCard{
public:
    Airlift();
    ~Airlift();
    void EventAction();
};

class OneQuietNight : public EventCard{
public:
    OneQuietNight();
    ~OneQuietNight();
    void EventAction();
};

class GovernmentGrant : public EventCard{
public:
    GovernmentGrant();
    ~GovernmentGrant();
    void EventAction();
};

class ResilientPopulation : public EventCard{
public:
    ResilientPopulation();
    ~ResilientPopulation();
    void EventAction();
};

class Forecast : public EventCard{
public:
    Forecast();
    ~Forecast();
    void EventAction();
};
