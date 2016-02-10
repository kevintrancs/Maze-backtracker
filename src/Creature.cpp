#include "Creature.h"
#include <iostream>
using namespace std;

/**
*Constructor
*Creates a new creature object with a path Node as the starting point
*Makes current row and col the starting point with next path as null
*/
Creature::Creature(int x, int y){
    this->path = new Node();
    cRow= x;
    cCol = y;
    this->path->row = x;
    this->path->col = y;
    this->path->next = NULL;
}

/**
*Returns the current Row of the creature
*
*@return cRows
*/
int Creature::getRow(){
    return cRow;
}

/**
*Returns the current col of the creature
*
*@return @cCol
*/
int Creature::getCol(){
    return cCol;
}

/**
*Takes two ints, they are the new row/col of the creature
*Pushes it on to the new position and pushes it on to the current path stack of the creature.
*@param _row, _col
*
*/
void Creature::pushToPath(int _row, int _col){
    cCol = _col;
    cRow = _row;
    Node* n = new Node();
    n->row = _row;
    n->col = _col;
    n->next = path;
    path = n;
}

/**
*
*Pops off the most recently visited path
*Deletes the Node and sets the current one to one previous
*
*/
void Creature::popOffPath(){
    Node* deleteNode = new Node();
    deleteNode = path;
    path = path->next;
    delete deleteNode;
    cRow = path->row;
    cCol = path->col;
}

/**
*Prints out the path of the creature
*Follows the node until it is null
*
*/
void Creature::printPath(){
    Node* temp = new Node();
    temp = path;
    while(temp != NULL){
        cout << "(" << temp->row << "," << temp->col << ")" << endl;
        temp = temp->next;
    }
}

