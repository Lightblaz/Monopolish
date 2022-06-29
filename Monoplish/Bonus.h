#pragma once
#include "CSquare.h"
#include "Player.h"
#include <memory>
using namespace std;
struct bon
{
	string bonusline;
	int reward;
};
class Bonus : public CSquare 
{
private:
	bon bonuslist[6];

public:
	Bonus();
	void Getbonus(Player* p, int randnum);
};

