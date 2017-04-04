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

const int nbplayers = 4;
const int nbcardsplayer = 4;    // # Cards per player when game starts
const int nbplayercards = 59;   // # PlayerCard's in the whole game
const int diseaseCubesCount = 24; // # of disease cubes per color disease

//Infection rate, initialized to 1
int infectionRate = 1;
//remaining disease cubes (blue, yellow, black, red)
int remainingDiseaseCubes[4] = {diseaseCubesCount,diseaseCubesCount,diseaseCubesCount,diseaseCubesCount };

//Number of players, default 2
int numPlayers = 2;

//Creates 4 reference cards needed in the game, put them in an array for access
RefCard refcard1, refcard2, refcard3, refcard4;
RefCard referencecards[] = { refcard1, refcard2, refcard3, refcard4 };

//Pawn pink("Pink"), orange("Orange"), white ("White"), brown("Brown"), palegreen("Pale Green"), darkgreen("Dark Green"), aqua("Aqua");

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

//---------Infection cards----------
InfectionCard* sanfrancisco_inf = new InfectionCard("sanfrancisco", "San Francisco", "blue", "");
InfectionCard* chicago_inf = new InfectionCard("chicago", "Chicago", "blue", "");
InfectionCard* atlanta_inf = new InfectionCard("atlanta", "Atlanta", "blue", "");
InfectionCard* montreal_inf = new InfectionCard("montreal", "Montreal", "blue", "");
InfectionCard* washington_inf = new InfectionCard("washington", "Washington", "blue", "");
InfectionCard* newyork_inf = new InfectionCard("newyork", "New York", "blue", "");
InfectionCard* londres_inf = new InfectionCard("londres", "Londres", "blue", "");
InfectionCard* madrid_inf = new InfectionCard("madrid", "Madrid", "blue", "");
InfectionCard* paris_inf = new InfectionCard("paris", "Paris", "blue", "");
InfectionCard* milan_inf = new InfectionCard("milan", "Milan", "blue", "");
InfectionCard* essen_inf = new InfectionCard("essen", "Essen", "blue", "");
InfectionCard* stpetersbourg_inf = new InfectionCard("stpetersbourg", "St Petersbourg", "blue", "");
//Yellow
InfectionCard* losangeles_inf = new InfectionCard("losangeles", "Los Angeles", "yellow", "");
InfectionCard* mexico_inf = new InfectionCard("mexico", "Mexico", "yellow", "");
InfectionCard* miami_inf = new InfectionCard("miami", "Miami", "yellow", "");
InfectionCard* bogota_inf = new InfectionCard("bogota", "Bogota", "yellow", "");
InfectionCard* lima_inf = new InfectionCard("lima", "Lima", "yellow", "");
InfectionCard* santiago_inf = new InfectionCard("santiago", "Santiago", "yellow", "");
InfectionCard* buesnosaires_inf = new InfectionCard("buenosaires", "Buenos Aires", "yellow", "");
InfectionCard* saopaulo_inf = new InfectionCard("saopaulo", "Sao Paulo", "yellow", "");
InfectionCard* lagos_inf = new InfectionCard("lagos", "Lagos", "yellow", "");
InfectionCard* kinshasa_inf = new InfectionCard("kinshasa", "Kinshasa", "yellow", "");
InfectionCard* johannesburg_inf = new InfectionCard("johannesburg", "Johannesburg", "yellow", "");
InfectionCard* khartoum_inf = new InfectionCard("khartoum", "Khartoum", "yellow", "");
//Black
InfectionCard* moscou_inf = new InfectionCard("moscou", "Moscou", "black", "");
InfectionCard* istanbul_inf = new InfectionCard("istanbul", "Istanbul", "black", "");
InfectionCard* alger_inf = new InfectionCard("alger", "Alger", "black", "");
InfectionCard* lecaire_inf = new InfectionCard("lecaire", "Le Caire", "black", "");
InfectionCard* bagdad_inf = new InfectionCard("bagdad", "Bagdad", "black", "");
InfectionCard* teheran_inf = new InfectionCard("teheran", "Teheran", "black", "");
InfectionCard* karachi_inf = new InfectionCard("karachi", "Karachi", "black", "");
InfectionCard* ryad_inf = new InfectionCard("ryad", "Ryad", "black", "");
InfectionCard* delhi_inf = new InfectionCard("delhi", "Delhi", "black", "");
InfectionCard* mumbai_inf = new InfectionCard("mumbai", "Mumbai", "black", "");
InfectionCard* chennai_inf = new InfectionCard("chennai", "Chennai", "black", "");
InfectionCard* calcutta_inf = new InfectionCard("calcutta", "Calcutta", "black", "");
//Red
InfectionCard* pekin_inf = new InfectionCard("pekin", "Pekin", "red", "");
InfectionCard* seoul_inf = new InfectionCard("seoul", "Seoul", "red", "");
InfectionCard* tokyo_inf = new InfectionCard("tokyo", "Tokyo", "red", "");
InfectionCard* shanghai_inf = new InfectionCard("shanghai", "Shanghai", "red", "");
InfectionCard* osaka_inf = new InfectionCard("osaka", "Osaka", "red", "");
InfectionCard* taipei_inf = new InfectionCard("taipei", "Taipei", "red", "");
InfectionCard* hongkong_inf = new InfectionCard("hongkong", "Hong Kong", "red", "");
InfectionCard* manille_inf = new InfectionCard("manille", "Manille", "red", "");
InfectionCard* bangkok_inf = new InfectionCard("bangkok", "Bangkok", "red", "");
InfectionCard* hochiminhville_inf = new InfectionCard("hochiminhville", "Ho Chi Minh Ville", "red", "");
InfectionCard* jakarta_inf = new InfectionCard("jakarta", "Jakarta", "red", "");
InfectionCard* sydney_inf = new InfectionCard("sydney", "Sydney", "red", "");

InfectionCard* infectioncardarr[] = { sanfrancisco_inf,chicago_inf,atlanta_inf,montreal_inf, washington_inf, newyork_inf, londres_inf,madrid_inf,paris_inf,milan_inf,essen_inf,stpetersbourg_inf,losangeles_inf, mexico_inf, miami_inf, bogota_inf, lima_inf, santiago_inf, buesnosaires_inf, saopaulo_inf, lagos_inf, kinshasa_inf, johannesburg_inf, khartoum_inf, moscou_inf, istanbul_inf, alger_inf, lecaire_inf, bagdad_inf, teheran_inf, karachi_inf, ryad_inf, delhi_inf, mumbai_inf, chennai_inf, calcutta_inf, pekin_inf, seoul_inf, tokyo_inf, shanghai_inf, osaka_inf, taipei_inf, hongkong_inf, manille_inf, bangkok_inf, hochiminhville_inf, jakarta_inf, sydney_inf };

// <<<-----------------------global objects--------------------------------------------------

#endif /* Global_h */
