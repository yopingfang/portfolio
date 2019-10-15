//pseudonym: Mastera Universi
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "DequeInterface.h"
#include "Station.h"
using namespace std;

int main(int argc, char * argv[]) {

	VS_MEM_CHECK;

	if (argc < 3) {
		cerr << "Please provide name of input and output files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}


	string line, command;

	//create station object
	Station<size_t> station;

	//iterate through file
	while (getline(in, line)) {

		//ignore empty lines
		if (line == "") {
			continue;
		}
		
		//echo input line to file
		out << line;

		//get command
		istringstream iss(line);
		iss >> command;

		//process command
		if (command == "Add:station") {
			size_t value;
			iss >> value;
			out << " " << station.addCar(value) << endl;
		}
		else if (command == "Remove:station") {
			out << " " << station.removeCar() << endl;
		}
		else if (command == "Train:") {
			out << "  " << station.toString() << endl;
		}
		else if (command == "Add:stack") {
			out << " " << station.addStack() << endl;
		}
		else if (command == "Top:stack") {
			out << " " << station.topStack() << endl;
		}
		else if (command == "Remove:stack") {
			out << " " << station.removeStack() << endl;
		}
		else if (command == "Add:queue") {
			out << " " << station.addQueue() << endl;
		}
		else if (command == "Top:queue") {
			out << " " << station.topQueue() << endl;
		}
		else if (command == "Remove:queue") {
			out << " " << station.removeQueue() << endl;
		}
		else if (command == "Size:queue") {
			out << " " << station.sizeQueue() << endl;
		}
		else if (command == "Size:stack") {
			out << " " << station.sizeStack() << endl;
		}
		else if (command.substr(0, 5) == "Find:") {
			out << " " << station.find(stoi(command.substr(5))) << endl;
		}
	}
	return 0;
}