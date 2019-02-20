//grid class
#include <iostream>
#include "grid.h"
#include "cell.h"
#include "termmanip.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

//constructor
Grid::Grid()
    : _grid(24, vector<Cell*>(80)){
        for(int y=0; y<24; y++){
            for(int x=0; x<80; x++){
                Cell*cell = new Cell();
                _grid[y][x]=cell;
            }
        }
        srand(time(0));
    }


Grid::~Grid(){
    for(int y=0; y<24; y++){
        for(int x=0; x<80; x++){
            delete _grid[y][x];
        }
    }
}

//display the grid
void Grid::display(){
    //clears the screen and sets the cursor in the top left corner
    cout << clearScreen << cursorPosition (1,1);
    for(int y=0; y<24; y++){
        for(int x=0; x < 80; x++){
            //compare the cell before displaying
            compare(y,x);
            //colors the cell based on the living state
            if (_grid[y][x]->getCurrentState()==true){
                cout << (_grid[y][x]->getFutureState() ? green:red);
                cout << '*';
            }
            else{
                cout << ' ';
            }
        }
        cout << endl;
    }
}


//compare the cell and the cells around it

void Grid::compare(int y, int x){
    int count = 0; //counts the living cells
        
    //creates variables for specific instances
        
    bool top = (y==0);
    bool right = (x==79);
    bool bottom = (y==23);
    bool left = (x==0);

    if(top and left){
        count=_grid[y+1][x+1]
            ->getCurrentState()+_grid[y][x+1]
            ->getCurrentState()+_grid[y+1][x]
            ->getCurrentState();
    }
    
    else if(top and right){
        count=_grid[y][x-1]
            ->getCurrentState()+_grid[y+1][x-1]
            ->getCurrentState()+_grid[y+1][x]
            ->getCurrentState();
    }
    
    else if(bottom and right){
        count=_grid[y-1][x]
            ->getCurrentState()+_grid[y-1][x-1]
            ->getCurrentState()+_grid[y][x-1]
            ->getCurrentState();
    }
    
    else if(bottom and left){
        count=_grid[y][x+1]
            ->getCurrentState()+_grid[y-1][x+1]
            ->getCurrentState()+_grid[y-1][x]
            ->getCurrentState();
    }
    
    else if(top){
        count=_grid[y][x-1]
            ->getCurrentState()+_grid[y+1][x-1]
            ->getCurrentState()+_grid[y+1][x]
            ->getCurrentState()+_grid[y+1][x+1]
            ->getCurrentState()+_grid[y][x+1]
            ->getCurrentState();
    }
    
    else if(bottom){
        count=_grid[y][x-1]
            ->getCurrentState()+_grid[y-1][x-1]
            ->getCurrentState()+_grid[y-1][x]
            ->getCurrentState()+_grid[y-1][x+1]
            ->getCurrentState()+_grid[y][x+1]
            ->getCurrentState();
    }
    
    else if(left){
        count=_grid[y+1][x]
            ->getCurrentState()+_grid[y+1][x+1]
            ->getCurrentState()+_grid[y][x+1]
            ->getCurrentState()+_grid[y-1][x+1]
            ->getCurrentState()+_grid[y-1][x]
            ->getCurrentState();
    }
    
    else if(right){
        count=_grid[y+1][x]
            ->getCurrentState()+_grid[y-1][x-1]
            ->getCurrentState()+_grid[y][x-1]
            ->getCurrentState()+_grid[y+1][x-1]
            ->getCurrentState()+_grid[y-1][x]
            ->getCurrentState();
    }
    
    else{
        count= _grid[y-1][x-1]
            ->getCurrentState()+_grid[y-1][x]
            ->getCurrentState()+_grid[y-1][x+1]
            ->getCurrentState()+_grid[y][x+1]
            ->getCurrentState()+_grid[y+1][x+1]
            ->getCurrentState()+_grid[y+1][x]
            ->getCurrentState()+_grid[y+1][x-1]
            ->getCurrentState()+_grid[y][x-1]
            ->getCurrentState();
    }
    
    
//whether the cell lives or dies based on current state
    if (_grid[y][x]->getCurrentState()==true){

        if(count <2 or count >3){
            //cell dies if the count is not 2 or 3
            _grid[y][x]->setFutureState(false);
        }
        
        else{
            _grid[y][x]->setFutureState(true);
        }
    }
//3 surrounding live cells when the cell is dead -> comes to life
    else if(_grid[y][x]->getCurrentState()==false){

        if (count!=3){
            _grid[y][x]->setFutureState(false);
        }
        
        else{
            _grid[y][x]->setFutureState(true);
        }
    }
}


//create a random grid
void Grid::randomGrid(){
    bool randomState;
    
    for (int y=0; y<24;y++){
        for (int x=0; x<80;x++){
            randomState=rand() %2;
            _grid[y][x]->setCurrentState(randomState);
        }
    }
}


void Grid::updateGrid(){
    //future state to current state
    for (int y=0;y<24;y++){
        for (int x=0;x<80;x++){
            _grid[y][x]->setCurrentState(_grid[y][x]->getFutureState());
        }
    }
}

//get specific cells
Cell*
Grid::getCell(int y, int x){
    return _grid[y][x];
}


