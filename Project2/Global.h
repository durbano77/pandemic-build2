//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//Global.h


#ifndef Global_h
#define Global_h

#include <afxwin.h>
#define _AFXDLL

using namespace std;


//----------- GLOBAL OBJECTS---------------------------------------------------->>>
//Contains only global objects (cards, pawns, player hands, array of players, array of playerviews, playerdeck, discard pile, etc.)

const int nbplayers = 4;
const int nbcardsplayer = 4;    // # Cards per player when game starts
const int nbplayercards = 59;   // # PlayerCard's in the whole game
const int diseaseCubesCount = 24; // # of disease cubes per color disease

//Infection rate, initialized to 2 infection cards to be drawn
int infectionRate = 2;
//remaining disease cubes (blue, yellow, black, red)
int remainingDiseaseCubes[4] = {diseaseCubesCount,diseaseCubesCount,diseaseCubesCount,diseaseCubesCount};
//cured diseases (blue, yellow, black, red)
bool isCured[4] = { false, false, false, false };
//eradicated diseases (blue, yellow, black, red)
bool isEradicated[4] = { false, false, false, false };

//Number of players, default 2
int numPlayers = 2;

//Creates 4 reference cards needed in the game, put them in an array for access
//RefCard refcard1, refcard2, refcard3, refcard4;
//RefCard referencecards[] = { refcard1, refcard2, refcard3, refcard4 };

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
vector<PlayerCard*> dispatcherhand, medichand, scientisthand, researcherhand, operationsexperthand, quarantinespecialisthand, contingencyplannerhand;

//Creates <vector> playerdeck that contains *PlayerCard
vector<PlayerCard*> playerdeck;

//Creates <vector> discardpile that contains *PlayerCard
vector <PlayerCard*> discardpile;

//Creates <vector> infectiondeck that contains *InfectionCard
vector <InfectionCard*> infectiondeck;

//Creates <vector> infectiondeck that contains *InfectionCard DISCARD PILE
vector <InfectionCard*> infectiondeck_discard;

//Creates <vector> of *Players (size determined by how many players)
vector <Player*> arrayofPlayers;

//Creates <vector> of *PlayerView objects (Observers) [1 for each player]
vector <PlayerView *> arrayofPlayerViews;

//-----------CITY OBJECTS----------------------------------->
vector <City *> cities;
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

//Pawns initializations (do not move.. shoud be put after cities objects)
Pawn dispatcherpawn("pink", city_Atlanta, "Dispatcher");
Pawn medicpawn("orange", city_Atlanta, "Medic");
Pawn scientistpawn("white", city_Atlanta, "Scientist");
Pawn researcherpawn("brown", city_Atlanta, "Researcher");
Pawn operationsexpertpawn("palegreen", city_Atlanta, "Operations Expert");
Pawn quarantinespecialistpawn("darkgreen", city_Atlanta, "Quarantine Specialist");
Pawn contingencyplannerpawn("aqua", city_Atlanta, "Contigency Planner");


//Creates <vector> of EventCard that can be used by the players
vector<PlayerCard *> eventCardsAvail; //cast to base class PlayerCard for convenience


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

// <<<-----------------------global objects--------------------------------------------------

#endif /* Global_h */
