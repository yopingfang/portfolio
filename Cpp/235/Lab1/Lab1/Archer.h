//Created by pp
#ifndef ARCHER_H
#define ARCHER_H

#include"Fighters.h"

class Archer : public Fighters {
public:
	Archer();
	int getDamage();
	void reset();
	bool useAbility();
	void takeDamage(int damage);
	std::string toString();
private:
	int aCurSpd;
};
#endif
