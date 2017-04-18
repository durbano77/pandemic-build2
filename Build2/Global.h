//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Global.h


#ifndef Global_h
#define Global_h


//----------- GLOBAL OBJECTS---------------------------------------------------->>>
//Contains only global objects (cards, pawns, player hands, array of players, array of playerviews, playerdeck, discard pile, etc.)
//Graph* myGraph;
//vertex* myVertex[];
//const int nbplayers = 4;
//const int nbcardsplayer = 4;    // # Cards per player when game starts
const int nbplayercards = 59;   // # PlayerCard's in the whole game
const int diseaseCubesCount = 24; // # of disease cubes per color disease

bool isgameover=false;

//Infection rate, initialized to 2 infection cards to be drawn
int infectionRatePos = 0;
int infectionRateMarker[7] = { 2,2,2,3,3,4,4 };
//Outbreak marker
int outbreakMarker = 0;
//remaining disease cubes (blue, yellow, black, red)
int remainingDiseaseCubes[4] = {diseaseCubesCount,diseaseCubesCount,diseaseCubesCount,diseaseCubesCount};
//cured diseases (blue, yellow, black, red)
bool isCured[4] = { false, false, false, false };
//eradicated diseases (blue, yellow, black, red)
bool isEradicated[4] = { false, false, false, false };

//Number of players, default 2
int numPlayers = 2;

//Creates 4 reference cards needed in the game, put them in an array for access
RefCard refcard1, refcard2, refcard3, refcard4;
RefCard referencecards[] = { refcard1, refcard2, refcard3, refcard4 };

//Creates Role Cards (inherited from Cards)
DispatcherCard dispatchercard1;
MedicCard mediccard1;
ScientistCard scientistcard1;
ResearcherCard researchercard1;
OperationsexpertCard operationsexpertcard1;
QuarantinespecialistCard quarantinespecialistcard1;
ContingencyplannerCard contingencyplannercard1;


//Creates player hands (creates many vectors of *PlayerCard)
//-----hands is an attribute from class Player-----
std::vector<PlayerCard*> dispatcherhand, medichand, scientisthand, researcherhand, operationsexperthand, quarantinespecialisthand, contingencyplannerhand;

//Creates <vector> playerdeck that contains *PlayerCard
std::vector<PlayerCard*> playerdeck;

//Creates <vector> discardpile that contains *PlayerCard
std::vector <PlayerCard*> discardpile;

//Creates <vector> infectiondeck that contains *InfectionCard
std::vector <InfectionCard*> infectiondeck;

//Creates <vector> infectiondeck that contains *InfectionCard DISCARD PILE
std::vector <InfectionCard*> infectiondeck_discard;

//Creates <vector> of *Players (size determined by how many players)
std::vector <Player*> arrayofPlayers;

//Creates <vector> of *PlayerView objects (Observers) [1 for each player]
std::vector <PlayerView *> arrayofPlayerViews;

//-----------CITY OBJECTS----------------------------------->
std::vector <City *> citiesInGraph;
//blue
City *city_Atlanta = new City("Atlanta", "blue");
City *city_SanFrancisco = new City("San Francisco", "blue");
City *city_Chicago = new City("Chicago", "blue");
City *city_Montreal = new City("Montreal", "blue");
City *city_Washington = new City("Washington", "blue");
City *city_NewYork = new City("New York", "blue");
City *city_London = new City("London", "blue");
City *city_Madrid = new City("Madrid", "blue");
City *city_Paris = new City("Paris", "blue");
City *city_Milan = new City("Milan", "blue");
City *city_Essen = new City("Essen", "blue");
City *city_StPetersburg = new City("St Petersburg", "blue");

//yellow
City *city_LosAngeles = new City("Los Angeles", "yellow");
City *city_Mexico = new City("Mexico", "yellow");
City *city_Miami = new City("Miami", "yellow");
City *city_Bogota = new City("Bogota", "yellow");
City *city_Lima = new City("Lima", "yellow");
City *city_Santiago = new City("Santiago", "yellow");
City *city_BuenosAires = new City("Buenos Aires", "yellow");
City *city_SaoPaolo = new City("Sao Paolo", "yellow");
City *city_Lagos = new City("Lagos", "yellow");
City *city_Kinshasa = new City("Kinshasa", "yellow");
City *city_Johannesburg = new City("Johannesburg", "yellow");
City *city_Khartoum = new City("Khartoum", "yellow");

