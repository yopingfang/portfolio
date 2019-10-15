//
//  Maze.h
//  Lab7_Maze
//
//  Created by ward37 on 7/24/18.
//  Copyright © 2018 ward37. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>

#include "MazeInterface.h"

class Maze : public MazeInterface {
    
public:
    Maze(int mHeight, int mWidth, int mDepth);
    ~Maze(void); 
    
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
    
    /** Outputs the solved maze
     @return a string of 2D layers
     */
    string solution(); 
    
private:
    int ***maze;
    int depth;
    int width;
    int height;
    enum CellValue { OPEN, BLOCKED, PATH, EXIT, TEMPORARY};
    bool find_maze_path(int currentH, int currentW, int currentD);
    
};

#endif /* Maze_h */
