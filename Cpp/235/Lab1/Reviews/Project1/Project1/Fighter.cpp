#include "Fighter.h"
#include <sstream>
#include <string>;

//
//Fighter::Fighter()
//{
//	std::string name = "";
//	char type = ' ';
//	int strength = -1;
//	int speed = -1;
//	int magic = -1;
//	int maxHits = -1;
//}

Fighter::Fighter()
{
}

Fighter::Fighter(std::string m_name, char m_type, int m_maxHits, int m_strength, int m_speed, int m_magic)
{
	std::string name = m_name;
	 type = m_type;
	strength = m_strength;
	 speed = m_speed;
	 magic = m_magic;
	 maxHits = m_maxHits;
	 currentHP = maxHits;
}

std::string Fighter::getName() const
{
	
	return name;
}

void Fighter::setName(std::string newName)
{
	name = newName;
}

int Fighter::getMaximumHP() const
{
	return maxHits;
}

void Fighter::setMaximumHP(int newMaxHP)
{
	maxHits = newMaxHP;
}

int Fighter::getCurrentHP() const
{
	return currentHP;
}

void Fighter::setCurrentHP(int newCurrHP)
{
	currentHP = newCurrHP;
}

int Fighter::getStrength() const
{
	return strength;
}

int Fighter::getSpeed() const
{
	return speed;
}

void Fighter::setSpeed(int newSpeed)
{
}

void Fighter::setStrength(int newStrength)
{
	strength = newStrength;
}

int Fighter::getMagic() const
{
	return magic;
}

void Fighter::setMagic(int newMagic)
{
	magic = newMagic;
}

int Fighter::getEnergy() const
{
	return 0;
}

void Fighter::setEnergy(int newEnergy)
{
	energy = newEnergy;
}

void Fighter::setType(char newType)
{
	type = newType;
}

char Fighter::getType() const
{
	return 0;
}

//void Fighter::setOrigSpeed(int newOrigSpeed)
//{
//	originalSpeed = newOrigSpeed;
//}

int Fighter::getOrigSpeed() const
{
	return 0;
}

int Fighter::getDamage()
{
	return 0;
}


void Fighter::takeDamage(int damage)
{
	if ((damage - (speed / 4)) >= 1)
	{
		currentHP = currentHP - (damage - (speed / 4));
	}
	else
	{
		currentHP -= 1;
	}
}

void Fighter::reset()
{
}

void Fighter::regenerate()
{
}

bool Fighter::useAbility()
{
	return false;
}

std::string Fighter::toString()
{
	std::ostringstream oSS;
	oSS  << name << " " << currentHP << " " << maxHits << " " << strength << " " << speed << " " << magic;
	std::string description = oSS.str();
	return description;
}
