#include<iostream>
#include<string>
#include<fstream>
#include"BST.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
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
	BST<int> inTree;
	while (getline(in, command)) {
		if (command.substr(0, 3) == "Add") {
			istringstream inSS(command.substr(4, command.size() - 4));
			int addNum;
			inSS >> addNum;
			bool wasAdded = inTree.addNode(addNum);
			out << command << " ";
			if (wasAdded) out << "True" << endl;
			else out << "False" << endl;
		}
		else if (command.substr(0, 5) == "Print") {
			out << command << inTree.toString() << endl;
		}
		else if (command.substr(0, 6) == "Remove") {
			istringstream inSS(command.substr(7, command.size() - 7));
			int removeNum;
			inSS >> removeNum;
			bool wasRemoved = inTree.removeNode(removeNum);
			out << command << " ";
			if (wasRemoved) out << "True" << endl;
			else out << "False" << endl;
		}
		else if (command.substr(0, 5) == "Clear") {
			bool wasCleared = inTree.clearTree();
			out << command << " ";
			if (wasCleared) out << "True";
			else out << "False";
			out << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}