//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//CityCard.cpp

#include "CityCard.h"

CityCard::CityCard(){
    Cards();

}

CityCard::CityCard(std::string city, std::string title, std::string cardtextfront, std::string cardtextback) {
    city=city;
    card_name=title;
    card_textfront=cardtextfront;
    card_textback=cardtextback;
    Cards(title, cardtextfront, cardtextback);
}

CityCard::~CityCard(){

}



BlueCity::BlueCity(){
    CityCard();
}
BlueCity::BlueCity(std::string city, std::string title, std::string cardtextfront, std::string cardtextback){
    city=city;
    card_name=title;
    card_textfront=cardtextfront;
    card_textback=cardtextback;
    CityCard(city, title, cardtextfront, cardtextback);
}
BlueCity::~BlueCity(){

}



YellowCity::YellowCity(){
    CityCard();
}
YellowCity::YellowCity(std::string city, std::string title, std::string cardtextfront, std::string cardtextback){
    city=city;
    card_name=title;
    card_textfront=cardtextfront;
    card_textback=cardtextback;
    CityCard(city, title, cardtextfront, cardtextback);
}
YellowCity::~YellowCity(){

}


BlackCity::BlackCity(){
    CityCard();
}
BlackCity::BlackCity(std::string city, std::string title, std::string cardtextfront, std::string cardtextback){
    city=city;
    card_name=title;
    card_textfront=cardtextfront;
    card_textback=cardtextback;
    CityCard(city, title, cardtextfront, cardtextback);
}
BlackCity::~BlackCity(){

}


RedCity::RedCity(){
    CityCard();
}
RedCity::RedCity(std::string city, std::string title, std::string cardtextfront, std::string cardtextback){
    city=city;
    card_name=title;
    card_textfront=cardtextfront;
    card_textback=cardtextback;
    CityCard(city, title, cardtextfront, cardtextback);
}
RedCity::~RedCity(){
    
}


/* List of cities
 //Blue
 SanFrancisco sanfrancisco;
 Chicago chicago;
 Atlanta atlanta;
 Montreal montreal;
 Washington washington;
 NewYork newyork;
 Londres londres;
 Madrid madrid;
 Paris paris;
 Milan milan;
 Essen essen;
 StPetersbourg stpetersbourg;
 //Yellow
 LosAngeles losangeles;
 Mexico mexico;
 Miami miami;
 Bogota bogota;
 Lima lima;
 Santiago santiago;
 BuenosAires buesnosaires;
 SaoPaulo saopaulo;
 Lagos lagos;
 Kinshasa kinshasa;
 Johannesburg johannesburg;
 Khartoum khartoum;
 //Black
 Moscou moscou;
 Istanbul istanbul;
 Alger alger;
 LeCaire lecaire;
 Bagdad bagdad;
 Teheran teheran;
 Karachi karachi;
 Ryad ryad;
 Delhi delhi;
 Mumbai mumbai;
 Chennai chennai;
 Calcutta calcutta;
 //Red
 Pekin pekin;
 Seoul seoul;
 Tokyo tokyo;
 Shanghai shanghai;
 Osaka osaka;
 Taipei taipei;
 HongKong hongkong;
 Manille manille;
 Bangkok bangkok;
 HoChiMinhVille hochiminhville;
 Jakarta jakarta;
 Sydney sydney;
*/