//black
City *city_Moscow = new City("Moscow", "black");
City *city_Istanbul = new City("Istanbul", "black");
City *city_Algers = new City("Algers", "black");
City *city_LeCaire = new City("LeCaire", "black");
City *city_Bagdad = new City("Bagdad", "black");
City *city_Teheran = new City("Teheran", "black");
City *city_Karachi = new City("Karachi", "black");
City *city_Ryad = new City("Ryad", "black");
City *city_Dehli = new City("Dehli", "black");
City *city_Mumbai = new City("Mumbai", "black");
City *city_Chennai = new City("Chennai", "black");
City *city_Calcutta = new City("Calcutta", "black");

//red
City *city_Pekin = new City("Pekin", "red");
City *city_Seoul = new City("Seoul", "red");
City *city_Tokyo = new City("Tokyo", "red");
City *city_Shanghai = new City("Shanghai", "red");
City *city_Osaka = new City("Osaka", "red");
City *city_Taipei = new City("Taipei", "red");
City *city_HongKong = new City("Hong Kong", "red");
City *city_Manville = new City("Manville", "red");
City *city_Bangkok = new City("Bangkok", "red");
City *city_HoChiMinCity = new City("Ho Chi Min City", "red");
City *city_Jakarta = new City("Jakarta", "red");
City *city_Sydney = new City("Sydney", "red");


City* cityarr[] = {city_Atlanta,city_SanFrancisco,city_Chicago,city_Montreal,city_Washington,city_NewYork,city_London,city_Madrid,city_Paris,city_Milan,city_Essen,city_StPetersburg,city_LosAngeles,city_Mexico,city_Miami,city_Bogota,city_Lima,city_Santiago,city_BuenosAires,city_SaoPaolo,city_Lagos,city_Kinshasa,city_Johannesburg,city_Khartoum,city_Moscow,city_Istanbul,city_Algers,city_LeCaire,city_Bagdad,city_Teheran,city_Karachi,city_Ryad,city_Dehli,city_Mumbai,city_Chennai,city_Calcutta,city_Pekin,city_Seoul,city_Tokyo,city_Shanghai,city_Osaka,city_Taipei,city_HongKong,city_Manville,city_Bangkok,city_HoChiMinCity,city_Jakarta,city_Sydney};

vector<City*> vectorofcities= {city_Atlanta,city_SanFrancisco,city_Chicago,city_Montreal,city_Washington,city_NewYork,city_London,city_Madrid,city_Paris,city_Milan,city_Essen,city_StPetersburg,city_LosAngeles,city_Mexico,city_Miami,city_Bogota,city_Lima,city_Santiago,city_BuenosAires,city_SaoPaolo,city_Lagos,city_Kinshasa,city_Johannesburg,city_Khartoum,city_Moscow,city_Istanbul,city_Algers,city_LeCaire,city_Bagdad,city_Teheran,city_Karachi,city_Ryad,city_Dehli,city_Mumbai,city_Chennai,city_Calcutta,city_Pekin,city_Seoul,city_Tokyo,city_Shanghai,city_Osaka,city_Taipei,city_HongKong,city_Manville,city_Bangkok,city_HoChiMinCity,city_Jakarta,city_Sydney};

//Pawns initializations (do not move.. shoud be put after cities objects)
Pawn dispatcherpawn("pink", city_Atlanta, "Dispatcher");
Pawn medicpawn("orange", city_Atlanta, "Medic");
Pawn scientistpawn("white", city_Atlanta, "Scientist");
Pawn researcherpawn("brown", city_Atlanta, "Researcher");
Pawn operationsexpertpawn("palegreen", city_Atlanta, "Operations Expert");
Pawn quarantinespecialistpawn("darkgreen", city_Atlanta, "Quarantine Specialist");
Pawn contingencyplannerpawn("aqua", city_Atlanta, "Contigency Planner");


//Creates <vector> of EventCard that can be used by the players
std::vector<PlayerCard *> eventCardsAvail; //cast to base class PlayerCard for convenience


