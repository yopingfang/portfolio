#ifndef ARENA_H
#define ARENA_HPP_

#include "ArenaInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"
#include <vector> 

class Arena : public ArenaInterface
{
public:
	Arena() {}
	 ~Arena() {}

	 bool addFighter(std::string info);

	 bool removeFighter(std::string name);

	 FighterInterface* getFighter(std::string name);

	 int getSize() const;

	 void quit();

private:
	std::vector <Fighter*> fighters;

};

#endif 


