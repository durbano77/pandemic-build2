#pragma once
#include"Observer.h"
#include "Graph.h"
#include<iostream>
class GraphView: public Observer
{
public:
	GraphView();
	GraphView(Graph*);
	~GraphView();
    void Update(int g);
    void display(int d);
	//void UpdateMap();
	//void displayMap();
private:
	Graph* _subject;
};

