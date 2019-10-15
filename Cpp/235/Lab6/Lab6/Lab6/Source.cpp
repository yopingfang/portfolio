//created by pp
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#include"Station.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK;
#endif

int main(int argc, char* argv[]) {

	VS_MEM_CHECK;

	if (argc < 3)
	{
		cerr << "Please provide name of input and output files";
		return 1;
	}
	cout << "Input file: " << argv[1] << endl;
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "Unable to open " << argv[1] << " for input";
		return 2;
	}
	cout << "Output file: " << argv[2] << endl;
	ofstream out(argv[2]);
	if (!out)
	{
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
		return 3;
	}

	string command;
	Station<unsigned int> userStation;
	unsigned int inData;
	string result;
	string getCommand;

	while (getline(in, getCommand)) {
		istringstream inSS(getCommand);
		inSS >> command;
		if (inSS) {
			if (command == "Add:station") {
				inSS >> inData;
				result = userStation.addCar(inData);
				out << command << " " << inData << " " << result << endl;
			}
			else if (command == "Remove:station") {
				result = userStation.removeCar();
				out << command << " " << result << endl;
			}
			else if (command == "Train:") {
				out << command << " " << userStation.toString() << endl;
			}
			else if (command == "Top:station") {
				out << command << " " << userStation.topCar() << endl;
			}
			else if (command == "Add:stack") {
				result = userStation.addStack();
				out << command << " " << result << endl;
			}
			else if (command == "Remove:stack") {
				result = userStation.removeStack();
				out << command << " " << result << endl;
			}
			else if (command == "Top:stack") {
				out << command << " " << userStation.topStack() << endl;
			}
			else if (command == "Add:queue") {
				result = userStation.addQueue();
				out << command << " " << result << endl;
			}
			else if (command == "Remove:queue") {
				result = userStation.removeQueue();
				out << command << " " << result << endl;
			}
			else if (command == "Top:queue") {
				out << command << " " << userStation.topQueue() << endl;
			}
			else if (command == "Size:queue") {
				out << command << " " << userStation.sizeQueue() << endl;
			}
			else if (command == "Size:stack") {
				out << command << " " << userStation.sizeStack() << endl;
			}
			else {
				if (command[0] == 'F') {
					string inNum = command;
					inNum = inNum.substr(5, inNum.size() - 5);
					istringstream inSS_(inNum);
					inSS_ >> inData;
					result = userStation.find(inData);
					out << command << " " << result << endl;
				}
			}
		}
	}

	//userStation.delAll();
	in.close();
	out.close();
	return 0;
}