//
//  Arena.hpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 6/29/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#ifndef Arena_hpp
#define Arena_hpp

#include <stdio.h>
#include "ArenaInterface.hpp"
#include "FighterInterface.hpp"
#include "Fighter.hpp"

class Arena : public ArenaInterface {
public:
    bool addFighter(std::string info);
    bool removeFighter(std::string name);
    FighterInterface* getFighter(std::string name);
    int getSize() const;
private:
    std::vector<FighterInterface*>fighters;
};

#endif /* Arena_hpp */
