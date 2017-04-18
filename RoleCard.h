//**********************************************
//COMP345 BUILD 1
//Winter 2017
//Team Buffalos
//**********************************************
//
//RoleCard.h

#ifndef ROLECARD_H_
#define ROLECARD_H_
#include "Cards.h"

using namespace std;

class RoleCard : public Cards {
private:
    std::string rolename;
public:
    RoleCard();
    RoleCard(std::string rolename, std::string cardtextfront, std::string cardtextback);

	DECLARE_SERIAL(RoleCard);
	void Serialize(CArchive& archive);
};

class DispatcherCard : public RoleCard{
public:
    DispatcherCard();
};

class MedicCard : public RoleCard{
public:
    MedicCard();
};

class ScientistCard : public RoleCard{
public:
    ScientistCard();
};

class ResearcherCard : public RoleCard{
public:
    ResearcherCard();
};

class OperationsexpertCard : public RoleCard{
public:
    OperationsexpertCard();
};

class QuarantinespecialistCard : public RoleCard{
public:
    QuarantinespecialistCard();
};
class ContingencyplannerCard : public RoleCard{
public:
    ContingencyplannerCard();
};

#endif /* ROLECARD_H_ */
