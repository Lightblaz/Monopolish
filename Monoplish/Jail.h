#pragma once
#include <string>
#include "CSquare.h"
using namespace std;
class Jail : public CSquare
{
public:
	Jail() :CSquare(6, "Jail") {};
	void Visiting(string name);
	void InJail(string name);
};

