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
#include <CString>
//#include "Pawn.h"
using namespace std;

class City : public CObject
{
public:
	City();
	City(CString thecityname, CString thecolor);
	//City(CString cityname, CString color, CityCard* pcitycard, int cubes, vector<Pawn*> pawnsincity);
	~City();

    CString getCityName();
    CString getColor();
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


	DECLARE_SERIAL(City);
	void Serialize(CArchive& archive);

	
private:
    CString cityname;
	CString color;
    //CityCard* pcitycard;
    int cubes;
    bool researchstation;
    //vector<Pawn*> pawnsincity;
   
};

#endif
