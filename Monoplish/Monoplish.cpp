#include <iostream>
#include <fstream>
#include <string>
#include "CSquare.h"
#include "Player.h"
#include "Monopoly.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;

//const char POUND = 156;
int main()
{
	int roll;								//stores the value of the roll
	//int p1round = 0 , p2round = 0;			//which round the players are currently at
	bool turn = true;						//whose turn is it
	//Monopoly* mon = new Monopoly;
	unique_ptr <Monopoly> mon = make_unique<Monopoly>();
	//unique_ptr <Bonus> bon = make_unique<Bonus>();
	mon->Welcome();
	mon->ReadFile();
	Player* p1 = new Player("Dog");
	Player* p2 = new Player("Car");
	Player* p3 = new Player("Shoe");
	Player* p4 = new Player("Hat");
	srand(mon->GetSeed());					//using seed this generates the random numbers

	bool p1active = true , p2active = true , p3active = true , p4active = true;
	int bankruptplayers = 0;

	for (int i = 0; i < 20; i++) {
		cout <<endl<< "------------------------ROUND " << i << "--------------------" << endl;
		if (p1active) {
			roll = mon->ThrowDice();
			p1->RollDice(roll);
			cout << p1->getPname() << " lands on " << mon->GetSquareTile(p1->getPosition()) << endl;
			mon->checkproperty(p1, p2, p3, p4);
			//cout << p1->getPname() << " has " <<POUND << p1->getMoney() << endl;
			if (!mon->lowbalance(p1)) {
				p1active = false;
				bankruptplayers++;
				cout << p1->getPname() << " bankrupt" << endl;
			}
			cout << p1->getPname() << " has " <<POUND<< p1->getMoney() << endl;
			cout << endl;
		}
		if (p2active) {
			roll = mon->ThrowDice();
			p2->RollDice(roll);
			cout << p2->getPname() << " lands on " << mon->GetSquareTile(p2->getPosition()) << endl;
			mon->checkproperty(p2, p1, p3, p4);
			//cout << p2->getPname() << " has "<<POUND << p2->getMoney() << endl;
			if (!mon->lowbalance(p2)) {
				p2active = false;
				bankruptplayers++;
				cout << p2->getPname() << " bankrupt" << endl;
			}
			cout << p2->getPname() << " has "<<POUND<< p2->getMoney() << endl;
			cout << endl;
		}

		if (p3active) {
			roll = mon->ThrowDice();
			p3->RollDice(roll);
			cout << p3->getPname() << " lands on " << mon->GetSquareTile(p3->getPosition()) << endl;
			mon->checkproperty(p3, p2, p1, p4);
			//cout << p3->getPname() << " has " <<POUND<< p3->getMoney() << endl;
			if (!mon->lowbalance(p3)) {
				p3active = false;
				bankruptplayers++;
				cout << p3->getPname() << " bankrupt" << endl;
			}
			cout << p3->getPname() << " has "<<POUND<< p3->getMoney() << endl;
			cout << endl;
		}

		if (p4active) {
			roll = mon->ThrowDice();
			p4->RollDice(roll);
			cout << p4->getPname() << " lands on " << mon->GetSquareTile(p4->getPosition()) << endl;
			mon->checkproperty(p4, p1, p2, p3);
			//cout << p4->getPname() << " has " <<POUND<< p4->getMoney() << endl;
			if (!mon->lowbalance(p4)) {
				p4active = false;
				bankruptplayers++;
				cout << p4->getPname() << " bankrupt" << endl;
			}
			cout << p4->getPname() << " has " <<POUND<< p4->getMoney() << endl;
			cout << endl;
		}

		cout << p1->getPname() << " has " << POUND << p1->getMoney() << endl;
		cout << p2->getPname() << " has " << POUND << p2->getMoney() << endl;
		cout << p3->getPname() << " has " << POUND << p3->getMoney() << endl;
		cout << p4->getPname() << " has " << POUND << p4->getMoney() << endl;
		cout << endl;

		if (bankruptplayers == 3) {
			break;
		}

	}

	cout << "Game Over" << endl;
	cout << p1->getPname() << " has " <<POUND<< p1->getMoney() << endl;
	cout << p2->getPname() << " has " <<POUND<< p2->getMoney() << endl;
	cout << p3->getPname() << " has " <<POUND<< p3->getMoney() << endl;
	cout << p4->getPname() << " has " <<POUND<< p4->getMoney() << endl;

	mon->winner(p1, p2, p3, p4);
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	mon.reset();

	_CrtDumpMemoryLeaks();
}