#pragma once
#include "Player.h"
#include "CSquare.h"
class GoToJail : public CSquare
{
public:
	GoToJail() :CSquare(7, "Go to Jail") {};
	void landJail(Player* p);
};

