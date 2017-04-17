#pragma once
#ifndef Graph_h
#define Graph_h
#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include "Subject.h"
#include "City.h"


struct vertex {
	//typedef pair<int, vertex*> ve;
	vector<vertex*> adj; //destination vertex
	City* name;
	//Graph g;
	vertex(City* s) : name(s) {}
	vector <City*> getAdjCities()
	{
		vector <City*> cityVector;
		if (this->adj.size() ==0)
		{
			cout << "\n" << name->getCityName() << " has  " << cityVector.size() <<" ciit it is connected to\n\n";
			return cityVector;
		}
		else
		{
		//	cout << "\n City " << name->getCityName() << " connected to: " << endl;
			//vector<vertex*> ::iterator itr = v.begin();
			for (int i = 0; i < adj.size(); i++) {
				cityVector.push_back(adj[i]->name);
			}
		cout << "\n City " << name->getCityName() << " has " << cityVector.size() << " cities it is connected to" << endl;;
			return cityVector;

		}

	}
	virtual ~vertex();
};

class Graph: public Subject
{
protected:
	typedef map<City*, vertex *> cMap;
	//vmap work;
	cMap* cityMap;
	vector <City*> cityInGraph;
public:
	Graph(cMap* citMap);
	Graph(vector<City**>cityVector);
	vector <City*> getCityInGraph();
	void addC(vector<City*>cityVector);
	//Graph(vector<City*>);
	virtual ~Graph();
	//typedef map<string, vertex *> vmap;
	void cityAdjacency(City* c);
	void cityWithAdjacency();
	void cityAndConnection();
	void cityConnection(City* c);
	void showCity();
	void showCityInfo(City* cityname);
	void addCityToGraph(City* ci, vertex* v);
	void printGraph();
	void move(City* f, City* t);
	void addedge(City* from, City* to);
	void getCityEdge(City*);
	void createMap(City** citiesarr, vertex** vertexarr);
	vector<City*> adjoiningCities(City*);
	bool operator==(City&);
    


};


#endif 
