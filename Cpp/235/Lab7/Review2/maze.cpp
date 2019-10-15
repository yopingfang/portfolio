#include "maze.h"

using namespace std;

Maze::Maze(int height, int width, int layers) {
	this->height = height;
	this->width = width;
	this->layers = layers;

	myArray = new int**[height];
	for (int i = 0; i < height; i++) {
		myArray[i] = new int*[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			myArray[i][j] = new int[layers];
		}
	}
}
Maze::~Maze(){
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete[] myArray[i][j];
		}
	}
	for (int i = 0; i < height; i++) {
		delete[] myArray[i];
	}
	delete[] myArray;
}

/**Finds path through the maze.
	0 = open space
	1 = closed space
	2 = path
	3 = exit
	4 = temporary path
*/
bool Maze::find_maze_path(int i, int j, int k) {
	//check boundry
	if ((i < 0) || (i >= height) ||
		(j < 0) || (j >= width) ||
		(k < 0) || (k >= layers)) {
		return false;
	}
	//check inaccessable blocks
	if (myArray[i][j][k] != 0) { return false; }
	//check for success
	if ((i == height - 1) && (j == width - 1) && (k == layers - 1)) {
		myArray[i][j][k] = 3;
		return true;
	}
	//marks path
	myArray[i][j][k] = 2;
	//recursivly calls function to find path
	if (find_maze_path(i, j - 1, k) || find_maze_path(i, j + 1, k) ||
		find_maze_path(i - 1, j, k) || find_maze_path(i + 1, j, k) ||
		find_maze_path(i, j, k - 1) || find_maze_path(i, j, k + 1)) {
		return true;
	}
	//unmarks path if not returned true;
	myArray[i][j][k] = 4;
	return false;
}

/** Set maze value
@parm height
@parm width
@parm layer
@parm value
*/
void Maze::setValue(int height, int width, int layer, int value) {
	myArray[height][width][layer] = value;
}

/** Solve maze
@return true if solveable, else false
*/
bool Maze::find_maze_path() {
	return find_maze_path(0, 0, 0);
}

/** Output maze (same order as input maze)
@return string of 2D layers
*/
string Maze::toString() const {
	stringstream ss;
	for (int k = 0; k < layers; k++) {
		ss << "Layer " << k + 1 << "\n";
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				ss << " " << symbolConverter(myArray[i][j][k]);
			}
			ss << "\n";
		}
	}
	return ss.str();
}

/**Converts values from the maze to the correct
output values.
*/
string Maze::symbolConverter(int data) const {
	if (data == 0) { return "_"; }
	else if (data == 1) { return "X"; }
	else if (data == 2) { return "2"; }
	else if (data == 3) { return "3"; }
	else if (data == 4) { return "_"; }
	else { return ""; }
}