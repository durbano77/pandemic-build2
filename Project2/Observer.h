//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Observer.h (Abstract class)


#ifndef OBSERVER_H
#define OBSERVER_H
#include <afxwin.h>
#define _AFXDLL

class Observer {
public:
    ~Observer();
    virtual void Update(int o) = 0;  //pure virtual function: must be implemented
//    virtual void UpdateHand() = 0;
//    virtual void UpdateDiscardHand()=0;
//    virtual void UpdateEpidemicCard()=0;
protected:
    Observer();
};
#endif //OBSERVER_H
