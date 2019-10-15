//Created by pp
#include "Archer.h"
#include <iostream>
#include <sstream>
using namespace std;

Archer::Archer() {
	aCurSpd = fSpd;
	return;
}
int Archer::getDamage() {
	return (aCurSpd);
}
void Archer::reset() {
	fCurHP = fMaxHP;
	aCurSpd = fSpd;
	return;
}
bool Archer::useAbility() {
	++aCurSpd;
	return true;
}
void Archer::takeDamage(int damage) {
	if ((damage - aCurSpd / 4) >= 1) {
		fCurHP -= (damage - aCurSpd / 4);
	}
	else {
		fCurHP -= 1;
	}
	return;
}
string Archer::toString() {
	if (fName == "NULL") {
		return "NULL";
	}
	else {
		ostringstream oss;
		oss << endl << fName << " " << fCurHP << " " << fMaxHP
			<< " " << fStr << " " << aCurSpd << " " << fMP << endl;
		return oss.str();
	}
}