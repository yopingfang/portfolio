//
//  Archer.hpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 7/2/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#ifndef Archer_hpp
#define Archer_hpp

#include <stdio.h>
#include "Fighter.hpp"

class Archer : public Fighter {
public:
    Archer(std::string name = "", int maxHp = 1, int strength = 1, int speed = 1, int magic = 1);
    int getDamage();
    void reset();
    bool useAbility();
    
    static const char TYPE_CODE = 'A';
    
private:
    int originalSpeed = 1;
};
#endif /* Archer_hpp */
