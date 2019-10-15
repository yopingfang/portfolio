#include "Archer.h"

Archer::Archer()
{
}

int Archer::getDamage()
{
	return speed;
}

void Archer::reset()
{
	currentHP= maxHits;
	speed = getOrigSpeed();
}

void Archer::regenerate()
{
	  
	if (strength / 6 > 0)
	{
		currentHP += (strength / 6);
	}
	else
	{
		currentHP += 1;
	}
	if (currentHP > maxHits)
	{
		currentHP = maxHits;
	}
}

bool Archer::useAbility()
{
	speed += 1;
	return true;
}

int Archer::getOrigSpeed()
{
	return originalSpeed;
}

void Archer::setOrigSpeed(int newOrigSpeed)
{
	originalSpeed = newOrigSpeed;
}

