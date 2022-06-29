#include "GoToJail.h"

void GoToJail::landJail(Player* p) {
	cout << p->getPname() << " goes to Jail" << endl;
	p->setPosition(6);
	cout << p->getPname() << " pays 50" << endl;
	p->setMoney(p->getMoney() - 50);
}
