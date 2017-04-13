//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Cards.h

#ifndef Cards_h
#define Cards_h

#include <string>

using namespace std;

class Cards{
protected:
    std::string card_name;
    std::string card_textfront;
    std::string card_textback;
public:
    Cards();
    Cards(std::string, std::string, std::string);
    virtual ~Cards();
    
    std::string getCardName();
    void setCardName(std::string);
    std::string getCardTextFront();
    void setCardTextFront(std::string);
    std::string getCardTextBack();
    void setCardTextBack(std::string);
    
    void printCard();
    void printCardFront();
    void printCardBack();

	string tester1();
    
};

#endif /* Cards_h */
