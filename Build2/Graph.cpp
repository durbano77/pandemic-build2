#include"Graph.h"


Graph::Graph(cMap* c){
	cityMap = c;
}

//void Graph::addC(vector<City*>cityVector){
//
//	//vector<City*>::iterator it = cityVector.begin();
//	for (unsigned i = 0; i < cityVector.size(); i++)
//	{
//		addCityToGraph(cityVector[i]);
//	}
//
//	//Notify();
//}
void Graph::addCityToGraph(City * name, vertex* v)
{
	cMap::iterator itr = cityMap->find(name);
	if (itr == cityMap->end())
	{
		//vertex *v;
		//v = new vertex(name);
		cityMap->insert(std::make_pair(name, v));// = new cMap <name, v>;// apinsert(name, v); //= v;
		cityInGraph.push_back(name);
		return;
		//Notify();
	}

	cout << "\nCity already exists!";
}

vector<City*> Graph::adjoiningCities(City* c)
{
	vertex *from = cityMap->find(c)->second;
	vector<vertex*> v = from->adj;
	vector <City*> cityVector;
	if (v.empty())
	{
		cout << c->getCityName() << "has no connetion\n";
		return cityVector;
	}
	else
	{
		//cout << "\n City " << from->name->getCityName() << " connected to: " << endl;
		//vector<vertex*> ::iterator itr = v.begin();

		for (int i = 0; i < v.size(); i++) {
			cityVector.push_back(v[i]->name);
		}
		//cout << "\n City " << from->name->getCityName() << " has " << cityVector.size() << " cities it is connected to" << endl;;
		return cityVector;

	}


}
void Graph::addedge(City* f, City* t) //OK
{

	//cMap::iterator itr = cityMap->find(f)->second; //find(f);
	//vertex *from = (cityMap->find(f)->second);
	//   vertex *to = (cityMap->find(t)->second);
	//    vertex *edge = to;
	//cityMap->
	cityMap->find(f)->second->adj.push_back(cityMap->find(t)->second);
	cityMap->find(t)->second->adj.push_back(cityMap->find(f)->second);
	//Notify();

}

void Graph::printGraph()
{
	cMap::iterator itr = cityMap->begin();
	//vector<City*>::iterator it = cityInGraph.begin();
	cout << "*****************************************************" << endl;
	cout << "list of cities in map and their information" << endl;
	while (itr != cityMap->end())
	{
		itr->first->print();
		itr++;
	}


	cout << "*****************************************************" << endl;
}
bool Graph::operator==(City &c)   // ??????
{
	City newCity;

	return true;
}
void Graph::showCity()
{
	cMap::iterator itr = cityMap->begin();
	cout << "\nCity with connection\n" << endl;

	while (itr != cityMap->end())
	{
		//cityWithAdjacency(itr->first);
		showCityInfo(itr->first);
		++itr;

	}
}
void Graph::showCityInfo(City* name)
{

	cMap::iterator itr = cityMap->find(name);
	if (itr != cityMap->end())
	{
		name->print();
		return;
	}

	cout << "city not in graph" << endl;
}
/*
returnthe list of a citis edge
*/
void Graph::getCityEdge(City* c) {

	vertex *from = cityMap->find(c)->second;
	vector<vertex*> v = from->adj;

	cout << "In: " << from->name->getCityName() << " connected to: " << endl;

	vector<vertex*> ::iterator itr = v.begin();

	for (itr; itr != v.end(); itr++) {
		//cout << &itr<< endl;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i]->name->getCityName() << endl;
	}

}
/*
display the cities and therir connections
*/
void Graph::cityAndConnection() //OK
{
	cMap::iterator itr = cityMap->begin();
	cout << "\nCity with connection\n" << endl;

	while (itr != cityMap->end())
	{
		//cityWithAdjacency(itr->first);
		cityConnection(itr->first);
		++itr;

	}


}
void Graph::cityConnection(City* c) { //OK

	vertex *from = cityMap->find(c)->second;
	vector<vertex*> v = from->adj;
	if (v.empty())
	{
		//cout << "no connetion";
	}
	else
	{
		//cout << "\n City " << from->name->getCityName() << " connected to: " << endl;
		//vector<vertex*> ::iterator itr = v.begin();
		cout << "\n City " << from->name->getCityName() << " has " << v.size() << " cities it is connected to" << endl;;
		for (int i = 0; i < v.size(); i++) {
			cout << i + 1 << " " << v[i]->name->getCityName() << endl;
		}


	}
}
/*
display just the cities that have cnnnection
*/
void Graph::cityWithAdjacency() {

	cMap::iterator itr = cityMap->begin();
	cout << "\nCity with connection\n" << endl;
	while (itr != cityMap->end())
	{
		cityAdjacency(itr->first);
		//cityConnection(itr->first);
		++itr;

	}

}
void Graph::cityAdjacency(City* c){
	vertex *from = cityMap->find(c)->second;
	vector<vertex*> v = from->adj;

	if (v.empty())
	{
		//cout << "no connetion";
	}

	else
		cout << "City " << from->name->getCityName() << endl;

}


