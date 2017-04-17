//
//  Menu.h
//  Build2
//
//  Created by Jasmine Leblond-Chartrand on 2017-04-17.
//  Copyright © 2017 Jasmine Leblond-Chartrand. All rights reserved.
//

#ifndef Menu_h
#define Menu_h

#include <stdio.h>

#include "GraphView.h"
#include "PlayerView.h"
#include "Player.h"

//#include "Global.h"


class Menu{
protected:
    Player* p;
    int nbactionsdone=4;
    vector<City*> vcities;
 //  vector<City*> vertex;  //to pass vertex of the city where the player is
    std::vector<Player*> vectorplayers;
    std::vector<PlayerCard*> *discardPile;
    
    std::vector<int> possible;

    
public:
    Menu();
    Menu(Player* p, vector<City*> &vc, std::vector<Player*> &vectorplayer,  std::vector<PlayerCard*> *dPile);
    virtual ~Menu();
    void setPlayer(Player* pl);
    Player* getPlayer();
    
    int options(int choice);
    void displayMenu(City* acities[]);
    void doAction(int a, City* acities[]);

};

#endif /* Menu_h */
