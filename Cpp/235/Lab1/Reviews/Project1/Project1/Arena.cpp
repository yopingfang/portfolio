#include "Arena.h"

#include <sstream>
using namespace std;

bool Arena::addFighter(std::string info)
{
	istringstream inSS(info);

	std::string name;
	char type;
	int maxHits;
	int strength;
	int speed;
	int magic;
	string extra = "NONE";

	inSS >> name;
	inSS >> type;
	inSS >> maxHits;
	inSS >> strength;
	inSS >> speed;
	inSS >> magic;
	

	
	if (inSS.fail())
	{
		//std::cout << "NULL";
		inSS.clear();
		return false;
	}
	inSS >> extra;
	if (extra != "NONE")
	{
		//std::cout << "NULL";
		return false;

	}

	for (unsigned int i = 0; i < fighters.size(); i++)
	{
		if ( fighters.at(i)->getName() == name)
		{
			//std::cout << "NULL";
			
			return false;
		}
	}
	if (type == 'A')
	{
		
		Fighter* newFighter = new Archer(name, type, maxHits, strength, speed, magic);
		/*newFighter->setName(name);
		newFighter->setType(type);*/
		
		
		fighters.push_back(newFighter);
		return true;
	}
	else if (type == 'C')
	{
		Fighter* newFighter = new Cleric(name, type, maxHits, strength, speed, magic);
		fighters.push_back(newFighter);
		return true;
	}
	 else if (type == 'R')
	{
		Fighter* newFighter = new Robot(name, type, maxHits, strength, speed, magic);
		fighters.push_back(newFighter);
		return true;
	}
	
	return false;
}

bool Arena::removeFighter(std::string name)
{
	for (unsigned int i = 0; i < fighters.size(); i++)
	{
		if ((fighters.at(i))->getName() == name)
		{
			delete fighters.at(i);
			fighters.erase(fighters.begin() + i);
			return true;
		}
	}
	return false;
}

FighterInterface * Arena::getFighter(std::string name)
{
	
	for (unsigned int i = 0; i < fighters.size(); i++)
	{
		if ((fighters.at(i))->getName() == name)
		{
			/*(fighters.at(i))->toString();*/
			return fighters.at(i);
		}
	}
	return nullptr;
}

int Arena::getSize() const
{
	 
	return fighters.size();
}

void Arena::quit()
{
	for (int i = 0; i < fighters.size(); i++)
	{
		delete fighters.at(i);
	}
	return;
}
