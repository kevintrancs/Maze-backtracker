#include "Maze.h"

/**
*Constructor
*Takes a string of the filename of the maze
*Reads the maze and puts it into the correct variables that are holding it in .h
*
*Then inits the empty arrays of visited and maze
*@param filename
*/
Maze::Maze(string filename){
    char s;
    ifstream file(filename.c_str());
    file >> cols >> rows;
    file>> endX >> endY;
    file >> startX >> startY;

    s = file.get();
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            maze[i][j] = 0;
        }
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols ;j++){
            visitedPath[i][j] = false;
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            file.get(maze[i][j]);
        }
        s = file.get();
    }
}

/**
*Deconstructor
*Deletes the maze
*
*/
Maze::~Maze(){

    for(int i=0;i<cols;i++){
        delete[]maze[i]; //this part was allocated with new[], so use delete[]
    }
    delete[] maze;
}

/**
*Returns the number of Col of the maze
*@return cols
*/
int Maze::getCols(){
    return cols;
}

/**
*Returns the nubmer of rows of the maze
*@return rows
*/
int Maze::getRows(){
    return rows;
}

/**
*Prints through the 2D array of the maze
*Uses 2 for loops
*
*/
void Maze::printMaze(){
     for(int i = 0; i <rows; i++){
        for(int j = 0; j <cols; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}

/**
*Returns the starting X(row)
*
*@return startX
*/
int Maze::getStartX(){
    return startX;
}

/**
*Returns the starting Y(col)
*
*@return startY
*/
int Maze::getStartY(){
    return startY;
}

/**
*Returns the ending X(row) of maze
*
*@return endX
*/
int Maze::getEndX(){
    return endX;
}

/**
*Returns the ending Y(col) of maze
*
*@return endY
*/
int Maze::getEndY(){
    return endY;
}

/**
*Returns the current value at the maze location
*
*@param row, col
*@return char
*/
char Maze::getMazeChar(int row, int col){
    return maze[row][col];
}

/**
*Returns a boolean if the location has been visited
*True for yes and otherwise false
*@param row, col
*@return boolean
*/
bool Maze::hasVisited(int row, int col){
    return visitedPath[row][col];
}

/**
*Takes in a row and col, and makes that spot as true
*@param row, col
*/
void Maze::markVisited(int row, int col){
    visitedPath[row][col] = true;
}
