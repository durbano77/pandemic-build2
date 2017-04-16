#include "SaveLoad.h"

using namespace std;

#include <afxwin.h>
#define _AFXDLL

class SaveBuilder {
protected:
	Save* m_save;
public:
	Save* getSave();

	void createNewSave();

	virtual void buildCString(Player* p) = 0;
};