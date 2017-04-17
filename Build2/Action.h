//
//  Action.hpp
//  Build2
//
//  Created by Jasmine Leblond-Chartrand on 2017-04-16.
//  Copyright © 2017 Jasmine Leblond-Chartrand. All rights reserved.
//

#ifndef Action_h
#define Action_h

#include "GraphView.h"
#include "PlayerView.h"

#include <stdio.h>

class Action{
public:
    virtual ~Action()=0;
    virtual void doAction()=0;
};

//Player
class Drive : public Action{
public:
    Drive();
    Drive(vector<City*> cVec); //vector of vertex (adj cities)
    ~Drive();
    void doAction();
};


class DirectFlight : public Action{
public:
    DirectFlight();
    DirectFlight(City* acities[]);
    ~DirectFlight();
    void doAction();
};


class CharterFlight: public Action{
public:
    CharterFlight();
    CharterFlight(City* acities[]);
    ~CharterFlight();
    void doAction();
};

class ShuttleFlight: public Action{
public:
    ShuttleFlight();
    ShuttleFlight(City* acities[]);
    ~ShuttleFlight();
    void doAction();
};

class BuildResearchStation: public Action{
public:
    BuildResearchStation();
    BuildResearchStation(std::vector<PlayerCard*> *discardPile);
    ~BuildResearchStation();
    void doAction();
};


class TreatDisease : public Action{
public:
    TreatDisease();
    TreatDisease(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated);
    ~TreatDisease();
    void doAction();
};

class DiscoverCure : public Action{
public:
    DiscoverCure();
    DiscoverCure(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated);
    ~DiscoverCure();
    void doAction();
};

class ShareKnowledge: public Action{
public:
    ShareKnowledge();
    ShareKnowledge(std::vector<Player*> vectorplayers);
    ~ShareKnowledge();
    void doAction();
};




//Medic: AUTOMATIC
//class RemoveCuredCubes : public Action{
//public:
//    RemoveCuredCubes();
//    RemoveCuredCubes(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated);
//    ~RemoveCuredCubes();
//    void doAction();
//};


//RESEARCHER
//void giveCityCard(); //argument: Citycard to give
//
//DISPATCHER
//void moveAnyPawn();
//void moveAnotherPlayerPawn();
//
//CONTINGENCYPLANNER
//void takeEventCard();





#endif /* Action_h */
