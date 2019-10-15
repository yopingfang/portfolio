#ifndef CLERIC_HPP_
#define CLERIC_HPP_

#include "Fighter.h"

const int CLERIC_MANA_CONST = 5;

class Cleric : public Fighter
{
private:
	int mana;
	int origMana;

public:

	Cleric();
	Cleric(std::string m_name, char m_type, int maxHits, int m_strength, int m_speed, int m_magic)
	{
		name = m_name;
		type = m_type;
		this->maxHits = maxHits;
		strength = m_strength;
		speed = m_speed;
		magic = m_magic;
		
		currentHP = maxHits;
		mana = CLERIC_MANA_CONST * magic;
		origMana = mana;
	}

	int getDamage();

	void reset();

	void regenerate();

	bool useAbility();

	int getOrigSpeed();

	void setOrigSpeed(int newOrigSpeed);
	
};

#endif 



