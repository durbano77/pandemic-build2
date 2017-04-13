#include "SaveLoad.h"

using namespace std;

class SaveBuilder {
protected:
	Save* m_save;
public:
	Save* getSave();

	void createNewSave();

	virtual void buildString(Player* p) = 0;
};