#include "Maze.h"


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

    cout << "Maze test" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            file.get(maze[i][j]);
        }
        s = file.get();
    }
}
Maze::~Maze(){

    for(int i=0;i<cols;i++){
        delete[]maze[i]; //this part was allocated with new[], so use delete[]
    }
    delete[] maze;
}

int Maze::getCols(){
    return cols;
}
int Maze::getRows(){
    return rows;
}
void Maze::printMaze(){
     for(int i = 0; i <rows; i++){
        for(int j = 0; j <cols; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}

int Maze::getStartX(){
    return startX;
}
int Maze::getStartY(){
    return startY;
}

int Maze::getEndX(){
    return endX;
}

int Maze::getEndY(){
    return endY;
}

char Maze::getMazeChar(int row, int col){
    return maze[row][col];
}

bool Maze::hasVisited(int row, int col){
    return visitedPath[row][col];
}

void Maze::markVisited(int row, int col){
    visitedPath[row][col] = true;
}
