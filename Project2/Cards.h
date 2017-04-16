//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Cards.h

#ifndef Cards_h
#define Cards_h

#include <CString>
#include <afxwin.h>
#define _AFXDLL

using namespace std;

//for serialization

class Cards : public CObject{
protected:
   CString card_name;
   CString card_textfront;
   CString card_textback;
public:
    Cards();
    Cards(CString, CString, CString);
    virtual ~Cards();
    
    CString getCardName();
    void setCardName(CString);
    CString getCardTextFront();
    void setCardTextFront(CString);
    CString getCardTextBack();
    void setCardTextBack(CString);
    
    void printCard();
    void printCardFront();
    void printCardBack();
    
};

#endif /* Cards_h */
