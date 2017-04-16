//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//PlayerCard.h

#ifndef PLAYERCARD_H_
#define PLAYERCARD_H_

#include "Cards.h"

using namespace std;

class PlayerCard : public Cards
{
private:
    CString playercardname;
public:
    PlayerCard();
    PlayerCard(CString playercardname, CString cardtextfront, CString cardtextback);
    virtual void EventAction();
};

#endif /* PLAYERCARD_H_ */
