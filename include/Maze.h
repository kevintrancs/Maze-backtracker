#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

class Maze{

public:
    Maze(string filename);
    int getCols();
    int getRows();
    void printMaze();
    int getStartX();
    int getStartY();
    int getEndX();
    int getEndY();
    char getMazeChar(int row, int col);
    bool hasVisited(int row, int col);
    void markVisited(int row, int col);


private:
    int startX, startY, endX, endY, cols, rows;
    char maze[100][100];
    bool visitedPath[100][100];
};


#endif // MAZE_H_INCLUDED
