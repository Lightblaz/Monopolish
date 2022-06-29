#include "Station.h"

using namespace std;
void Station::payticket(Player* p1, Player* p2) {
	p1->setMoney(p1->getMoney() - 10);
	cout << p1->getPname() << " pays 10 for ticket" << endl;
	p2->setMoney(p2->getMoney() + 10);
}

string Station::getstationowner() {
	return owner;
}

Station::Station(string own , string sqname) : CSquare(3 , sqname){
	owner = own;
}

void Station::setstationowner(string own) {
	owner = own;
}
