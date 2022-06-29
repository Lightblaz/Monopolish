#pragma once
#include <iostream>
#include "CSquare.h"
#include "Player.h"
#include <string>
class Station : public CSquare 
{
private:
	string owner;
public:
	Station(string own, string Sqname);
	void payticket(Player* p1, Player* p2);
	string getstationowner();
	void setstationowner(string own);
};

