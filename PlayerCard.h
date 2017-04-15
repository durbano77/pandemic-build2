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

class PlayerCard : public Cards
{
private:
    std::string playercardname;
public:
    PlayerCard();
    PlayerCard(std::string playercardname, std::string cardtextfront, std::string cardtextback);
    virtual void EventAction();
};

#endif /* PLAYERCARD_H_ */
