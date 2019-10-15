#ifndef MAZE_H
#define MAZE_H

#include"MazeInterface.h"

class Maze : public MazeInterface {
public:
	Maze() {}
	~Maze() {}
	void setValue(int height, int width, int layer, int value);
	bool find_maze_path();
	bool find_maze_path(int height, int width, int layer);
	string toString() const;
	void setDimensions(int height, int width, int layer);
	string toString(bool isFound) const;
	void deleteMaze();
private:
	int m_height;
	int m_width;
	int m_layers;
	enum CellValue { OPEN, BLOCKED, PATH, EXIT, TEMPORARY };
	CellValue ***maze_;
};

#endif
