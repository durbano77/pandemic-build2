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


class Menu{
protected:
    Menu();
    Player* p;
    
    virtual ~Menu();
    
public:
    void setPlayer(Player* pl);
    Player* getPlayer();
    
    int options(int choice);
    void displayMenu();
    void setAction(int a);

};

#endif /* Menu_h */
