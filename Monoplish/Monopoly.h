#pragma once
#include "CSquare.h"
#include "Property.h"
#include "Player.h"
#include "Jail.h"
#include "GoToJail.h"
#include "Station.h"
#include "Freeparking.h"
#include <iostream>
#include <memory>
#include "Bonus.h"
#include "Penalty.h"
#include <vector>
typedef vector <CSquare*> Vec;
const char POUND = 156;
using namespace std;
class Monopoly : public CSquare
{
private:
	//CSquare* CS[26];
	Vec CS;
public:
	void ReadFile();
	int ThrowDice();
	int GetSeed();
	void Welcome();
	Monopoly();
	~Monopoly();
	void Inialisizearray();
	string GetPropertyName(string Line);
	string GetSquareName(string line);
	string GetSquareTile(int pos);			//gets the tile name where the position is

	bool housefree(int tilenum , string playername);
	int proinfo(string line , int spacenum);
	void buyhouse(Player* p1);
	//void payrent(string pname , int tilenum, Player* p, int& amount);
	void payrent(Player* p1 , Player* p2);
	//void checkproperty(Player* p1 , Player* p2 , Monopoly* mon);
	void checkproperty(Player* p1, Player* p2, Player* p3 , Player* p4);

	bool stationfree(Player* p);
	void buystation(Player* p);
	void payticket(Player* p1, Player* p2);
	bool checkpropertycolor(string ownername,int colorgroup);
	int findlowhouse(string ownername); 
	bool lowbalance(Player* p);
	void sellproperty(Player* p , int squarenum);
	void buypropertyback(Player* p, int squarenum);			//buy the mortgaged house back from the bank
	Player* Gethouseowner(Player* p , Player* p2 , Player* p3, string ownername);
	void winner(Player* p1, Player* p2, Player* p3, Player* p4);
};

