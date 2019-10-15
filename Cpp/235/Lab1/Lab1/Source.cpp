//Created by pp
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include "Robot.h"
#include "Cleric.h"
#include "Archer.h"
#include "Arena.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
using namespace std;

int main(int argc, char* argv[]) {

	VS_MEM_CHECK

	if (argc < 3) {
		cerr << "Please provide name of input and output files";
		return 1;
	}

	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	
	ofstream out(argv[2]);
	if (!out) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	string useAbility;
	getline(in, useAbility);
	Arena arena;
	while (!in.eof()) {
		string command;
		in >> command;
		if (command == "getSize") {
			out << command << " " << arena.getSize() << endl;
		}
		if (command == "getFighter") {
			string name;
			in >> name;
			out << command << " " << name;
			if (arena.getFighter(name)->getName() == "NULL") {
				out << " NULL" << endl;
			}
			else {
				string output;
				output = arena.getFighter(name)->toString();
				output = arena.removeSpace(output);
				out << endl << output << endl;
			}
		}
		if (command == "addFighter") {
			string info;
			getline(in, info);
			bool isAdded = false;
			isAdded = arena.addFighter(info);
			if (isAdded) {
				out << command << info << " " << "Added" << endl;
			}
			else {
				out << command << " " << info << " " << "Invalid" << endl;
			}
		}
		if (command == "removeFighter") {
			string name;
			in >> name;
			bool isAdded = false;
			isAdded = arena.removeFighter(name);
			if (isAdded) {
				out << command << " " << name << " " << "True" << endl;
			}
			else {
				out << command << " " << name << " " << "False" << endl;
			}
		}
		if (command == "battle") {
			string f1;
			in >> f1;
			string f2;
			in >> f2;
			int damage = 0;
			out << command << " " << f1 << " " << f2 << endl << endl;
			string output1, output2;
			while (arena.getFighter(f1)->getCurrentHP() > 0) {
				output1 = arena.getFighter(f1)->toString();
				output2 = arena.getFighter(f2)->toString();
				output1 = arena.removeSpace(output1);
				output2 = arena.removeSpace(output2);
				out << output1 << endl << output2 << endl << endl;
				if (useAbility == "USE ABILITY") {
					arena.getFighter(f1)->regenerate();
					arena.getFighter(f1)->useAbility();
				}
				damage = arena.getFighter(f1)->getDamage();
				arena.getFighter(f2)->takeDamage(damage);
				if (arena.getFighter(f2)->getCurrentHP() <= 0) {
					break;
				}
				if (useAbility == "USE ABILITY") {
					arena.getFighter(f2)->regenerate();
					arena.getFighter(f2)->useAbility();
				}
				damage = arena.getFighter(f2)->getDamage();
				arena.getFighter(f1)->takeDamage(damage);
			}
			output1 = arena.getFighter(f1)->toString();
			output2 = arena.getFighter(f2)->toString();
			output1 = arena.removeSpace(output1);
			output2 = arena.removeSpace(output2);
			out << output1 << endl << output2 << endl;
		}
		if (command == "reset") {
			string name;
			in >> name;
			if (arena.isPresent(name) == false) {
				out << command << " " << name << " NULL" << endl;
			}
			else {
				arena.getFighter(name)->reset();
				out << command << " " << name << " Success" << endl;
			}
		}
	}
	in.close();
	out.close();
	arena.emptyRoster();
	return 0;
}


