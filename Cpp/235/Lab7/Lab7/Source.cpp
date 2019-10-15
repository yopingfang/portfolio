#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"Maze.h"
using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[]) {

	VS_MEM_CHECK

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
	string dimensions;
	getline(in, dimensions);
	istringstream inSS(dimensions);
	int inHeight;
	inSS >> inHeight;
	int inWidth;
	inSS >> inWidth;
	int inLayer;
	inSS >> inLayer;
	Maze userMaze;
	userMaze.setDimensions(inHeight, inWidth, inLayer);

	string inLine;
	int cHeight = 0;
	int cLayer = 0;
	getline(in, inLine);
	while (getline(in, inLine)) {
		if (inLine != "") {
			for (int i = 0; i < inWidth; i++) {
				istringstream inSS_(inLine.substr(i * 2, 1));
				int inValue;
				inSS_ >> inValue;
				userMaze.setValue(cHeight, i, cLayer, inValue);
			}
			cHeight++;
		}
		else {
			cHeight = 0;
			cLayer++;
		}
	}
	out << "Solve Maze:" << endl;
	out << userMaze.toString();
	bool isFound = false;
	isFound = userMaze.find_maze_path();
	out << userMaze.toString(isFound);

	in.close();
	out.close();
	userMaze.deleteMaze();

	return 0;
}