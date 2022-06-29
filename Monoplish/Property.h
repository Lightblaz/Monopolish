#pragma once
#include <iostream>
using namespace std;
#include "CSquare.h"

class Property : public CSquare
{
private:
	string ProName;
	string owner;
	int cost;
	int rent;
	int Cgroup;
public:
	//Property(string pname, string ownname, int cst, int ren, int group) : ProName(pname), owner(ownname), cost(cst), rent(ren), Cgroup(group) , CSquare(1 , pname) {};
	Property(string pname, string ownname, int cst, int ren, int group);
	void setowner(string own);
	int getcost();
	int getrent();
	string getowner();
	int getgroup();
	string getPname();
	~Property();
};


