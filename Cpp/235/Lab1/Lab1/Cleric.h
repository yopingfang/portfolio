//Created by pp
#ifndef CLERIC_H
#define CLERIC_H

#include"Fighters.h"

class Cleric : public Fighters {
public:
	Cleric();
	int getDamage();
	void reset();
	bool useAbility();
	void regenerate();
private:
	int cMana;
};

#endif
