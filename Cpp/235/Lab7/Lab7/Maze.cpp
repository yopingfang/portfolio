#include"Maze.h"
#include<sstream>
using namespace std;

void Maze::setValue(int height, int width, int layer, int value) {
	
	if (value == 0) {
		maze_[height][width][layer] = OPEN;
	}
	else {
		maze_[height][width][layer] = BLOCKED;
	}
	return;
}
bool Maze::find_maze_path() {
	
	if (maze_[0][0][0] == BLOCKED) {
		return false;
	}
	else {
		bool isFound = false;
		isFound = find_maze_path(0, 0, 0);
		return isFound;
	}
}
bool Maze::find_maze_path(int height, int width, int layer) {

	if (height < 0 || height >= m_height
		|| width < 0 || width >= m_width
		|| layer < 0 || layer >= m_layers) return false;
	if (maze_[height][width][layer] != OPEN) return false;
	if ((height == m_height - 1) && (width == m_width - 1) && (layer == m_layers - 1)) {
		maze_[height][width][layer] = EXIT;
		return true;
	}
	maze_[height][width][layer] = PATH;
	if (find_maze_path(height, width - 1, layer) || find_maze_path(height, width + 1, layer)
		|| find_maze_path(height - 1, width, layer) || find_maze_path(height + 1, width, layer)
		|| find_maze_path(height, width, layer - 1) || find_maze_path(height, width, layer + 1)) return true;
	maze_[height][width][layer] = TEMPORARY;
	return false;
}
string Maze::toString() const {
	ostringstream oSS;

	for (int i = 0; i < m_layers; i++) {
		oSS << "Layer " << i + 1 << endl;
		for (int j = 0; j < m_height; j++) {
			for (int k = 0; k < m_width; k++) {
				if (maze_[j][k][i] == OPEN) {
					oSS << "_" << " ";
				}
				else {
					oSS << "X" << " ";
				}
			}
			oSS << endl;
		}
		oSS << endl;
	}

	return oSS.str();
}
void Maze::setDimensions(int height, int width, int layer) {

	maze_ = new CellValue**[height];
	for (unsigned int i = 0; i < height; i++) {
		maze_[i] = new CellValue*[width];
		for (unsigned int j = 0; j < width; j++) {
			maze_[i][j] = new CellValue[layer];
		}
	}
	m_height = height;
	m_width = width;
	m_layers = layer;
	return;
}
string Maze::toString(bool isFound) const {
	
	ostringstream oSS;
	if (isFound == false) {
		oSS << "No Solution Exists!" << endl;
		return oSS.str();
	}
	oSS << "Solution:" << endl;
	for (int i = 0; i < m_layers; i++) {
		oSS << "Layer " << i + 1 << endl;
		for (int j = 0; j < m_height; j++) {
			for (int k = 0; k < m_width; k++) {
				if (maze_[j][k][i] == OPEN) {
					oSS << "_" << " ";
				}
				else if (maze_[j][k][i] == BLOCKED) {
					oSS << "X" << " ";
				}
				else if (maze_[j][k][i] == PATH) {
					oSS << "2" << " ";
				}
				else if (maze_[j][k][i] == EXIT) {
					oSS << "3" << " ";
				}
				else {
					oSS << "_" << " ";
				}
			}
			oSS << endl;
		}
		oSS << endl;
	}

	return oSS.str();
}
void Maze::deleteMaze() {

	for (unsigned int i = 0; i < m_height; i++) {
		for (unsigned int j = 0; j < m_width; j++) {
			delete [] maze_[i][j];
		}
		delete [] maze_[i];
	}
	delete [] maze_;
	return;
}