//grid class definition
#include "cell.h"
#include <iostream>
#include <vector>
#ifndef GRID_H
#define GRID_H

class Grid{
    public:
        Grid(); //constructor
        ~Grid(); //destructor
        virtual void display();
        virtual void compare(int y, int x);
        virtual void randomGrid();
        virtual Cell* getCell(int y, int x);
        virtual void updateGrid();
    private:
        std::vector<std::vector<Cell*>> _grid;
};
#endif