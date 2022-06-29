#include "CSquare.h"
#include <string>
using namespace std;

int CSquare::GetNumtype() {
	return Numtype;
}

string CSquare::GetSName() {
	return Sname;
}
CSquare::CSquare(int num , string name) {
	//cout << num << endl;
	Numtype = num;
	Sname = name;
}

int CSquare::getcost() {
	return 0;
}

int CSquare::getrent() {
	return 0;
}

string CSquare::getowner() {
	return " ";
}

int CSquare::getgroup() {
	return 0;
}

string CSquare::getPname() {
	return " ";
}

void CSquare::setowner(string own) {

}

CSquare::~CSquare() {

}

string CSquare::getstationowner() {
	return " ";
}

void CSquare::setstationowner(string own) {

}