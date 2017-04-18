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
#include "afx.h"
#include <vector>
#include <string>
//#include "Pawn.h"
using namespace std;

class City : public CObject
{
public:
	City();
	City(string thecityname, string thecolor);
	
	~City();

    string getCityName();
    string getColor();
    int getCubes();
    bool getResearchStation();

    
    void addCubes();
    void removeCubes();
    void add3Cubes();
    void removeAllCubes();
    void addResearchStation();
    void removeResearchStation();

    void print();
	bool operator== (City* other) {
		return (getCityName() == other->getCityName());
	};

	DECLARE_SERIAL(City);
	void Serialize(CArchive& archive);
	
private:
    string cityname;
    string color;
 
    int cubes;
    bool researchstation;

   
};

#endif
