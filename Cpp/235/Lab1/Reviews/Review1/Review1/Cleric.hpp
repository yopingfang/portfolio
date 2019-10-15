//
//  Cleric.hpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 7/2/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#ifndef Cleric_hpp
#define Cleric_hpp

#include <stdio.h>
#include "Fighter.hpp"

class Cleric : public Fighter {
public:
    Cleric(std::string name = "", int maxHp = 1, int strength = 1, int speed = 1, int magic = 1);
    int getDamage();
    void reset();
    bool useAbility();
    void regenerate();
    
    static const char TYPE_CODE = 'C';
    
private:
    int mana = 1;
    int getMaxMana() const;
};
#endif /* Cleric_hpp */
