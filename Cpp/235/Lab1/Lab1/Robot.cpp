//Created by pp
#include<iostream>
#include"Robot.h"
using namespace std;

Robot::Robot() {
	rMaxEnergy = fMP * 2;
	rExtraDamage = 0;
	return;
}
int Robot::getDamage() {
	rTotalDamage = fStr + rExtraDamage;
	rExtraDamage = 0;
	return rTotalDamage;
}
void Robot::reset() {
	fCurHP = fMaxHP;
	rMaxEnergy = fMP * 2;
	rCurEnergy = rMaxEnergy;
	rExtraDamage = 0;
	return;
}
bool Robot::useAbility() {
	double energyMult = 0;
	if (rCurEnergy >= ROBOT_ABILITY_COST) {
		energyMult = rCurEnergy / rMaxEnergy;
		rExtraDamage = energyMult * energyMult * energyMult * energyMult * fStr;
		rCurEnergy -= ROBOT_ABILITY_COST;
		return true;
	}
	else {
		return false;
	}
}