#include "Robot.h"
#include <cmath>





Robot::Robot()
{
}

int Robot::getDamage()
{
	if (bonusDamage != 0)
	{
		int damage = bonusDamage;
		bonusDamage = 0;
		return damage;
	}
	return strength;
}

void Robot::reset()
{
	currentHP = maxHits;
	energy = origEnergy;
	bonusDamage = 0;

}

void Robot::regenerate()
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

bool Robot::useAbility()
{
	if (energy >= ROBOT_ABILITY_COST)
	{
		double dBonusDamage = static_cast<double>(bonusDamage);
		double dStrength = static_cast<double>(strength);
		double dEnergy = static_cast<double>(energy);
		double dOrigEnergy = static_cast<double>(origEnergy); 
		double temp = dEnergy / dOrigEnergy;
		double temp2 = pow(temp, 4);
		dBonusDamage = dStrength + (dStrength  * temp2);
		energy -= ROBOT_ABILITY_COST;
		bonusDamage = static_cast<int>(dBonusDamage);
		
		return true;
	}
	return false;
}



