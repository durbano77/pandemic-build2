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
    color="";
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



void City::print()
{
    cout<<"----------------------------------------"<<endl;
    cout <<"City: "<< cityname <<" (" <<color<<") " << endl;
	cout <<cubes << " infection cubes in city " <<endl;
    if(researchstation){cout<<"City has a research station"<<endl;}
    else{cout<<"City does not have a research station"<<endl;}
    cout<<"----------------------------------------"<<endl;

}

