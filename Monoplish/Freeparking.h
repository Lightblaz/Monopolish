#pragma once
#include "CSquare.h"
#include "Player.h"
class Freeparking : public CSquare 
{

public:
	Freeparking() : CSquare(8, "Free parking") {};
	void Displaypark(Player* p);
};

