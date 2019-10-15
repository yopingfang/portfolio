//
//  Archer.cpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 7/2/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#include "Archer.hpp"

Archer::Archer(std::string name, int maxHp, int strength, int speed, int magic) : Fighter(name, maxHp, strength, speed, magic) {
    originalSpeed = speed;
};

int Archer::getDamage() {
    int result = this->speed;
    result = (result < 1) ? 1 : result;
    return result;
};
void Archer::reset() {
    Fighter::reset();
    this->speed = this->originalSpeed;
};
bool Archer::useAbility() {
    this->speed++;
    return true;
};
