#include "Monopoly.h"
#include <iostream>
#include <fstream>
#include <string>
//#include "Player.h"


using namespace std;

int Monopoly::ThrowDice() {					//returns a random number for the dice roll
	//srand(4);
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

int Monopoly::GetSeed() {				//retrives the seed in seed.txt
	string FileLine;
	ifstream f;
	f.open("seed.txt");
	getline(f, FileLine);
	return stoi(FileLine);
}

void Monopoly::Welcome(){
	cout <<"Welcome to Monopol - ish" << endl<<endl;
}
Monopoly::Monopoly(): CSquare(0 , " ") {
//	CSquare* cs = new CSquare(1, "dfd");
}

string Monopoly::GetPropertyName(string Line)			//gets the property name from the line in the monopoly.txt
{
	string pro;		//stores the property name
	int space = 0;	//number of times spaces were encountered
	for (int i = 2; i < Line.length(); i++) {
		if (space != 2) {
			if (Line[i] == ' ') {				//checks if the character taken from the string is empty , if so indicates it's a space and starts adding string from the 2 space
				space++;
			}
			pro = pro + Line[i];				//get's the characters to a string to make the property name		
		}
	}
	return pro;
}

string Monopoly::GetSquareName(string line) {
	string pro;		//stores the property name
	int space = 0;	//number of times spaces were encountered
	for (int i = 2; i < line.length(); i++) {
		pro = pro + line[i];
	}
	return pro;
}

int Monopoly::proinfo(string line, int spacenum) {
	string pro;		//stores the property info , can change depending on the parameters given
	int space = 0;	//number of times spaces were encountered
	for (int i = 2; i < line.length(); i++) {

		if (line[i] == ' ') {
			space++;
			if (space > spacenum) {		
				break;
			}
		}
		else {
			if (space == spacenum) {
				pro = pro + line[i];
			}
		}

		/*if (space != spacenum) {
			if (line[i] == ' ') {
				space++;
			}
			pro = pro + line[i];
		}
		else {
			break;
		}*/
	}
	return stoi(pro);
}

void Monopoly::ReadFile() {
	int count = 0;			//stores the count for the number of tiles
	int tilenum = 0;
	string FileLine , tmp;	//stores a line from the file when reading
	ifstream f;
	f.open("monopoly.txt");

	while (!(f.eof())) {

		getline(f, FileLine);
		//cout << FileLine << endl;
		tmp = FileLine[0];
		tilenum = stoi(tmp);
		if (FileLine[0] == '1') {
			//cout << FileLine[0] << endl;
			//CS[count] = new CSquare(tilenum, GetPropertyName(FileLine));
			//cout << "house price is " << proinfo(FileLine, 2)<<endl;
			 
			//CS[count] = new Property(GetPropertyName(FileLine), "null", proinfo(FileLine, 2), proinfo(FileLine, 3), proinfo(FileLine, 4));

			CS.push_back(new Property(GetPropertyName(FileLine), "null", proinfo(FileLine, 2), proinfo(FileLine, 3), proinfo(FileLine, 4)));
			//P[pcount] = new Property(GetPropertyName(FileLine), "null", proinfo(FileLine, 2), proinfo(FileLine, 3), proinfo(FileLine, 4));
			//cout << CS[count]->GetSName() << " is the name " << endl;
			//cout << GetPropertyName(FileLine) << endl;
		}

		else if (FileLine[0] == '3') {
			//CS[count] = new Station("null" , GetSquareName(FileLine));
			CS.push_back(new Station("null", GetSquareName(FileLine)));
		}
		else {
			//CS[count] = new CSquare(tilenum, GetSquareName(FileLine));
			CS.push_back(new CSquare(tilenum, GetSquareName(FileLine)));
			
			//cout << GetSquareName(FileLine) << endl;
		}
		if (count < 26) {
			count++;
		}
		else {
			break;
		}
		//cout << FileLine[0] << endl;
	}
	f.close();
}

string Monopoly::GetSquareTile(int pos) {
	return CS[pos]->GetSName();
}

Monopoly::~Monopoly() {
	for (int i = 0; i < 26; i++) {
		delete CS[i];
	}
}

void Monopoly::Inialisizearray() {
	for (int i = 0; i < 26; i++) {
		CS[i] = new CSquare(0, " ");
	}
}

bool Monopoly::housefree(int tilenum , string playername) {
	/*for (int i = 0; i < 18; i++) {
		if (P[i]->GetSName() == name) {
			if (P[i]->getowner() != playername) {
				return true;
			}
			else {
				return false;
			}
		}
	}*/
	//cout << "house price is " << CS[tilenum]->getcost() << endl;
	if (CS[tilenum]->GetNumtype() == 1) {			//check if tile is of type property
		if (CS[tilenum]->getowner() == "null") {	//checks if empty tile
			return true;
		}
	}
	return false;
}

void Monopoly::buyhouse(Player* p1) {
	if (p1->getMoney() > 0) {
		int tilenum = p1->getPosition();
		CS[tilenum]->setowner(p1->getPname());
		//amount = amount - CS[tilenum]->getcost();
		p1->setMoney(p1->getMoney() - CS[tilenum]->getcost());
		cout << p1->getPname() << " buys " << CS[tilenum]->GetSName() << " for " <<POUND<< CS[tilenum]->getcost() << endl;
	}
}

void Monopoly::payrent(Player* p1 , Player* p2) {
	int tilenum = p1->getPosition();
	int rent = CS[tilenum]->getrent();
	if (CS[tilenum]->getowner() == p2->getPname()) {
		if (checkpropertycolor(CS[tilenum]->getowner(), CS[tilenum]->getgroup())) {
			rent = rent * 2;
		}
		cout << p1->getPname() << " pays " <<POUND <<rent << " to " << p2->getPname()<< endl;
		p1->setMoney(p1->getMoney() - rent);
		p2->setMoney(p2->getMoney() + rent);
	}
}

void Monopoly::checkproperty(Player* p1, Player* p2 , Player* p3, Player* p4)
{
	int sqnum = findlowhouse(p1->getPname()+"bank");//store the square where the lowest mortgage house price resides
	if (p1->getMoney() > 0 & (sqnum != 0)) {
		if (p1->getMoney() > CS[sqnum]->getcost()) {
			buypropertyback(p1 , sqnum);
		}
	}


	if (CS[p1->getPosition()]->GetNumtype() == 1) {
		if (housefree(p1->getPosition(), p1->getPname())) {
			buyhouse(p1);
		}
		else {
			payrent(p1, Gethouseowner(p2 , p3 , p4  , CS[p1->getPosition()]->getowner()));
		}
	}
	else if (CS[p1->getPosition()]->GetNumtype() == 6) {
		Jail* j = new Jail();
		j->Visiting(p1->getPname());
		delete j;
	}
	else if (CS[p1->getPosition()]->GetNumtype() == 7) {
		GoToJail* GoJail = new GoToJail();
		GoJail->landJail(p1);
		delete GoJail;
	}
	else if (CS[p1->getPosition()]->GetNumtype() == 3) {
		if (stationfree(p1)) {
			buystation(p1);
		}
		else {
			payticket(p1, Gethouseowner(p2 , p3 , p4  , CS[p1->getPosition()]->getowner()));
		}
	}
	else if (CS[p1->getPosition()]->GetNumtype() == 8) {
		Freeparking* Freepark = new Freeparking();
		Freepark->Displaypark(p1);
		delete Freepark;
	}
	else if (CS[p1->getPosition()]->GetNumtype() == 4) {
		//srand(GetSeed());
		unique_ptr <Bonus> bon = make_unique<Bonus>();
		bon->Getbonus(p1, ThrowDice());
	}
	else if (CS[p1->getPosition()]->GetNumtype() == 5) {
		//srand(GetSeed());
		unique_ptr <Penalty> pen = make_unique<Penalty>();
		pen->GetPenalty(p1, ThrowDice());
	}
}


bool Monopoly::stationfree(Player* p) {
	if (CS[p->getPosition()]->getstationowner() == "null") {
		return true;
	}
	return false;
}

void Monopoly::buystation(Player* p) {
	if (p->getMoney() > 0) {
		p->setMoney(p->getMoney() - 200);
		CS[p->getPosition()]->setstationowner(p->getPname());
		cout << p->getPname() << " buys " << CS[p->getPosition()]->GetSName() << endl;
	}
}

void Monopoly::payticket(Player* p1, Player* p2) {
	p1->setMoney(p1->getMoney() - 10);
	cout << p1->getPname() << " pays "<<POUND<<"10 for ticket" << endl;
	p2->setMoney(p2->getMoney() + 10);
}

bool Monopoly::checkpropertycolor(string ownername , int colorgroup) {
	int count = 0;
	bool found = false;
	bool ownerowncolors = false;
	int arrsize = 26;

	for (int i = 0; i < arrsize; i++) {
		count = i;
		if (CS[i]->getgroup() == colorgroup && CS[i]->GetNumtype() == 1) {
			if (CS[i]->getowner() == ownername) {
				cout << ownername << " - " << CS[i]->getPname()<<endl;
				found = true;
			}
			else {
				found = false;
				break;
			}
		}
	}
	return found;




}

int Monopoly::findlowhouse(string ownername) {
	int arrsize = sizeof(CS) / sizeof(CS[0]);
	int lowsquare = 0;
	int lowcost = 999999;

	for (int i = 0; i < arrsize; i++) {
		if (CS[i]->GetNumtype() == 1) {
			if ((CS[i]->getcost() < lowcost) & (CS[i]->getowner() == ownername)) {
				lowcost = CS[i]->getcost();
				lowsquare = i;
			}
		}
	}
	return lowsquare;
}

void Monopoly::sellproperty(Player* p , int squarenum) {
	CS[squarenum]->setowner(p->getPname() + "bank");
	p->setMoney(p->getMoney() + CS[squarenum]->getcost());
	cout << p->getPname() << " sold " << CS[squarenum]->getPname() << " for " <<POUND<< CS[squarenum]->getcost() << endl;
}

bool Monopoly::lowbalance(Player* p) {
	/*if (p->getMoney() < 0) {
		int tilenum = findlowhouse(p->getPname());
		if (tilenum == 0) {
			return false;
		}
		sellproperty(p, tilenum);
	}
	return true;*/

	if (p->getMoney() < 0) {
		int tilenum = findlowhouse(p->getPname());
		while (tilenum != 0)
		{
			sellproperty(p, tilenum);
			if (p->getMoney() > 0) {
				return true;
			}
			tilenum = findlowhouse(p->getPname());
		}
		return false;
	}
	return true;
}

void Monopoly::buypropertyback(Player* p, int squarenum) {
	CS[squarenum]->setowner(p->getPname());
	//amount = amount - CS[tilenum]->getcost();
	p->setMoney(p->getMoney() - CS[squarenum]->getcost());
	cout << p->getPname() << " buys  " << CS[squarenum]->GetSName() << " back for " <<POUND<< CS[squarenum]->getcost() << endl;
}

Player* Monopoly::Gethouseowner(Player* p, Player* p2, Player* p3 , string ownername) {
	if (p->getPname() == ownername) {
		return p;
	}
	else if (p2->getPname() == ownername) {
		return p2;
	}
	else {
		return p3;
	}
}
struct Pdetails
{
	string name;
	int amount;
};

void Monopoly::winner(Player* p1, Player* p2, Player* p3, Player* p4) {
	int amount = -455444;
	int winnernum = 0;
	bool draw = false;
	/*Pdetails* playeramounts[4]{};
	playeramounts[0]->name = p1->getPname();
	playeramounts[0]->amount = p1->getMoney();
	playeramounts[1]->name = p2->getPname();
	playeramounts[1]->amount = p2->getMoney();
	playeramounts[2]->name = p3->getPname();
	playeramounts[2]->amount = p3->getMoney();
	playeramounts[3]->name = p4->getPname();
	playeramounts[3]->amount = p4->getMoney();

	for (int i = 0; i < 4; i++) {
		if (playeramounts[i]->amount == amount) {
			draw = true;
		}else if (playeramounts[i]->amount > amount) {
			amount = playeramounts[i]->amount;
			winnernum = i;
			draw = false;
		}
	}*/

	Pdetails playeramounts[4]{};
	playeramounts[0].name = p1->getPname();
	playeramounts[0].amount = p1->getMoney();
	playeramounts[1].name = p2->getPname();
	playeramounts[1].amount = p2->getMoney();
	playeramounts[2].name = p3->getPname();
	playeramounts[2].amount = p3->getMoney();
	playeramounts[3].name = p4->getPname();
	playeramounts[3].amount = p4->getMoney();

	for (int i = 0; i < 4; i++) {
		if (playeramounts[i].amount == amount) {
			draw = true;
		}
		else if (playeramounts[i].amount > amount) {
			amount = playeramounts[i].amount;
			winnernum = i;
			draw = false;
		}
	}

	if (draw) {
		cout << "There is a draw" << endl;
	}
	else {
		cout << playeramounts[winnernum].name << " is the winner with amount of " <<POUND<< playeramounts[winnernum].amount << endl;
	}
}