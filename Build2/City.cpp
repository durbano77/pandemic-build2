//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//City.cpp

#include "City.h"
#include<iostream>
// namespace std;


City::City()
{
    cityname="";
    //color="";
    //pcitycard=nullptr;
    cubes=0;
    researchstation=false;
}
City::City(string thecityname, string thecolor)
{
    cityname=thecityname;
    cubes=0;
    researchstation=0;
	color = thecolor;
}

//City::City(string cityname, string color, CityCard* pcitycard, int cubes, vector<Pawn*> pawnsincity)
//{
//    cityname=cityname;
//    color=color;
//    pcitycard=pcitycard;
//    cubes=0;
//    researchstation=0;
//    pawnsincity=pawnsincity;
//}


City::~City()
{
   
}

string City::getCityName(){
    if(cityname!="")
        return this->cityname;
    else
        return "ERR: city name is void ";
}

string City::getColor(){
    return color;
}

int City::getCubes(){
    return cubes;
}
bool City::getResearchStation()
{
	return researchstation;
}
//vector<Pawn*> City::getPawnsInCity()
//{
//    return pawnsincity;
//}

void City::addCubes()
{
    cubes++;
}

void City::removeCubes(){
    if(cubes>0)
        cubes--;
    else
        cubes=0;
}

void City::add3Cubes(){
    cubes+=3;
}

void City::removeAllCubes(){
    cubes=0;
}

void City::addResearchStation(){
    researchstation=true;
}

void City::removeResearchStation(){
    researchstation=false;
}

//void City::addPawnsToCity(Pawn* pa)
//{
//    pawnsincity.push_back(pa);
//}

//void City::removePawnFromCity(Pawn* pa){
//    for(int i=0;i<pawnsincity.size();i++){
//        if(pawnsincity[i]==pa)
//            pawnsincity.erase(pawnsincity.begin() + i);
//    }
//    
//}

//void City::printListPlayersInCity(){
//    for(int i=0;i<pawnsincity.size();i++){
//        cout<<pawnsincity[i]->getPawnPlayerName()<<endl;
//    }
//}

void City::print()
{
	//cardColor;
    cout << " City Card: "<< cityname << endl;
//	//RefCard ref = getPlayerInCity();
//    cout << "List of players in city :"<<endl;
//    printListPlayersInCity();

	cout << "the number of infection in city:" << cubes <<endl;

}

