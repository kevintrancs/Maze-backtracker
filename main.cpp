#include <iostream>
#include "Maze.h"
#include "Creature.h"

using namespace std;

bool goNorth( Maze &m, Creature &c);
bool goSouth(Maze &m, Creature &c);
bool goWest(Maze &m, Creature &c);
bool goEast(Maze &m, Creature &c);

int main()
{
    Maze maze("maze_complex.txt");
    maze.printMaze();
    Creature creature(maze.getStartX(), maze.getStartY());

    if(goNorth(maze, creature)){
        cout << "done" << endl;
    }
    else{
        cout << "not done" << endl;
    }

    cout << endl;

    creature.printPath();
    return 0;
}

bool goNorth(Maze &m, Creature &c){
    bool success =false;

    if(m.getMazeChar(c.getRow() - 1, c.getCol()) != 'x' && !m.hasVisited(c.getRow() -1, c.getCol())){// no wall and not visited
            c.pushToPath(c.getRow() - 1, c.getCol());
            m.markVisited(c.getRow(), c.getCol());

            cout << c.getRow() << " " << c.getCol() << endl;
         if(c.getRow() == m.getEndX() && c.getCol() == m.getEndY()){
                success = true;
                return success;
            }
            else{
                success = goNorth(m, c);
                if(!success){
                    success = goWest(m, c);
                    if(!success){
                        success = goEast(m, c);
                        if(!success){
                            c.popOffPath();
                        }
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}

bool goWest(Maze &m, Creature &c){
    bool success =false;

    if(m.getMazeChar(c.getRow(), c.getCol() -1) != 'x' && !m.hasVisited(c.getRow(), c.getCol()-1)){// no wall and not visited
            c.pushToPath(c.getRow(), c.getCol() -1);
            m.markVisited(c.getRow(), c.getCol());

            cout << c.getRow() << " " << c.getCol() << endl;
         if(c.getRow() == m.getEndX() && c.getCol() == m.getEndY()){
                success = true;
                return success;
            }
            else{
                success = goNorth(m, c);
                if(!success){
                    success = goWest(m, c);
                    if(!success){
                        success = goEast(m, c);
                        if(!success){
                            c.popOffPath();
                        }
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}

bool goEast(Maze &m, Creature &c){
bool success =false;
    if(m.getMazeChar(c.getRow(), c.getCol() +1) != 'x' && !m.hasVisited(c.getRow(), c.getCol() +1)){// no wall and not visited
            c.pushToPath(c.getRow(), c.getCol() +1);
            m.markVisited(c.getRow(), c.getCol());

            cout << c.getRow() << " " << c.getCol() << endl;
         if(c.getRow() == m.getEndX() && c.getCol() == m.getEndY()){
                success = true;
                return success;
            }
            else{
                success = goNorth(m, c);
                if(!success){
                    success = goWest(m, c);
                    if(!success){
                        success = goEast(m, c);
                        if(!success){
                            success = goSouth(m, c);
                                if(!success){
                                    c.popOffPath();
                                }
                        }
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}

bool goSouth(Maze &m, Creature &c){

     bool success = false;

    if(m.getMazeChar(c.getRow() +1, c.getCol()) != 'x' && !m.hasVisited(c.getRow() +1, c.getCol())){// no wall and not visited
            c.pushToPath(c.getRow() +1, c.getCol());
            m.markVisited(c.getRow(), c.getCol());

            cout << c.getRow() << " " << c.getCol() << endl;
         if(c.getRow() == m.getEndX() && c.getCol() == m.getEndY()){
                success = true;
                return success;
            }
            else{
                success = goNorth(m, c);
                if(!success){
                    success = goWest(m, c);
                    if(!success){
                        success = goEast(m, c);
                        if(!success){
                            success = goSouth(m, c);
                                if(!success){
                                    c.popOffPath();
                                }
                        }
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}
