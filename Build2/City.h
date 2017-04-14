//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//City.h

#ifndef City_h
#define City_h
#include "Cards.h"

#include <vector>
#include <string>
//#include "Pawn.h"
using namespace std;

class City
{
public:
	City();
	City(string thecityname, string thecolor);
	//City(string cityname, string color, CityCard* pcitycard, int cubes, vector<Pawn*> pawnsincity);
	~City();

    string getCityName();
    string getColor();
    int getCubes();
    bool getResearchStation();
    //vector<Pawn*> getPawnsInCity();
    
    void addCubes();
    void removeCubes();
    void add3Cubes();
    void removeAllCubes();
    void addResearchStation();
    void removeResearchStation();
   // void addPawnsToCity(Pawn* pa);
    //void removePawnFromCity(Pawn* pa);
    
    //void printListPlayersInCity();
    void print();

	
private:
    string cityname;
    string color;
    //CityCard* pcitycard;
    int cubes;
    bool researchstation;
    //vector<Pawn*> pawnsincity;
   
};

#endif