Graph::~Graph()
{

	//* Destructor: Not working as it is*/


	//vector<City>::iterator it = cityInGraph.begin();

	//	cMap::iterator itr = cityMap->begin();
	//	while (itr !=cityMap->end())
	//	{
	//		delete itr->first;
	//		delete itr->second;
	//	}


}
vector <City*>  Graph::getCityInGraph()
{
	return cityInGraph;

}
void  Graph::createMap(City* citiesarr[], vertex* vertexarr[])
{

	//City c[48];

	//copy cityarr objects into c
	for (int i = 0; i < 48; i++) {
		//c[i] = *citiesarr[i];
	}


	vector <City*> v;

	for (int i = 0; i < 48; i++) {
		addCityToGraph(citiesarr[i], vertexarr[i]);
		//v.push_back(citiesarr[i]);
	}
	//addC(v);

	addedge(citiesarr[2], citiesarr[14]);
	addedge(citiesarr[0], citiesarr[14]);
	addedge(citiesarr[2], citiesarr[12]);
	addedge(citiesarr[2], citiesarr[13]);
	addedge(citiesarr[14], citiesarr[13]);
	addedge(citiesarr[16], citiesarr[13]);
	addedge(citiesarr[15], citiesarr[13]);
	addedge(citiesarr[10], citiesarr[11]);
	addedge(citiesarr[6], citiesarr[10]);
	addedge(citiesarr[10], citiesarr[9]);
	addedge(citiesarr[7], citiesarr[8]);
	addedge(citiesarr[6], citiesarr[8]);
	addedge(citiesarr[5], citiesarr[7]);
	addedge(citiesarr[19], citiesarr[7]);
	addedge(citiesarr[5], citiesarr[6]);
	addedge(citiesarr[7], citiesarr[6]);
	addedge(citiesarr[4], citiesarr[5]);
	addedge(citiesarr[3], citiesarr[5]);
	addedge(citiesarr[2], citiesarr[1]);
	addedge(citiesarr[0], citiesarr[2]);
	addedge(citiesarr[2], citiesarr[3]);
	addedge(citiesarr[4], citiesarr[3]);
	addedge(citiesarr[0], citiesarr[4]);
	addedge(citiesarr[11], citiesarr[25]);
	addedge(citiesarr[9], citiesarr[25]);
	addedge(citiesarr[24], citiesarr[25]);
	addedge(citiesarr[11], citiesarr[24]);
	addedge(citiesarr[19], citiesarr[20]);
	addedge(citiesarr[15], citiesarr[19]);
	addedge(citiesarr[7], citiesarr[19]);
	addedge(citiesarr[15], citiesarr[18]);
	addedge(citiesarr[15], citiesarr[16]);
	addedge(citiesarr[14], citiesarr[15]);
	addedge(citiesarr[29], citiesarr[30]);
	addedge(citiesarr[32], citiesarr[30]);
	addedge(citiesarr[24], citiesarr[29]);
	addedge(citiesarr[29], citiesarr[28]);
	addedge(citiesarr[25], citiesarr[26]);
	addedge(citiesarr[7], citiesarr[26]);
	addedge(citiesarr[44], citiesarr[46]);
	addedge(citiesarr[44], citiesarr[45]);
	addedge(citiesarr[46], citiesarr[45]);
	addedge(citiesarr[35], citiesarr[44]);
	addedge(citiesarr[45], citiesarr[43]);
	addedge(citiesarr[35], citiesarr[42]);
	addedge(citiesarr[46], citiesarr[42]);
	addedge(citiesarr[30], citiesarr[33]);
	addedge(citiesarr[32], citiesarr[33]);
	addedge(citiesarr[29], citiesarr[32]);
	addedge(citiesarr[28], citiesarr[32]);
	addedge(citiesarr[28], citiesarr[31]);
	addedge(citiesarr[30], citiesarr[31]);
	addedge(citiesarr[32], citiesarr[34]);
	addedge(citiesarr[33], citiesarr[34]);
	addedge(citiesarr[32], citiesarr[35]);

	//getCityEdge(&c[32]);
	///showCityInfo(&c[47]);

	Notify(5);
	cout << endl;
}



vertex::~vertex()
{
	delete name;
}
