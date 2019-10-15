//
//  Robot.hpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 6/29/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#ifndef Robot_hpp
#define Robot_hpp

#include <stdio.h>
#include "Fighter.hpp"

class Robot : public Fighter {
public:
    Robot(std::string name = "", int maxHp = 1, int strength = 1, int speed = 1, int magic = 1);
    int getDamage();
    void reset();
    bool useAbility();
    
    static const char TYPE_CODE = 'R';
    
private:
    int energy = 1;
    int bonusDamage = 0;
    int getMaxEnergy() const;
};
#endif /* Robot_hpp */
