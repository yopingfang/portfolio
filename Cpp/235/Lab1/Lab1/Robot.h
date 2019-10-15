//Created by pp
#ifndef ROBOT_H
#define ROBOT_H

#include"Fighters.h"

class Robot : public Fighters{
public:
	Robot();
	int getDamage();
	void reset();
	bool useAbility();
private:
	double rCurEnergy;
	double rMaxEnergy;
	int rExtraDamage;
	int rTotalDamage;
};

#endif