#pragma once
#include <iostream>
#include <string>
using namespace std;
class Player
{
private:
	string Pname;
	int money;
	int position;
public:
	Player(string name);
	~Player();
	string getPname();
	int getMoney();
	int getPosition();
	void setMoney(int money);
	void setPosition(int position);
	void RollDice(int roll);
	void UpdataPosition(int roll);
};

