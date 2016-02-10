/************************************************************
 * Author: Kevin Tran, Maxwell Baker, Ava M Zebzda          *
 * Date Created: 2/1/2016                                   *
 * Date Last Modified: 2/10/2016                            *
 * Class: CPSC 223                                          *
 * Professor: Otto Borchert                                 *
 * Assignment Backtrack Maze Program - Recursive call       *
 * **********************************************************
 ************************************************************/
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
    cout << endl;

    if(goNorth(maze, creature)){
        cout << "Maze Path found(Finish - Start): " << endl;
        creature.printPath();
    }
    else
        cout << "Maze Path NOT found." << endl;
    return 0;
}

/**
*Takes in a Maze and creature
*Checks if the correct spot going is visited and doesn't have a wall
*Then advances forward and pushing on to Path for creature
*Then updates it as marked
*Then checks if it is at the end
*Recursive call itself or other functions to continue moving until false or true
*
*@param &m, &c
*@return bool success
*/
bool goNorth(Maze &m, Creature &c){
    bool success =false;

    if(m.getMazeChar(c.getRow() - 1, c.getCol()) != 'x' && !m.hasVisited(c.getRow() -1, c.getCol())){// no wall and not visited
            c.pushToPath(c.getRow() - 1, c.getCol());
            m.markVisited(c.getRow(), c.getCol());
            //cout << c.getRow() << " " << c.getCol() << endl;
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

/**
*Takes in a Maze and creature
*Checks if the correct spot going is visited and doesn't have a wall
*Then advances forward and pushing on to Path for creature
*Then updates it as marked
*Then checks if it is at the end
*Recursive call itself or other functions to continue moving until false or true
*
*@param &m, &c
*@return bool success
*/
bool goWest(Maze &m, Creature &c){
    bool success =false;

    if(m.getMazeChar(c.getRow(), c.getCol() -1) != 'x' && !m.hasVisited(c.getRow(), c.getCol()-1)){// no wall and not visited
            c.pushToPath(c.getRow(), c.getCol() -1);
            m.markVisited(c.getRow(), c.getCol());
            //cout << c.getRow() << " " << c.getCol() << endl;
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
                        if(!success)
                            c.popOffPath();
                    }
                }
            }
    }
    else{
        success = false;
    }
    return success;
}

/**
*Takes in a Maze and creature
*Checks if the correct spot going is visited and doesn't have a wall
*Then advances forward and pushing on to Path for creature
*Then updates it as marked
*Then checks if it is at the end
*Recursive call itself or other functions to continue moving until false or true
*
*@param &m, &c
*@return bool success
*/
bool goEast(Maze &m, Creature &c){
bool success =false;
    if(m.getMazeChar(c.getRow(), c.getCol() +1) != 'x' && !m.hasVisited(c.getRow(), c.getCol() +1)){// no wall and not visited
            c.pushToPath(c.getRow(), c.getCol() +1);
            m.markVisited(c.getRow(), c.getCol());
            //cout << c.getRow() << " " << c.getCol() << endl;
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
                                if(!success)
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

/**
*Takes in a Maze and creature
*Checks if the correct spot going is visited and doesn't have a wall
*Then advances forward and pushing on to Path for creature
*Then updates it as marked
*Then checks if it is at the end
*Recursive call itself or other functions to continue moving until false or true
*
*@param &m, &c
*@return bool success
*/
bool goSouth(Maze &m, Creature &c){

     bool success = false;

    if(m.getMazeChar(c.getRow() +1, c.getCol()) != 'x' && !m.hasVisited(c.getRow() +1, c.getCol())){// no wall and not visited
            c.pushToPath(c.getRow() +1, c.getCol());
            m.markVisited(c.getRow(), c.getCol());
            //cout << c.getRow() << " " << c.getCol() << endl;
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
                                if(!success)
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
