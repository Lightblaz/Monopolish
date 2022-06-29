#include "Penalty.h"

Penalty::Penalty() : CSquare(5, "Penalty") {
	penaltylist[0].penaltyline = "Buy a coffee in Starbuks";
	penaltylist[0].cost = 20;
	penaltylist[1].penaltyline = "Pay your broadband bill";
	penaltylist[1].cost = 50;
	penaltylist[2].penaltyline = "Visit the SU shop for food";
	penaltylist[2].cost = 100;
	penaltylist[3].penaltyline = "Buy an assignment solution";
	penaltylist[3].cost = 150;
	penaltylist[4].penaltyline = "Go for a romantic meal";
	penaltylist[4].cost = 200;
	penaltylist[5].penaltyline = "Pay some univeristy fees";
	penaltylist[5].cost = 300;
}

void Penalty::GetPenalty(Player* p, int randnum) {
	randnum--;
	cout << penaltylist[randnum].penaltyline << " Lost " << penaltylist[randnum].cost << endl;
	p->setMoney(p->getMoney() - penaltylist[randnum].cost);
}