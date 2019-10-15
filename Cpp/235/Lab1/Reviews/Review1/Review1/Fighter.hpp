//
//  Fighter.hpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 6/29/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#ifndef Fighter_hpp
#define Fighter_hpp

#include <stdio.h>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "FighterInterface.hpp"

class Fighter : public FighterInterface {
public:
    static FighterInterface* createFighterFromStream(std::istringstream& userInput);
//    static const char ROBOT_TYPE = 'R';       we have to include each child class header file anyway in order to be able to create each type
//    static const char ARCHER_TYPE = 'A';
//    static const char CLERIC_TYPE = 'C';
    std::string getName() const;
    int getMaximumHP() const;
    int getCurrentHP() const;
    int getStrength() const;
    int getSpeed() const;
    int getMagic() const;
    virtual int getDamage() = 0;
    void takeDamage(int damage);
    virtual void reset();
    virtual void regenerate();
    virtual bool useAbility() = 0;
    std::string toString();
protected:
    Fighter(std::string name, int maxHp, int strength, int speed, int magic);
    std::string name = "";
    int maxHp = 1;
    int currentHp = maxHp;
    int strength = 1;
    int speed = 1;
    int magic = 1;
};

#endif /* Fighter_hpp */
