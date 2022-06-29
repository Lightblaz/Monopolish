#include "Jail.h"
#include <iostream>
using namespace std;

void Jail::Visiting(string name) {
	cout << name << " is just visiting" << endl;
}

void Jail::InJail(string name) {
	cout << name << " lands on Jail" << endl;
}