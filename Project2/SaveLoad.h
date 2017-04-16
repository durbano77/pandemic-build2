#include <iostream>
#include <fstream>
#include <istream>
#include <vector>
#include <algorithm>
#include <CString>
#include "PlayerView.h"
#include "CardsHeaders.h"
#include "Global.h"
#include <afxwin.h>
#define _AFXDLL

using namespace std;

class Save{
private:
	CString output;
public:
	void setCString(const CString& s);
	void write();
};