//
//  Maze.cpp
//  Lab7_Maze
//
//  Created by ward37 on 7/24/18.
//  Copyright © 2018 ward37. All rights reserved.
//
#include <sstream>
#include <iostream>

#include "Maze.h"


Maze::Maze(int mHeight, int mWidth, int mDepth){
    height = mHeight;
    depth = mDepth;
    width = mWidth;
    maze = new int**[width];
    
    
    
    for(int i = 0; i < width; ++i){
        maze[i] = new int*[height];
        for(int j = 0; j < height; ++j){
            maze[i][j] = new int[depth];
        }
    }
}

Maze::~Maze(){
    for (int i = 0; i < width; ++i){
        for(int j = 0; j < height; ++j){
            delete[] maze[i][j];
        }
        delete [] maze[i]; 
    }
    delete[] maze; 
}

void Maze::setValue(int width, int height, int layer, int value){
    //std::cout << width << " " << height << " " << layer << std::endl; 
    maze[width][height][layer] = value;
    return; 
}

bool Maze::find_maze_path(int x, int y, int z){
    
    if(y < 0 || x < 0 || z < 0 || y >= height || x >= width || z >= depth) { //checks for out-of-bounds
        return false;
    }
    
    if (maze[x][y][z] == BLOCKED || maze[x][y][z] == TEMPORARY){          //checks for blocked or already visited cells
           return false;
    }
    
    if(y == height - 1 && x == width - 1 && z == depth - 1){                // checks for maze being solved
        maze[x][y][z] = EXIT;
        return true;
    }
        maze[x][y][z] = CellValue::TEMPORARY;
    
        /* Following if statements iterates recursively through the maze trying (in order) left, right, forward, back
         * in, out. If the exit is found, all applicable cells are changed to PATH
        */
        if (find_maze_path(x - 1, y, z) || find_maze_path(x + 1, y, z) || find_maze_path(x, y - 1, z)||
            find_maze_path(x, y + 1, z) || find_maze_path(x, y, z -1) || find_maze_path(x, y, z + 1)){
            maze[x][y][z] = CellValue::PATH;
            return true;
        }

    
    return false;
    
}
//Wrapper class that calls the private member function find_maze_path with parameters.
bool Maze::find_maze_path(){
    if (find_maze_path(0,0,0)){
        return true;
    }
    return false;
}

string Maze::toString() const{
    std::ostringstream oSS;
    
    for (int i = 0; i < depth; ++i){
        oSS << "Layer " << i + 1 << "\n";
        for(int j = 0; j < height; ++j){
            for(int k = 0; k < width; ++k){
                if(maze[k][j][i] == 0){
                    oSS << " _";
                }
                else if (maze[k][j][i] == 1){
                    oSS << " X";
                }
            }
            oSS << "\n";
        }
        
    }
    return oSS.str();
}

string Maze::solution(){
    std::ostringstream oSS;
    
    for (int i = 0; i < depth; ++i){
        oSS << "Layer " << i +1 << "\n";
        for(int j = 0; j < height; ++j){
            for(int k = 0; k < width; ++k){
                if(maze[k][j][i] == OPEN || maze[k][j][i] == TEMPORARY){
                    oSS << " _";
                }
                else if (maze[k][j][i] == BLOCKED){
                    oSS << " X";
                }
                else {
                    oSS << " " << maze[k][j][i];
                }
            }
            oSS << "\n";
        }
        
    }
    return oSS.str();
}
