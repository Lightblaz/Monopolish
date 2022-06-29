#include "Property.h"
#include <iostream>
using namespace std;
void Property::setowner(string own) {
	owner = own;
}

int Property::getcost() {
	return cost;
}

int Property::getrent() {
	return rent;
}

string Property::getowner() {
	return owner;
}

int Property::getgroup() {
	return Cgroup;
}

string Property::getPname() {
	return ProName;
}
Property::~Property() {
	
}

Property::Property(string pname, string ownname, int cst, int ren, int group) : CSquare(1 , pname) {
	ProName = pname;
	owner = ownname;
	cost = cst;
	rent = ren;
	Cgroup = group;
}
