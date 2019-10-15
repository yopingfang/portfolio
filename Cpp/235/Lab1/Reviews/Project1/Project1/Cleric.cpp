#include "Cleric.h"


Cleric::Cleric()
{
}

int Cleric::getDamage()
{
	return magic;
}



void Cleric::reset()
{
	currentHP = maxHits;
	mana = origMana;
}

void Cleric::regenerate()
{
	if (magic / 5 >= 1)
	{
		mana += (magic / 5);
	}
	else
	{
		mana += 1;
	}
	if (mana > origMana)
	{
		mana = origMana;
	}

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

bool Cleric::useAbility()
{
	const int CLERIC_CONST = 3;
	if (mana >= CLERIC_ABILITY_COST)
	{
		if ((magic / CLERIC_CONST) >= 1)
		{
			currentHP += magic / CLERIC_CONST;
		}
		else
		{
			currentHP += 1;
		}
		if (currentHP > maxHits)
		{
			currentHP = maxHits;
		}
		mana -= CLERIC_ABILITY_COST;
		return true;
	}
	return false;
}

int Cleric::getOrigSpeed()
{
	return 0;
}

void Cleric::setOrigSpeed(int newOrigSpeed)
{
}



