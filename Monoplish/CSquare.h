#pragma once
#include <iostream>
#include <string>
using namespace std;
class CSquare
{
private:
	int Numtype;	//type of square
	string Sname;	//name of square
public:
	CSquare(int num, string name);
	int GetNumtype();
	string GetSName();
	virtual ~CSquare();
	virtual void setowner(string own);
	virtual int getcost();
	virtual int getrent();
	virtual string getowner();
	virtual int getgroup();
	virtual string getPname();
	virtual string getstationowner();
	virtual void setstationowner(string own);
};

