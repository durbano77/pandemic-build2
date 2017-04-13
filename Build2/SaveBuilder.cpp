#include "SaveBuilder.h"

using namespace std;

Save* SaveBuilder::getSave() {
	return m_save;
}

void SaveBuilder:: createNewSave() {
	m_save = new Save;
}