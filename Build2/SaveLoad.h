#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <algorithm>
#include <string>
#include "PlayerView.h"
#include "CardsHeaders.h"
#include "Global.h"

using namespace std;

class Save{
public:
	ofstream myfile;
	void save_game(){
		myfile.open("SaveFile.txt");
		//saving the map
		int i = 3;
		while (i >= 1) {
			for (int k = 3; k > 0; k--) {
				//draw infection card from infection deck
				InfectionCard* curr_inf = infectiondeck.back();
				string city = curr_inf->getCardName();
				string color = curr_inf->getCardTextFront();
				//infect the city
				for (int j = 1; j <= i; j++) {
					curr_inf->Infect(remainingDiseaseCubes, city, color);
				}
				//add drawn card to discard pile
				infectiondeck_discard.push_back(curr_inf);
				//remove card from infection deck
				infectiondeck.pop_back();
			}
			i--;
		};
		myfile.close();
	}
	void load_game(){
		string line;
		ifstream myfile("SaveFile.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				cout << line << '\n';
			}
			myfile.close();
		}

		else cout << "Unable to open file";
	}
};