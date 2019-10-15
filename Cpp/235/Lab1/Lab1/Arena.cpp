//Created by pp
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include"Arena.h"
#include"Fighters.h"
#include"Archer.h"
#include"Cleric.h"
#include"Robot.h"

using namespace std;

Arena::Arena() { //sets up the NULL option for getFighter

	Fighters* ptr = new Archer; //picked a random class any will do
	ptr->setName("NULL");
	roster.push_back(ptr);
	return;
}
bool Arena::addFighter(string info) {

	istringstream inSS(info);

	string fName;
	inSS >> fName;
	for (unsigned int i = 0; i < roster.size(); i++) {
		if (fName == roster.at(i)->getName()) return false;
	}
	string fType;
	inSS >> fType;

	Fighters* ptr = nullptr;
	if (fType == "A") {
		ptr = new Archer;
	}
	else if (fType == "C") {
		ptr = new Cleric;
	}
	else if (fType == "R") {
		ptr = new Robot;
	}
	else {
		return false;
	}
	ptr->setName(fName);
	ptr->setType(fType);
	int fNum[4];
	for (int i = 0; i < 4; i++) {
		inSS >> fNum[i];
		if (inSS.fail()) {
			inSS.clear();
			delete ptr;
			return false;
		}
		if (fNum < 0) {
			delete ptr;
			return false;
		}
	}
	int testNum;
	inSS >> testNum;
	if (inSS) {
		delete ptr;
		return false;
	}
	ptr->setHP(fNum[0]);
	ptr->setStr(fNum[1]);
	ptr->setSpd(fNum[2]);
	ptr->setMP(fNum[3]);
	ptr->reset();//initializes current HP and other stats (energy, mana, etc)

	roster.push_back(ptr);
	return true;
}
bool Arena::removeFighter(string name) {

	Fighters* ptr = nullptr;
	for (unsigned int i = 0; i < roster.size(); i++) {
		if (roster.at(i)->getName() == name) {
			ptr = roster.at(i);
			delete ptr; //catches memory leaks
			roster.erase(roster.begin() + i);
			return true;
		}
	}
	return false;
}
Fighters* Arena::getFighter(string name) {
	Fighters* fighter;
	for (unsigned int i = 0; i < roster.size(); i++) {
		if (roster.at(i)->getName() == name) {
			fighter = roster.at(i);
			return fighter;
		}
	}
	return (roster.at(0)); //NULL option created in constructor
}
int Arena::getSize() const {
	return (roster.size() - 1); //-1 compensates for NULL option
}
void Arena::emptyRoster() { //catches memory leaks in any remaining fighters on roster
	Fighters* ptr = nullptr;
	for (unsigned int i = 0; i < roster.size(); i++) {
		ptr = roster.at(i);
		delete ptr;
	}

	return;
}
std::string Arena::removeSpace(std::string info) {
	string newInfo = info;
	if (info[0] == '\n') {
		newInfo = info.substr(1, info.size() - 1);
	}
	int size = newInfo.size();
	if (newInfo[size - 1] == '\n') {
		newInfo = newInfo.substr(0, size - 1);
	}
	return newInfo;
}
bool Arena::isPresent(string name) const {
	for (unsigned int i = 0; i < roster.size(); i++) {
		if (name == roster.at(i)->getName()) return true;
	}
	return false;
}
