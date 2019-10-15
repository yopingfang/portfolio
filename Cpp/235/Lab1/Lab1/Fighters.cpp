//Created by pp
#include"Fighters.h"
#include<iostream>
#include<sstream>
using namespace std;

Fighters::Fighters() {
	fCurHP = fMaxHP;
	return;
}
void Fighters::setName(string name) {
	fName = name;
	return;
}
void Fighters::setType(string type) {
	fType = type;
	return;
}
void Fighters::setHP(int HP) {
	fMaxHP = HP;
	return;
}
void Fighters::setStr(int str) {
	fStr = str;
	return;
}
void Fighters::setSpd(int spd) {
	fSpd = spd;
	return;
}
void Fighters::setMP(int MP) {
	fMP = MP;
	return;
}
string Fighters::getName() const {
	return fName;
}
string Fighters::getType() const {
	return fType;
}
int Fighters::getMaximumHP() const {
	return fMaxHP;
}
int Fighters::getCurrentHP() const {
	return fCurHP;
}
int Fighters::getStrength() const{
	return fStr;
}
int Fighters::getSpeed() const{
	return fSpd;
}
int Fighters::getMagic() const{
	return fMP;
}
void Fighters::takeDamage(int damage) {
	if ((damage - fSpd / 4) >= 1) {
		fCurHP -= (damage - fSpd / 4);
	}
	else {
		fCurHP -= 1;
	}
	return;
}
void Fighters::regenerate() {
	if (fStr / 6 >= 1) {
		fCurHP += (fStr / 6);
	}
	else {
		fCurHP += 1;
	}
	if (fCurHP > fMaxHP) {
		fCurHP = fMaxHP;
	}
	return;
}
string Fighters::toString() {
	if (fName == "NULL") {
		return "NULL";
	}
	else {
		ostringstream oss;
		oss << fName << " " << fCurHP << " " << fMaxHP
			<< " " << fStr << " " << fSpd << " " << fMP;
		string info;
		info = oss.str();
		return info;
	}
}