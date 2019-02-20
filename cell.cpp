//cell class
#include "cell.h"

using namespace std;

//constructor
Cell::Cell(){
    //defaults for data members
    alive = false;
    future = false;
}

void Cell::setFutureState(bool state){
    future = state;
}

void Cell::setCurrentState(bool state){
    alive = state;
}

bool Cell::getCurrentState(){
    return alive;
}

bool Cell::getFutureState(){
    return future;
}
