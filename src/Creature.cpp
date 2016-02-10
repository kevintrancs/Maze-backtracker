#include "Creature.h"
#include <iostream>
using namespace std;

Creature::Creature(int x, int y){
    this->path = new Node();
    cRow= x;
    cCol = y;
    this->path->row = x;
    this->path->col = y;
    this->path->next = NULL;
}

int Creature::getRow(){
    return cRow;
}

int Creature::getCol(){
    return cCol;
}

void Creature::pushToPath(int _row, int _col){
    cCol = _col;
    cRow = _row;
    Node* n = new Node();
    n->row = _row;
    n->col = _col;
    n->next = path;
    path = n;
}

void Creature::popOffPath(){
    Node* deleteNode = new Node();
    deleteNode = path;
    path = path->next;
    delete deleteNode;
    cRow = path->row;
    cCol = path->col;
}

void Creature::printPath(){
    Node* temp = new Node();
    temp = path;
    while(temp != NULL){
        cout << " (" << temp->row << ", " << temp->col << ") " << endl;
        temp = temp->next;
    }
}
