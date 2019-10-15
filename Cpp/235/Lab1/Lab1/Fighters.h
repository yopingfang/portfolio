//Created by pp
#ifndef FIGHTERS_H
#define FIGHTERS_H

#include"FighterInterface.h"

class Fighters : public FighterInterface {
public:
	Fighters();
	void setName(std::string name);
	void setType(std::string type);
	void setHP(int HP);
	void setStr(int str);
	void setSpd(int spd);
	void setMP(int MP);
	std::string getName() const;
	std::string getType() const;
	int getMaximumHP() const;
	int getCurrentHP() const;
	int getStrength() const;
	int getSpeed() const;
	int getMagic() const;
	virtual void takeDamage(int damage);
	virtual void regenerate();
	virtual std::string toString();
	virtual int getDamage() = 0;
	virtual void reset() = 0;
	virtual bool useAbility() = 0;
protected:
	std::string fName;
	std::string fType;
	int fMaxHP;
	int fCurHP;
	int fStr;
	int fSpd;
	int fMP;
};

#endif
