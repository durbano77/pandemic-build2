//
//  Menu.h
//  Build2
//


#ifndef Menu_h
#define Menu_h

#include <stdio.h>
#include <set>
#include <stdlib.h>

#include "GraphView.h"
#include "PlayerView.h"
#include "Player.h"

//#include "Global.h"


//remaining disease cubes (blue, yellow, black, red)



class Menu{
protected:
    Player* p;
    int nbactionstodo=4;
    vector<City*> adjcities;

    std::vector<Player*> vectorplayers;
    
    
    std::vector<int> possible;

    
public:
    Menu();
    Menu(Player* p, std::vector<Player*> &vectorplayer) ;
    virtual ~Menu();
    
    int getnbactionstodo();
    void setAdjCity(vector<City*> &vc);
    
    void setPlayer(Player* pl);
    Player* getPlayer();
    
    void doMenu(City* acities[], int remainingDiseaseCubes[4], bool isCured[4], bool isEradicated[4], std::vector<PlayerCard*> &eventcardsavail, std::vector<PlayerCard*> *dPile);
    
    void displayMenu(City* acities[], int remainingDiseaseCubes[4], bool isCured[4], bool isEradicated[4], std::vector<PlayerCard*> &eventcardsavail, std::vector<PlayerCard*> *dPile);
    int inChoice();
    void doAction(int a, City* acities[], int remainingDiseaseCubes[4], bool isCured[4], bool isEradicated[4], std::vector<PlayerCard*> &eventcardsavail, std::vector<PlayerCard*> *dPile);
    
    void clearScreen();
    
};

#endif /* Menu_h */