//-----------PlayerCard CARDS------------------------------->
//----------Epidemic cards----------
EpidemicCard* epcard1=new EpidemicCard();
EpidemicCard* epcard2=new EpidemicCard();
EpidemicCard* epcard3=new EpidemicCard();
EpidemicCard* epcard4=new EpidemicCard();
EpidemicCard* epcard5=new EpidemicCard();

EpidemicCard* epcardarr[]={epcard1, epcard2, epcard3, epcard4, epcard5};

//----------Event cards----------
Airlift* airliftcard=new Airlift();
OneQuietNight* onequietnightcard=new OneQuietNight();
GovernmentGrant* governmentgrantcard=new GovernmentGrant();
ResilientPopulation* resilientpopulationcard=new ResilientPopulation();
Forecast* forecastcard=new Forecast();

EventCard* eventcardarr[]={airliftcard, onequietnightcard, governmentgrantcard, resilientpopulationcard, forecastcard};

//


//---------City cards----------

//Blue
BlueCity* sanfrancisco=new BlueCity("sanfrancisco", "San Francisco", "", "");
BlueCity* chicago=new BlueCity("chicago", "Chicago", "", "");
BlueCity* atlanta=new BlueCity("atlanta", "Atlanta", "", "");
BlueCity* montreal=new BlueCity("montreal", "Montreal", "", "");
BlueCity* washington=new BlueCity("washington", "Washington", "", "");
BlueCity* newyork=new BlueCity("newyork", "New York", "", "");
BlueCity* londres=new BlueCity("londres", "Londres", "", "");
BlueCity* madrid=new BlueCity("madrid", "Madrid", "", "");
BlueCity* paris=new BlueCity("paris", "Paris", "", "");
BlueCity* milan=new BlueCity("milan", "Milan", "", "");
BlueCity* essen=new BlueCity("essen", "Essen", "", "");
BlueCity* stpetersbourg=new BlueCity("stpetersbourg", "St Petersbourg", "", "");
//Yellow
YellowCity* losangeles=new YellowCity("losangeles", "Los Angeles", "", "");
YellowCity* mexico=new YellowCity("mexico", "Mexico", "", "");
YellowCity* miami=new YellowCity("miami", "Miami", "", "");
YellowCity* bogota=new YellowCity("bogota", "Bogota", "", "");
YellowCity* lima=new YellowCity("lima", "Lima", "", "");
YellowCity* santiago=new YellowCity("santiago", "Santiago", "",  "");
YellowCity* buesnosaires=new YellowCity("buenosaires", "Buenos Aires", "", "");
YellowCity* saopaulo=new YellowCity("saopaulo", "Sao Paulo", "", "");
YellowCity* lagos=new YellowCity("lagos", "Lagos", "", "");
YellowCity* kinshasa=new YellowCity("kinshasa", "Kinshasa", "" , "");
YellowCity* johannesburg=new YellowCity("johannesburg", "Johannesburg", "", "");
YellowCity* khartoum=new YellowCity("khartoum", "Khartoum", "", "");
//Black
BlackCity* moscou=new BlackCity("moscou", "Moscou", "", "");
BlackCity* istanbul=new BlackCity("istanbul", "Istanbul", "", "");
BlackCity* alger=new BlackCity("alger", "Alger", "", "");
BlackCity* lecaire=new BlackCity("lecaire", "Le Caire", "", "");
BlackCity* bagdad=new BlackCity("bagdad", "Bagdad", "", "");
BlackCity* teheran=new BlackCity("teheran", "Teheran", "", "");
BlackCity* karachi=new BlackCity("karachi", "Karachi", "", "");
BlackCity* ryad=new BlackCity("ryad", "Ryad", "", "");
BlackCity* delhi=new BlackCity("delhi", "Delhi", "", "");
BlackCity* mumbai=new BlackCity("mumbai", "Mumbai", "", "");
BlackCity* chennai=new BlackCity("chennai", "Chennai", "", "");
BlackCity* calcutta=new BlackCity("calcutta", "Calcutta", "", "");
//Red
RedCity* pekin=new RedCity("pekin", "Pekin", "", "");
RedCity* seoul=new RedCity("seoul", "Seoul", "", "");
RedCity* tokyo=new RedCity("tokyo", "Tokyo", "", "");
RedCity* shanghai=new RedCity("shanghai", "Shanghai", "", "");
RedCity* osaka=new RedCity("osaka", "Osaka", "", "");
RedCity* taipei=new RedCity("taipei", "Taipei", "", "");
RedCity* hongkong=new RedCity("hongkong", "Hong Kong", "", "");
RedCity* manille=new RedCity("manille", "Manille", "", "");
RedCity* bangkok=new RedCity("bangkok", "Bangkok", "", "");
RedCity* hochiminhville=new RedCity("hochiminhville", "Ho Chi Minh Ville", "", "");
RedCity* jakarta=new RedCity("jakarta", "Jakarta", "", "");
RedCity* sydney=new RedCity("sydney", "Sydney", "", "");

