//
//  Robot.cpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 6/29/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#include "Robot.hpp"
Robot::Robot(std::string name, int maxHp, int strength, int speed, int magic) : Fighter(name, maxHp, strength, speed, magic) {
    this->energy = this->getMaxEnergy();
};

int Robot::getDamage() {
    int result = this->strength + this->bonusDamage;
    result = (result < 1) ? 1 : result;
    this->bonusDamage = 0;
    return result;
};
void Robot::reset() {
    Fighter::reset();
    this->energy = this->getMaxEnergy();
    this->bonusDamage = 0;
};
bool Robot::useAbility() {
    if (this->energy >= ROBOT_ABILITY_COST) {
        this->bonusDamage = int(double(this->strength) * std::pow((double(this->energy) / double(this->getMaxEnergy())), 4.0));
        this->energy -= ROBOT_ABILITY_COST;
        return true;
    }
    else {
        return false;
    }
};
int Robot::getMaxEnergy() const {
    return 2 * this->magic;
}
