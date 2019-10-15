//Created by pp
#ifndef ARENA_H
#define ARENA_H

#include "ArenaInterface.h"
#include "Fighters.h"
#include<vector>

class Arena : public ArenaInterface {
public:
	Arena();
	bool addFighter(std::string info);
	bool removeFighter(std::string name);
	Fighters* getFighter(std::string name);
	int getSize() const;
	void emptyRoster();
	std::string removeSpace(std::string info);
	bool isPresent(std::string name) const;
private:
	std::vector<Fighters*> roster;
};
#endif
