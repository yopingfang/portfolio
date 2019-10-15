#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include "Fighter.h"

const int ROBOT_ENERGY_CONST = 2;

class Robot : public Fighter
{
private:
	int energy;
	int origEnergy;
	int bonusDamage;

public:

	Robot();
	Robot(std::string m_name, char m_type, int maxHits, int m_strength, int m_speed, int m_magic)
	{
		name = m_name;
		type = m_type;
		this->maxHits = maxHits;
		strength = m_strength;
		speed = m_speed;
		magic = m_magic;
		
		currentHP = maxHits; 
	    energy = ROBOT_ENERGY_CONST * magic;
	    origEnergy = energy;
		bonusDamage = 0;
	}

	int getDamage();

	void reset();

	void regenerate();

	bool useAbility();

	
};

#endif 



