#include "Player.h"
#include "Monopoly.h"

Player::Player(string name) {
	Pname = name;
	money = 1500;
	position = 0;
    //Inialisizearray();
}

string Player::getPname() {
    return Pname;
}

int Player::getMoney() {
    return money;
}

int Player::getPosition()  {
    return position;
}

void Player::setMoney(int amount) {
    money = amount;
}

void Player::setPosition(int pos) {
    position = pos;
}

void Player::UpdataPosition( int roll) {
    position += roll;
    if (position > 25) {
        position -= 26;
        cout << "    " << Pname << " passes Go and collects $200" << endl;
        money += 200;
    }
    /*if (housefree(position, Pname , money)) {
        buyhouse(position, Pname, money);
    }
    else {
        p->setMoney(payrent(Pname, position, p->getPname(), money) + p->getMoney());
    }*/

    //cout << Pname << " has " << money << endl;

    
    //cout << Pname << " lands on " << GetSquareTile(position) << endl;
}

void Player::RollDice(int roll) {
    //int roll = ThrowDice();
    cout << Pname << " rolls " << roll << endl;
    UpdataPosition(roll);
}
Player::~Player() {

}

