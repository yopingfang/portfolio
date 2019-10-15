//
//  Cleric.cpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 7/2/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#include "Cleric.hpp"
Cleric::Cleric(std::string name, int maxHp, int strength, int speed, int magic) : Fighter(name, maxHp, strength, speed, magic) {
    this->mana = this->getMaxMana();
};

int Cleric::getDamage() {
    int result = this->magic;
    result = (result < 1) ? 1 : result;
    return result;
};
void Cleric::reset(){
    Fighter::reset();
    this->mana = this->getMaxMana();
};
bool Cleric::useAbility() {
    if (this->mana >= CLERIC_ABILITY_COST) {
        int tempHp = this->currentHp;   //temp variable since we cant have currentHp go over maxHp, even temporarily
        tempHp += int((1.0 / 3.0) * this->magic);
        tempHp = (tempHp >= 1) ? tempHp: 1;
        this->currentHp = (tempHp > this->getMaximumHP()) ? this->getMaximumHP() : tempHp;
        this->mana -= CLERIC_ABILITY_COST;
        return true;
    }
    else {
        return false;
    }
};
void Cleric::regenerate() {
    Fighter::regenerate();
    int manaBoost = 1;
    manaBoost = (int(this->magic * (1.0 / 5.0)) >= 1) ? int(this->magic * (1.0 / 5.0)) : 1;
    this->mana = ((this->mana + manaBoost) > this->getMaxMana()) ? getMaxMana() : this->mana + manaBoost;
}
int Cleric::getMaxMana() const {
    return 5 * this->magic;
};
