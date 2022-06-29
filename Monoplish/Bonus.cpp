#include "Bonus.h"


Bonus::Bonus() : CSquare(4 , "Bonus") {
	bonuslist[0].bonusline = "Find some money";
	bonuslist[0].reward = 20;
	bonuslist[1].bonusline = "Win a coding competition";
	bonuslist[1].reward = 50;
	bonuslist[2].bonusline = "Receive a rent rebate";
	bonuslist[2].reward = 100;
	bonuslist[3].bonusline = "Win the lottery";
	bonuslist[3].reward = 150;
	bonuslist[4].bonusline = " Recieve a bequest";
	bonuslist[4].reward = 200;
	bonuslist[5].bonusline = "It's your birthday";
	bonuslist[5].reward = 300;
}

void Bonus::Getbonus(Player* p, int randnum) {
	randnum--;
	cout << bonuslist[randnum].bonusline << " Gain " << bonuslist[randnum].reward << endl;
	p->setMoney(p->getMoney()+ bonuslist[randnum].reward);
}