CityCard* citycardarr[]={sanfrancisco, chicago, atlanta, montreal, washington, newyork, londres, madrid, paris, milan, essen, stpetersbourg, losangeles, mexico, miami, bogota, lima, santiago, buesnosaires, saopaulo, lagos, kinshasa, johannesburg, khartoum, moscou, istanbul, alger, lecaire, bagdad, teheran, karachi, ryad, delhi, mumbai, chennai, calcutta, pekin, seoul, tokyo, shanghai, osaka, taipei, hongkong, manille, bangkok, hochiminhville, jakarta, sydney};

////---------Infection cards----------
InfectionCard* sanfrancisco_inf = new InfectionCard(city_SanFrancisco, "San Francisco", "blue", "");
InfectionCard* chicago_inf = new InfectionCard(city_Chicago, "Chicago", "blue", "");
InfectionCard* atlanta_inf = new InfectionCard(city_Atlanta, "Atlanta", "blue", "");
InfectionCard* montreal_inf = new InfectionCard(city_Montreal, "Montreal", "blue", "");
InfectionCard* washington_inf = new InfectionCard(city_Washington, "Washington", "blue", "");
InfectionCard* newyork_inf = new InfectionCard(city_NewYork, "New York", "blue", "");
InfectionCard* londres_inf = new InfectionCard(city_London, "London", "blue", "");
InfectionCard* madrid_inf = new InfectionCard(city_Madrid, "Madrid", "blue", "");
InfectionCard* paris_inf = new InfectionCard(city_Paris, "Paris", "blue", "");
InfectionCard* milan_inf = new InfectionCard(city_Milan, "Milan", "blue", "");
InfectionCard* essen_inf = new InfectionCard(city_Essen, "Essen", "blue", "");
InfectionCard* stpetersbourg_inf = new InfectionCard(city_StPetersburg, "St Petersburg", "blue", "");
//Yellow
InfectionCard* losangeles_inf = new InfectionCard(city_LosAngeles, "Los Angeles", "yellow", "");
InfectionCard* mexico_inf = new InfectionCard(city_Mexico, "Mexico", "yellow", "");
InfectionCard* miami_inf = new InfectionCard(city_Miami, "Miami", "yellow", "");
InfectionCard* bogota_inf = new InfectionCard(city_Bogota, "Bogota", "yellow", "");
InfectionCard* lima_inf = new InfectionCard(city_Lima, "Lima", "yellow", "");
InfectionCard* santiago_inf = new InfectionCard(city_Santiago, "Santiago", "yellow", "");
InfectionCard* buesnosaires_inf = new InfectionCard(city_BuenosAires, "Buenos Aires", "yellow", "");
InfectionCard* saopaulo_inf = new InfectionCard(city_SaoPaolo, "Sao Paolo", "yellow", "");
InfectionCard* lagos_inf = new InfectionCard(city_Lagos, "Lagos", "yellow", "");
InfectionCard* kinshasa_inf = new InfectionCard(city_Kinshasa, "Kinshasa", "yellow", "");
InfectionCard* johannesburg_inf = new InfectionCard(city_Johannesburg, "Johannesburg", "yellow", "");
InfectionCard* khartoum_inf = new InfectionCard(city_Khartoum, "Khartoum", "yellow", "");
//Black
InfectionCard* moscou_inf = new InfectionCard(city_Moscow, "Moscow", "black", "");
InfectionCard* istanbul_inf = new InfectionCard(city_Istanbul, "Istanbul", "black", "");
InfectionCard* alger_inf = new InfectionCard(city_Algers, "Algers", "black", "");
InfectionCard* lecaire_inf = new InfectionCard(city_LeCaire, "Le Caire", "black", "");
InfectionCard* bagdad_inf = new InfectionCard(city_Bagdad, "Bagdad", "black", "");
InfectionCard* teheran_inf = new InfectionCard(city_Teheran, "Teheran", "black", "");
InfectionCard* karachi_inf = new InfectionCard(city_Karachi, "Karachi", "black", "");
InfectionCard* ryad_inf = new InfectionCard(city_Ryad, "Ryad", "black", "");
InfectionCard* delhi_inf = new InfectionCard(city_Dehli, "Dehli", "black", "");
InfectionCard* mumbai_inf = new InfectionCard(city_Mumbai, "Mumbai", "black", "");
InfectionCard* chennai_inf = new InfectionCard(city_Chennai, "Chennai", "black", "");
InfectionCard* calcutta_inf = new InfectionCard(city_Calcutta, "Calcutta", "black", "");
//Red
InfectionCard* pekin_inf = new InfectionCard(city_Pekin, "Pekin", "red", "");
InfectionCard* seoul_inf = new InfectionCard(city_Seoul, "Seoul", "red", "");
InfectionCard* tokyo_inf = new InfectionCard(city_Tokyo, "Tokyo", "red", "");
InfectionCard* shanghai_inf = new InfectionCard(city_Shanghai, "Shanghai", "red", "");
InfectionCard* osaka_inf = new InfectionCard(city_Osaka, "Osaka", "red", "");
InfectionCard* taipei_inf = new InfectionCard(city_Taipei, "Taipei", "red", "");
InfectionCard* hongkong_inf = new InfectionCard(city_HongKong, "Hong Kong", "red", "");
InfectionCard* manille_inf = new InfectionCard(city_Manville, "Manville", "red", "");
InfectionCard* bangkok_inf = new InfectionCard(city_Bangkok, "Bangkok", "red", "");
InfectionCard* hochiminhville_inf = new InfectionCard(city_HoChiMinCity,"Ho Chi Min City", "red", "");
InfectionCard* jakarta_inf = new InfectionCard(city_Jakarta, "Jakarta", "red", "");
InfectionCard* sydney_inf = new InfectionCard(city_Sydney, "Sydney", "red", "");

