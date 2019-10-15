//Created by pp
#include<iostream>
#include "Cleric.h"
using namespace std;

Cleric::Cleric() {
	cMana = fMP * 5;
	return;
}
int Cleric::getDamage() {
	return fMP;
}
void Cleric::reset() {
	fCurHP = fMaxHP;
	cMana = fMP * 5;
	return;
}
bool Cleric::useAbility() {
	if (cMana >= CLERIC_ABILITY_COST) {
		cMana -= CLERIC_ABILITY_COST;
		if (fMP / 3 >= 1) {
			fCurHP += fMP / 3;
		}
		else {
			fCurHP++;
		}
		if (fCurHP > fMaxHP) {
			fCurHP = fMaxHP;
		}
		return true;
	}
	else {
		return false;
	}
}
void Cleric::regenerate() {
	Fighters::regenerate();
	if (cMana < (fMP * 5)) {
		if (fMP / 5 >= 1) {
			cMana += fMP / 5;
		}
		else {
			cMana++;
		}
	}
	return;
}