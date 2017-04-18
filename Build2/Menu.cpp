//
//  Menu.cpp
//  Build2
//


#include "Menu.h"


Menu::Menu(){}

Menu::Menu(Player* pl, std::vector<Player*> &vectorplayer,  std::vector<PlayerCard*> *dPile){
    this->p=pl;
    //this->adjcities;
    
    this->vectorplayers=vectorplayer;
    this->discardPile=dPile;
    
}


Menu::~Menu(){
    p=nullptr;
    delete p;

}


int Menu::getnbactionstodo(){
    return nbactionstodo;

}

void Menu::setAdjCity(vector<City*> &vc){
    adjcities=vc;
}

void Menu::setPlayer(Player* pl){
    this->p=pl;

}


Player* Menu::getPlayer(){
    return p;
}

//add options to pick a event card anytime

void Menu::clearScreen(){
    cout<<"\n\n\nPress enter to continue";
    cin.ignore();
    for(int i = 0; i<100; i++){
        cout << "    " << endl;
    }
}

void Menu::doMenu(City* acities[], int remainingDiseaseCubes[4], bool isCured[4], bool isEradicated[4]){

    displayMenu(acities, remainingDiseaseCubes, isCured, isEradicated);

    int choice=inChoice();
    
    doAction(choice, acities, remainingDiseaseCubes, isCured, isEradicated);

  
}



