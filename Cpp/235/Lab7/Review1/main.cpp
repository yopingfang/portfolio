//
//  main.cpp
//  Lab7_Maze
//
//  Created by ward37 on 7/24/18.
//  Copyright © 2018 ward37. All rights reserved.
//



#include <iostream>
#include <fstream>
#include <string>

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

#include "Maze.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
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
    ofstream  out(argv[2]);
    if (!out)
    {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    }
    
    int w = 0;
    int h = 0;
    int d = 0;
    
    in >> h;
    in >> w;
    in >> d;
    
    Maze mazeSolver(h,w,d);
    for(int i = 0; i < d; ++i){
        for(int j = 0; j < h; ++j){  
            for(int k = 0; k < w; ++k){
                int value;
                in >> value;
                mazeSolver.setValue(k,j,i,value);
            }
        }
    }
    out  << "Solve Maze:" << endl << mazeSolver.toString() << endl;
    
    
    if (!mazeSolver.find_maze_path()){
        out << "No Solution Exists!";
    }
    else {
        out << "Solution:" << endl << mazeSolver.solution();
    }
    
    
    
    
    
    return 0;
}
