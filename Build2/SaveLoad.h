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
	void setString(const string& s);
	void write();
};