void Menu::displayMenu(City* acities[], int remainingDiseaseCubes[4], bool isCured[4], bool isEradicated[4]){
   
    int vps=vectorplayers.size();
    
    p->getPawn()->printPawn();
    p->printHandTitles();
    p->getPawn()->getPawnCity()->print();
    
    std::cout<<"\n\n***************MENU***************"<<std::endl;
    std::cout<<"Select one of the following options:\n\n\n"<<std::endl;
    
    std::cout<<"-----DISPLAY-----\n"<<std::endl;
    std::cout<<p->getPlayerName()<<" information"<<std::endl;
    std::cout<<"[1] Reference card"<<std::endl;
        possible.push_back(1);
    std::cout<<"[2] Role card"<<std::endl;
        possible.push_back(2);
    std::cout<<"[3] Player hand\n"<<std::endl;
        possible.push_back(3);
    

    std::cout<<"Players information"<<std::endl;
    for(int i=0;i<vectorplayers.size();i++){
        std::cout<<"["<<4+i<<"] "<<vectorplayers[i]->getPlayerName()<<std::endl;
        possible.push_back(4+i);
    }
    
    std::cout<<"\nCity information"<<std::endl;
    std::cout<<"["<<vps+4<<"] One city to display"<<std::endl;
        possible.push_back(vps+4);
    std::cout<<"["<<vps+5<<"] All the cities"<<std::endl;
        possible.push_back(vps+5);

    std::cout<<"\n-----ACTIONS-----\n"<<std::endl;
    if(nbactionstodo>0){
        std::cout<<"***You can still perform "<<nbactionstodo<<" actions***\n"<<std::endl;
        std::cout<<"["<<vps+6<<"] Drive"<<std::endl;
            if(!p->drive(adjcities, false)){
                std::cout<<"This option is not available to you right now"<<std::endl;
            }else{possible.push_back(vps+6);}
        
        
        std::cout<<"["<<vps+7<<"] Direct Flight"<<std::endl;
        if(!p->directFlight(acities, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{
            possible.push_back(vps+7);
            std::cout<<"You have city card "<<p->getPawn()->getPawnCity()->getCityName()<<". You can fly to "<<p->getPawn()->getPawnCity()->getCityName()<<std::endl;
        }
        
        
        std::cout<<"["<<vps+8<<"] Charter Flight"<<std::endl;
        if(!p->charterFlight(acities, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{
            possible.push_back(vps+8);
            std::cout<<"You can discard any city card from your hand to fly to the corresponding city."<<std::endl;
        }
        
        
        std::cout<<"["<<vps+9<<"] Shuttle Flight"<<std::endl;
        if(!p->shuttleFlight(acities, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(vps+9);}
        
        
        std::cout<<"["<<vps+10<<"] Build a Research Station"<<std::endl;
        if(!p->buildResearchStation(discardPile, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(vps+10);}
        
        
        std::cout<<"["<<vps+11<<"] Treat Disease"<<std::endl;
        if(!p->treatDisease(remainingDiseaseCubes, isCured, isEradicated , false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(vps+11);}
        
        
        std::cout<<"["<<vps+12<<"] Share Knowledge"<<std::endl;
        if(!p->shareKnowledge(vectorplayers, false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(vps+12);}
        
        
        std::cout<<"["<<vps+13<<"] Discover a Cure"<<std::endl;
        if(!p->discoverCure(remainingDiseaseCubes, isCured, isEradicated , false)){
            std::cout<<"This option is not available to you right now"<<std::endl;
        }else{possible.push_back(vps+13);}
    
    
    }
    else{
        std::cout<<"You dont have any actions left.\n"<<std::endl;}
    
    //std::cout<<"-----EVENT ACTIONS-----\n"<<std::endl;
    
//    cout<<"POSSIBLE AFTER ORIGINAL DISPLAY: "<<possible.size();
//    for(int i=0;i<possible.size();i++){
//        cout<<possible[i]<<"  ";
//        
//    }

}

int Menu::inChoice(){
    int actionchoice=0;
    
    
    std::set<int> setofchoices(std::make_move_iterator(possible.begin()),
                               std::make_move_iterator(possible.end()));
    
    
    while(!setofchoices.count(actionchoice))
    {
        std::cout<<"Enter your choice # : "<<std::endl;
        std::cin>>actionchoice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    
    return actionchoice;
}

void Menu::doAction(int a, City* acities[], int remainingDiseaseCubes[4], bool isCured[4], bool isEradicated[4]){
    
    //clearScreen();
    for(int i = 0; i<100; i++){
        cout << "    " << endl;
    }

    
    int ai=vectorplayers.size()+4;
    
    if(a==1){
        p->getPawn()->printPawn();
        p->printRefCard();
        clearScreen();
        doMenu(acities, remainingDiseaseCubes, isCured, isEradicated);
    }
    else if(a==2){
        p->getPawn()->printPawn();
        p->printRoleCard();
        clearScreen();
        doMenu(acities, remainingDiseaseCubes, isCured, isEradicated);
    }
    else if(a==3){
        p->getPawn()->printPawn();
        p->printHand();
        clearScreen();
        doMenu(acities, remainingDiseaseCubes, isCured, isEradicated);
    }
    
    for(int i=0;i<vectorplayers.size();i++){
        if(a==4+i){
            vectorplayers[i]->getPawn()->printPawn();
            vectorplayers[i]->printRoleCard();
            vectorplayers[i]->printHand();
            clearScreen();
            doMenu(acities, remainingDiseaseCubes, isCured, isEradicated);
        }
    }
    
    ai-=1;
    
    if(a==ai+1){
        cout<<"CITY INFORMATION"<<endl;
        for(int c=0;c<48;c++){
            cout<<"["<<c+1<<"] "<<acities[c]->getCityName()<<endl;
        }
        std::cout<<"What city do you want to get information for?"<<std::endl;
        int t=0;
        while(t<1 || t>48)
        {
            std::cout<<"Enter your choice # : "<<std::endl;
            std::cin>>t;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        for(int i = 0; i<100; i++){
            cout << "    " << endl;
        }
        acities[t-1]->print();
        
        clearScreen();
        doMenu(acities, remainingDiseaseCubes, isCured, isEradicated);
    }
    else if(a==ai+2){
        cout<<" ALL CITIES INFO "<<endl;
        for(int j=0;j<48;j++){
            acities[j]->print();
        }
        clearScreen();
        doMenu(acities, remainingDiseaseCubes, isCured, isEradicated);
    }
    
    else if(a==ai+3){
        p->drive(adjcities, true);
        nbactionstodo-=1;
    }
    else if(a==ai+4){
         p->directFlight(acities, true);
        nbactionstodo-=1;
    }
    else if(a==ai+5){
        p->charterFlight(acities, true);
        nbactionstodo-=1;
    }
    else if(a==ai+6){
        p->shuttleFlight(acities, true);
        nbactionstodo-=1;
    }
    else if(a==ai+7){
         p->buildResearchStation(discardPile, true);
        nbactionstodo-=1;
    }
    else if(a==ai+8){
        p->treatDisease(remainingDiseaseCubes, isCured, isEradicated , true);
        nbactionstodo-=1;
    }
    else if(a==ai+9){
        p->shareKnowledge(vectorplayers, true);
        nbactionstodo-=1;
    }
    else if(a==ai+10){
        p->discoverCure(remainingDiseaseCubes, isCured, isEradicated , true);
        nbactionstodo-=1;
    }


}
