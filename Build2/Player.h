//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Player.h

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include <vector>
#include <algorithm>

#include "Subject.h"
#include "Pawn.h"

//#include "CardsPawnHeaders.h" (through Subject headers)

class Player : public Subject{
    
protected:
    std::string playername;
    Pawn* playerpawn;
    RefCard* reference_card;
    Cards* role_card;
    std::vector<PlayerCard*> player_hand;
    
public:
    Player();            /* Default Constructor */
    Player(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand); /*Constructor*/
    Player(Player const& theplayer)  ;             /* Copy Constructor */
    virtual ~Player();
    
    //Accessors & Setters for Member Variables
    Pawn * getPawn() const;
    void setPawn(Pawn &pw);
    
    RefCard * getRefCard() const;
    void setRefCard(RefCard &refc);
    void printRefCard();
    
    Cards * getRoleCard() const;
    void setRoleCard(Cards &rc);
    void printRoleCard();
    
    std::string getPlayerName() const;
    void printPlayerName();
    
    std::vector<PlayerCard*>  getHand();
    void addCardtoHand(PlayerCard* pc);
    void setHand(std::vector<PlayerCard*> &ha);
    void printHand();
    
    void drawpcards(int nbcardsdraw, std::vector<PlayerCard*> &plyrdeck, std::vector<PlayerCard*> &discardpile, std::vector<PlayerCard*> &eventCardsAvail);
    void discardCards();
    
    void action();
    void DirectFlight(City* acities[]);
    void CharterFlight(City* acities[]);
    void shuttleFlight( vector<City*> citVec);
 
    
    void buildResearchStation(std::vector<PlayerCard*> *discardPile);

    void treatDisease(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated);
    void ShareKnowledge(std::vector<Player*> vectorplayers);
    virtual void discoverCure(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated);
    
    void moveAnyPawn();
    
};

//Class Declarations for each RolePlayer : Player
//dispatcher, medic, scientist, researcher, operationsexpert, quarantinespecialist, contingencyplanner

class Dispatcher : public Player{
public:
    Dispatcher( );
    Dispatcher(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand);
    Dispatcher(Dispatcher const& disp)  ;
    virtual ~Dispatcher();
    void moveAnyPawn();
    void moveAnotherPlayerPawn();
};

class Medic : public Player{
public:
    Medic();
    Medic(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand);
    Medic (Medic const& med);
    virtual ~Medic();
	void treatDisease(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated);
	void removeCuredCubes(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated);

};

class Scientist : public Player{
public:
    Scientist();
    Scientist(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand);
    Scientist (Scientist const& scient);
    virtual ~Scientist();
    void discoverCure(int* remainingDiseaseCubes, bool* isCured, bool* isEradicated); //base method will be overridden
    
};

class Researcher : public Player{
public:
    Researcher();
    Researcher(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand);
    Researcher(Researcher const& research);
    virtual ~Researcher();
    void giveCityCard(); //argument: Citycard to give
    
};

class Operationsexpert : public Player{
public:
    Operationsexpert();
    Operationsexpert(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand);
    Operationsexpert(Operationsexpert const& opexpert);
    virtual ~Operationsexpert();
    void buildResearchStation();
    void moveResearchstationCity(City* toCity , vector<PlayerCard*> *discardPile);


};


class Quarantinespecialist : public Player{
public:
    Quarantinespecialist();
    Quarantinespecialist(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand);
    Quarantinespecialist(Quarantinespecialist const& qspecialist);
    virtual ~Quarantinespecialist();
    void preventOutbreaks();
    void preventCubes();
    
};

class Contingencyplanner : public Player{
public:
    Contingencyplanner();
    Contingencyplanner(Pawn *ppawn, RefCard *refcard, Cards *rolecard, std::vector<PlayerCard*> p_hand);
    Contingencyplanner(Contingencyplanner const& cplanner);
    virtual ~Contingencyplanner();
    void takeEventCard();
    
};

#endif /* Player_h */
