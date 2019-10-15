#ifndef ARCHER_HPP_
#define ARCHER_HPP_

#include "Fighter.h"


class Archer : public Fighter
{
private:
	int originalSpeed;

public:

	Archer();
	Archer(std::string m_name, char m_type, int maxHits, int m_strength, int m_speed, int m_magic)
	{
		name = m_name;
		type = m_type;
		this->maxHits = maxHits;
		strength = m_strength;
		speed = m_speed;
		magic = m_magic;
		originalSpeed = m_speed;
		currentHP = maxHits;
	}

	int getDamage();
	    
	void reset();

	void regenerate();

	bool useAbility();

	int getOrigSpeed();

	void setOrigSpeed(int newOrigSpeed);
	
};

#endif 



