#ifndef MAZE_H
#define MAZE_H

#include "MazeInterface.h"
#include <string>
#include <istream>
#include <sstream>

class Maze:public MazeInterface {
private:
	int height;
	int width;
	int layers;

	int*** myArray;
	
	bool find_maze_path(int i, int j, int k);

public:
	Maze(int height, int width, int layers);
	~Maze();

	/** Set maze value
	@parm height
	@parm width
	@parm layer
	@parm value
	*/
	void setValue(int height, int width, int layer, int value);

	/** Solve maze
	@return true if solveable, else false
	*/

	bool find_maze_path();

	/** Output maze (same order as input maze)
	@return string of 2D layers
	*/
	string toString() const;

	/**Converts values from the maze to the correct
	output values.
	*/
	string symbolConverter(int data) const;

};
#endif
