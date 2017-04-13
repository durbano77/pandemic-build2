#include "SaveLoad.h"

using namespace std;

class SaveBuilder {
protected:
	Save* m_save;
public:
	Save* getSave() {
		return m_save;
	}
	void createNewSave() {
		m_save = new Save;
	}
	virtual void buildString(Player* p) = 0;
};