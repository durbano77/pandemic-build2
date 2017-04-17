//
//  Action.cpp
//  Build2
//
//  Created by Jasmine Leblond-Chartrand on 2017-04-16.
//  Copyright © 2017 Jasmine Leblond-Chartrand. All rights reserved.
//

#include "Action.h"

Action::~Action(){}

Drive::Drive(){}
Drive::Drive(vector<City*> cVec){}
Drive::~Drive(){}
void Drive::doAction(){
    std::cout<<"Action: drive/flight"<<std::endl;
}

DirectFlight::DirectFlight(){}
DirectFlight::DirectFlight(City* acities[]){}
DirectFlight::~DirectFlight(){}
void DirectFlight::doAction(){
    std::cout<<"Action: direct/flight"<<std::endl;
}

CharterFlight::CharterFlight(){}
CharterFlight::CharterFlight(City* acities[]){}
CharterFlight::~CharterFlight(){}
void CharterFlight::doAction(){
    std::cout<<"Action: charter/flight"<<std::endl;
}

ShuttleFlight::ShuttleFlight(){}
ShuttleFlight::ShuttleFlight(City* acities[]){}
ShuttleFlight::~ShuttleFlight(){}
void ShuttleFlight::doAction(){
    std::cout<<"Action: shuttle/flight"<<std::endl;
}

BuildResearchStation::BuildResearchStation(){}
BuildResearchStation::BuildResearchStation(std::vector<PlayerCard*> *discardPile){}
BuildResearchStation::~BuildResearchStation(){}
void BuildResearchStation::doAction(){
    std::cout<<"Action: build research station"<<std::endl;
}

TreatDisease::TreatDisease(){}
TreatDisease::TreatDisease(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated){}
TreatDisease::~TreatDisease(){}
void TreatDisease::doAction(){
    std::cout<<"Action: treat disease"<<std::endl;
}

DiscoverCure::DiscoverCure(){}
DiscoverCure::DiscoverCure(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated){}
DiscoverCure::~DiscoverCure(){}
void DiscoverCure::doAction(){
    std::cout<<"Action: discover cure"<<std::endl;
}

ShareKnowledge::ShareKnowledge(){}
ShareKnowledge::ShareKnowledge(std::vector<Player*> vectorplayers){}
ShareKnowledge::~ShareKnowledge(){}
void ShareKnowledge::doAction(){}

