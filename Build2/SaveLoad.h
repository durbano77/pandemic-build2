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
private:
	string output;
public:
	void setString(const string& s) {
		output = s;
	}
	void write() {
		ofstream myFile;
		myFile.open("saveFile.txt", ios_base::app);
		myFile << output;
	}
};