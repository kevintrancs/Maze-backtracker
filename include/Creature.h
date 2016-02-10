#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

class Creature{
public:
    struct Node{
        int row,col;
        Node* next;
    };
    Creature(int x, int y);
    int getRow();
    int getCol();
    void pushToPath(int _row, int _col);
    void popOffPath();
    void printPath();

private:
    char** position;
    int cRow, cCol;
    Node* path;
};



#endif // CREATURE_H_INCLUDED
