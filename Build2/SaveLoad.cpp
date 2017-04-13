#include "SaveLoad.h"

using namespace std;

void Save::setString(const string& s) {
	output = s;
}
void Save::write() {
	ofstream myFile;
	myFile.open("saveFile.txt", ios_base::app);
	myFile << output;
	myFile.close();
}