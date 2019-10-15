//
//  Fighter.cpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 6/29/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#include "Fighter.hpp"
#include "Robot.hpp"
#include "Archer.hpp"
#include "Cleric.hpp"

Fighter::Fighter(std::string name, int maxHp, int strength, int speed, int magic) {
    this->name = name;
    this->maxHp = maxHp;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    this->currentHp = maxHp;
}

FighterInterface* Fighter::createFighterFromStream(std::istringstream& userInput) {
    std::string name;
    char type;
    int maxHp;
    int strength;
    int speed;
    int magic;
    try {
        if (userInput >> name) {}
        else {throw(1);}
        if (userInput >> type) {}
        else {throw (1);}
        if (userInput >> maxHp) {}
        else {throw (1);}
        if (userInput >> strength) {}
        else {throw (1);}
        if (userInput >> speed) {}
        else {throw (1);}
        if (userInput >> magic) {}
        else {throw (1);}
        
        std::string next;
        userInput >> next;
        if(std::any_of(std::begin(next), std::end(next), ::isascii)) {throw 2;}    //check if extra data was included past what we needed
         
        switch(type) {
            case Robot::TYPE_CODE: return new Robot(name, maxHp, strength, speed, magic);
                break;
            case Archer::TYPE_CODE: return new Archer(name, maxHp, strength, speed, magic);
                break;
            case Cleric::TYPE_CODE: return new Cleric(name, maxHp, strength, speed, magic);
                break;
            default: throw(3);
        }
    }
    catch (...) {
        return nullptr;
    }
}

std::string Fighter::getName() const {
    return this->name;
}
int Fighter::getMaximumHP() const {
    return this->maxHp;
};
int Fighter::getCurrentHP() const {
    return this->currentHp;
};
int Fighter::getStrength() const {
    return this->strength;
};
int Fighter::getSpeed() const {
    return this->speed;
};
int Fighter::getMagic() const {
    return this->magic;
};
void Fighter::takeDamage(int damage) {
    int result = damage - static_cast<int>((1.0/4.0) * this->speed);
    result = (result < 1) ? 1 : result;
    this->currentHp -= result;
};
void Fighter::reset() {
    this->currentHp = this->maxHp;
};
void Fighter::regenerate() {
    int hpBoost = int((1.0/6.0) * this->strength);
    hpBoost = (hpBoost < 1) ? 1 : hpBoost;
    this->currentHp = ((this->currentHp + hpBoost) > this->getMaximumHP()) ? this->getMaximumHP() : (this->currentHp + hpBoost);
};
std::string Fighter::toString() {
    using namespace std;
    string result = this->name + " " + to_string(this->currentHp) + " " + to_string(this->maxHp) + " " + to_string(this->strength) + " " + to_string(this->speed) + " " + to_string(this->magic);
    return result;
};