InfectionCard* infectioncardarr[] = { sanfrancisco_inf,chicago_inf,atlanta_inf,montreal_inf, washington_inf, newyork_inf, londres_inf,madrid_inf,paris_inf,milan_inf,essen_inf,stpetersbourg_inf,losangeles_inf, mexico_inf, miami_inf, bogota_inf, lima_inf, santiago_inf, buesnosaires_inf, saopaulo_inf, lagos_inf, kinshasa_inf, johannesburg_inf, khartoum_inf, moscou_inf, istanbul_inf, alger_inf, lecaire_inf, bagdad_inf, teheran_inf, karachi_inf, ryad_inf, delhi_inf, mumbai_inf, chennai_inf, calcutta_inf, pekin_inf, seoul_inf, tokyo_inf, shanghai_inf, osaka_inf, taipei_inf, hongkong_inf, manille_inf, bangkok_inf, hochiminhville_inf, jakarta_inf, sydney_inf };
//-----------------------------------------------------------------------------------------------//
std::vector <vertex *> verticies;
//blue
typedef map<City*, vertex *> cMap;
cMap cityMap;
Graph* myGraph = new Graph(&cityMap);

vertex *vertex_Atlanta = new vertex(city_Atlanta);// , myGraph);
vertex*vertex_SanFrancisco = new vertex(city_SanFrancisco);
vertex*vertex_Chicago = new vertex(city_Chicago);
vertex*vertex_Montreal = new vertex(city_Montreal);
vertex*vertex_Washington = new vertex(city_Washington);
vertex*vertex_NewYork = new vertex(city_NewYork);
vertex*vertex_London = new vertex(city_London);
vertex*vertex_Madrid = new vertex(city_Madrid);
vertex *vertex_Paris = new vertex(city_Paris);
vertex *vertex_Milan = new vertex(city_Milan);
vertex *vertex_Essen = new vertex(city_Essen);
vertex *vertex_StPetersburg = new vertex(city_StPetersburg);

