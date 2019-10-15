//
//  main.cpp
//  CS 235 Lab 01 - RPG
//
//  Created by Benson Kane on 6/29/18.
//  Copyright © 2018 Benson Kane. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "Fighter.hpp"
#include "Arena.hpp"
#include "Robot.hpp"
#include "Cleric.hpp"
#include "Archer.hpp"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif


/**
 * Trim given characters from right end of string
 * @param s String to trim from
 * @param t Array of characters to be stripped from string
 */
inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v") {  //https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

/**
 * Convert boolean to string representation
 * @return String representation of boolean
 */
std::string boolToStr(bool val){
    std::string result = (val) ? "True" : "False";
    return result;
}

/**
 * Wrapper function for addFighter result
 * @return String representation of result of addFighter operation
 */
std::string addFighterResultFormatter(bool val) {
    std::string result = (val) ? "Added" : "Invalid";
    return result;
}

/**
 * Wrapper function for resetFighter result
 * @return String representation of result of resetFighter operation
 */
std::string resetFighterResultFormatter(bool val) {
    std::string result = (val) ? "Success" : "NULL";
    return result;
}

using namespace std;

/**
 * Function to simulate battle between fighters
 * @param out The ostream to which to write results
 * @param fighter1 First fighter in battle
 * @param fighter2 Second fighter in battle
 * @param useAbility flag variable whether to run regenerate and useAbility in battle
 */
void runBattle(ostream& out, FighterInterface *fighter1, FighterInterface *fighter2, bool useAbility = true) {
    out << endl;
    out << "  " << fighter1->toString() << endl;
    out << "  " << fighter2->toString() << endl << endl;
    while ((fighter1->getCurrentHP() > 0) && (fighter2->getCurrentHP() > 0)) {
        if (fighter1->getCurrentHP() <= 0) {
            out << "  " << fighter1->toString() << endl;
            out << "  " << fighter2->toString() << endl;
            return;
        }
        else {
            if (useAbility) {
                fighter1->regenerate();
                fighter1->useAbility();
            }
            fighter2->takeDamage(fighter1->getDamage());
        }
    
        if (fighter2->getCurrentHP() <= 0) {
            out << "  " << fighter1->toString() << endl;
            out << "  " << fighter2->toString() << endl;
            return;
        }
        else {
            if (useAbility) {
                fighter2->regenerate();
                fighter2->useAbility();
            }
            fighter1->takeDamage(fighter2->getDamage());
        }
        
        out << "  " << fighter1->toString() << endl;
        out << "  " << fighter2->toString() << endl;
        if (fighter1->getCurrentHP() <= 0) {
            return;
        }
        else {
            out << endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    VS_MEM_CHECK               // enable memory leak check
    Arena *myArena = new Arena;
    bool useAbility = false;
    ifstream in(argv[1]);
    if (!in) return 1;
    ostream& out = (argc > 2) ? *(new ofstream(argv[2])) : cout;
    if (!out) return 2;
    while (!in.eof()) {
        string command;
        in >> command;
        string line;
        getline(in, line);
        istringstream input(line);
        if (command == "getSize") {
            out << command << rtrim(line);
            out << " " << myArena->getSize() << endl;
        }
        else if (command == "getFighter") {
            string nameToFind;
            input >> nameToFind;
            FighterInterface *fighterPointer = myArena->getFighter(nameToFind);
            out << command << rtrim(line);
            if (fighterPointer) {
                out << endl << "  " << fighterPointer->toString() << endl;
            }
            else {
                out << " NULL" << endl;
            }
        }
        else if (command == "addFighter") {
            out << command << rtrim(line);
            out << " " << addFighterResultFormatter(myArena->addFighter(input.str())) << endl;
        }
        else if (command == "removeFighter") {
            string nameToRemove;
            input >> nameToRemove;
            out << command << rtrim(line);
            out << " " << boolToStr(myArena->removeFighter(nameToRemove)) << endl;
        }
        else if (command == "battle") {
            string fighter1;
            string fighter2;
            input >> fighter1;
            input >> fighter2;
            out << command << rtrim(line);
            out << endl;
            runBattle(out, myArena->getFighter(fighter1), myArena->getFighter(fighter2), useAbility);
        }
        else if (command == "reset") {
            string fighterName;
            input >> fighterName;
            FighterInterface *fighterPointer = myArena->getFighter(fighterName);
            out << command << rtrim(line);
            if (fighterPointer) {
                fighterPointer->reset();
                out << " " << resetFighterResultFormatter(true) << endl;
            }
            else {
                out << " " << resetFighterResultFormatter(false) << endl;
            }
        }
        else if (command == "USE") {
            useAbility = true;
        }
        else if (command == "NO") {
            useAbility = false;
        }
        else {
        }
        
    }
    if (&out != &cout) delete(&out);
    in.close();
    delete myArena;

    return 0;
}
