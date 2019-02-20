//cell class definition
#include <iostream>
#ifndef CELL_H
#define CELL_H

class Cell{
    
    public:
        Cell();
        bool isAlive();
        bool futureAlive();
        bool getCurrentState();
        bool getFutureState();
        void setFutureState(bool state);
        void setCurrentState(bool state);
    private:
        bool alive;
        bool future;
};
#endif