//yellow
vertex *vertex_LosAngeles = new vertex(city_LosAngeles);
vertex *vertex_Mexico = new vertex(city_Mexico);
vertex *vertex_Miami = new vertex(city_Miami);
vertex *vertex_Bogota = new vertex(city_Bogota);
vertex *vertex_Lima = new vertex(city_Lima);
vertex *vertex_Santiago = new vertex(city_Santiago);
vertex *vertex_BuenosAires = new vertex(city_BuenosAires);
vertex *vertex_SaoPaolo = new vertex(city_SaoPaolo);
vertex *vertex_Lagos = new vertex(city_Lagos);
vertex *vertex_Kinshasa = new vertex(city_Kinshasa);
vertex *vertex_Johannesburg = new vertex(city_Johannesburg);
vertex *vertex_Khartoum = new vertex(city_Khartoum);

//black
vertex *vertex_Moscow = new vertex(city_Moscow);
vertex *vertex_Istanbul = new vertex(city_Istanbul);
vertex *vertex_Algers = new vertex(city_Algers);
vertex *vertex_LeCaire = new vertex(city_LeCaire);
vertex *vertex_Bagdad = new vertex(city_Bagdad);
vertex *vertex_Teheran = new vertex(city_Teheran);
vertex *vertex_Karachi = new vertex(city_Karachi);
vertex *vertex_Ryad = new vertex(city_Ryad);
vertex *vertex_Dehli = new vertex(city_Dehli);
vertex *vertex_Mumbai = new vertex(city_Mumbai);
vertex *vertex_Chennai = new vertex(city_Chennai);
vertex *vertex_Calcutta = new vertex(city_Calcutta);

//red
vertex *vertex_Pekin = new vertex(city_Pekin);
vertex *vertex_Seoul = new vertex(city_Seoul);
vertex *vertex_Tokyo = new vertex(city_Tokyo);
vertex *vertex_Shanghai = new vertex(city_Shanghai);
vertex *vertex_Osaka = new vertex(city_Osaka);
vertex *vertex_Taipei = new vertex(city_Taipei);
vertex *vertex_HongKong = new vertex(city_HongKong);
vertex *vertex_Manville = new vertex(city_Manville);
vertex *vertex_Bangkok = new vertex(city_Bangkok);
vertex *vertex_HoChiMinCity = new vertex(city_HoChiMinCity);
vertex *vertex_Jakarta = new vertex(city_Jakarta);
vertex *vertex_Sydney = new vertex(city_Sydney);


vertex* vertexarr[] = { vertex_Atlanta, vertex_SanFrancisco, vertex_Chicago, vertex_Montreal, vertex_Washington, vertex_NewYork, vertex_London, vertex_Madrid, vertex_Paris, vertex_Milan, vertex_Essen, vertex_StPetersburg, vertex_LosAngeles, vertex_Mexico, vertex_Miami, vertex_Bogota, vertex_Lima, vertex_Santiago, vertex_BuenosAires, vertex_SaoPaolo, vertex_Lagos, vertex_Kinshasa, vertex_Johannesburg, vertex_Khartoum, vertex_Moscow, vertex_Istanbul, vertex_Algers, vertex_LeCaire, vertex_Bagdad, vertex_Teheran, vertex_Karachi, vertex_Ryad, vertex_Dehli, vertex_Mumbai, vertex_Chennai, vertex_Calcutta, vertex_Pekin, vertex_Seoul, vertex_Tokyo, vertex_Shanghai, vertex_Osaka, vertex_Taipei, vertex_HongKong, vertex_Manville, vertex_Bangkok, vertex_HoChiMinCity, vertex_Jakarta, vertex_Sydney };

vector< vector<City*> > valladjcities;
// <<<-----------------------global objects--------------------------------------------------

#endif /* Global_h */
