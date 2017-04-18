//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//PlayerView.cpp

#include "PlayerView.h"

PlayerView::PlayerView(){
}

PlayerView::PlayerView(Player *plyr){
    p=plyr;
    p->Attach(this); //for each player, attach one observer
}


PlayerView::~PlayerView(){
    p->Detach(this);
    p=nullptr;

}

void PlayerView::Update(int u){
    display(u);
}

void PlayerView::display(int t){
    switch(t){
        case 0:
            this->displayAll();
            break;
        case 1:
            this->displayHand();
            break;
        case 2:
            this->displayDiscardHand();
            break;
        case 3:
            this->displayEpidemicCard();
            break;
        case 4:
            this->displayPawn();
            break;
        case 5:
            //graph view (cities that have adjency)
            break;
        case 6:
            //graph view (cities connections)
            break;
        case 7:
            //all cities info
            break;
        case 8:
            //infection card display
            break;
        default:
            std::cout<<"ERR: Player View - No display function selected."<<std::endl;
    
    }

    
}

//void PlayerView::UpdateHand(){
//    displayHand();
//}
//void PlayerView::UpdateDiscardHand(){
//    displayDiscardHand();
//}
//void PlayerView::UpdateEpidemicCard(){
//    displayEpidemicCard();
//}


void PlayerView::displayAll(){
        p->getPawn()->printPawn();
        clearScreen();
        p->printRoleCard();
        clearScreen();
        p->printRefCard();
        clearScreen();
        p->printHand();
        std::cout<<"====================================================================\n\n\n"<<std::endl;

}

void PlayerView::displayHand(){
    p->printHand();
    std::cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n"<<std::endl;
}

void PlayerView::displayDiscardHand(){
    int sizehand = (int)(p->getHand()).size();
    int nbcardsdiscard=sizehand % 7;
    std::cout<<"\nYou have " << sizehand << " player cards. You must discard "<< nbcardsdiscard <<" cards."<<std::endl;
    std::cout<<"What card(s) do you want to discard?"<<std::endl;
    for(int i=0; i<sizehand;i++){
        std::cout<< i+1 <<" - " <<((p->getHand())[i])->getCardName()<<std::endl;
    }

}

void PlayerView::displayEpidemicCard(){
    std::cout<<"////////// ALERT EPIDEMIC CARD \\\\\\\\\\"<<std::endl;
    //((p->getHand()).back())->printCard();
    
}


void PlayerView::displayPawn(){  //could be called each time the player moves to another location?
    p->getPawn()->printPawn();
}

void PlayerView::clearScreen(){
    cout<<"\n\n\nPress enter to continue";
    cin.ignore();
    for(int i = 0; i<100; i++){
        cout << "    " << endl;
    }
}
