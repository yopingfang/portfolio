//
//  Arena.cpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 6/29/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#include "Arena.hpp"
#include "FighterInterface.hpp"
#include <sstream>
#include <istream>
bool Arena::addFighter(std::string info) {
    bool doInsert = true;
    std::istringstream tempInput(info);
    std::string nameToAdd;
    tempInput >> nameToAdd;
    for (int i = 0; i < fighters.size(); i++) {
        if (fighters.at(i)->getName() == nameToAdd) {
            doInsert = false;
        }
    }
    if (doInsert) {
        std::istringstream userInput(info);
        FighterInterface *tempFighter = Fighter::createFighterFromStream(userInput);
        if (tempFighter) {
            fighters.push_back(tempFighter);
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
bool Arena::removeFighter(std::string name) {
    int itemToErase = -1;
    for (int i = 0; i < fighters.size(); i++) {
        if (fighters.at(i)->getName() == name) {
            itemToErase = i;
        }
    }
    if (itemToErase != -1) {
        delete fighters.at(itemToErase);
        fighters.erase(fighters.begin() + itemToErase);
        return true;
    }
    else {
        return false;
    }
}
FighterInterface* Arena::getFighter(std::string name) {
    for (int i = 0; i < fighters.size(); i++) {
        if (fighters.at(i)->getName() == name) {
            return fighters.at(i);
        }
    }
    return 0;
}
int Arena::getSize() const {
    return int(fighters.size());
}
