#pragma once
#include "CSquare.h"
#include "Player.h"
using namespace std;
struct pen
{
	string penaltyline;
	int cost;
};
class Penalty : public CSquare
{
private:
	pen penaltylist[6];

public:
	Penalty();
	void GetPenalty(Player* p, int randnum);
};

