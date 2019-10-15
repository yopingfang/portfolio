/*
Creator: door2door_suit

Date begun: 7/27/2018
Date completed: 7/27/2018

Notes:
all tests pass. the while(in>>data) may be redundent(force of habit), but may help detect if files contain extra lines of data.
*/

#include <iostream>
#include <fstream>
#include <sstream>

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include "maze.h"
#include <string>
#include <istream>
#include <sstream>

using namespace std;

int main(int argc, char * argv[]) {

	VS_MEM_CHECK;

		//output and input to a file
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

	string data;
	
	getline(in, data);

	//easy way to convert data from strings to ints
	istringstream ss(data);
	int height, width, layers;
	ss >> height >> width >> layers;

	Maze myMaze(height, width, layers);

	//sifts in rest of data to place in 3D array
	while (in >> data) {
		for (int k = 0; k < layers; k++) {
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					istringstream s(data);//coverts data to int
					int value;
					s >> value;
					myMaze.setValue(i, j, k, value);
					in >> data;

				}
			}
		}
	}

	out << "Solve Maze:" << endl;
	out << myMaze.toString() << endl;

	if (myMaze.find_maze_path()) {
		out << "Solution:" << endl;
		out << myMaze.toString();
	}
	else {
		out << "No Solution Exists!";
	}

	return 0;
}