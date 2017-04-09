//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//EpidemicCard.h

#ifndef EpidemicCard_h
#define EpidemicCard_h

#include <stdio.h>
#include "PlayerCard.h"
#include "InfectionCard.h"

#endif /* EpidemicCard_hp */

class EpidemicCard : public PlayerCard{
public:
    EpidemicCard();
    ~EpidemicCard();
    
    void EventAction(int *remainingDiseaseCubes, bool* isEradicated, int& infectionRate, vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard);
    
    void Increase(int& infectionRate);
	void Infect(int* remainingDiseaseCubes, bool* isEradicated, vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard);
    void Intensify(vector<InfectionCard*>& infectiondeck, vector<InfectionCard*>& infectiondeck_discard);

};


