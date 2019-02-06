#include <iostream>
#include <cstdlib>
#include <unistd.h>

const int gridsize = 80;

void Display(bool grid[gridsize+1][gridsize+1]){
    for(int a = 1; a < gridsize; a++){
        for(int b = 1; b < gridsize; b++){
            if(grid[a][b] == true){
                std::cout << "*";
            }
            else{
                std::cout << " ";
            }
            if(b == gridsize-1){
                std::cout << std::endl;
            }
        }
    }
}

void CopyGrid (bool grid[gridsize+1][gridsize+1],bool grid2[gridsize+1][gridsize+1]){
    for(int a =0; a < gridsize; a++){
        for(int b = 0; b < gridsize; b++){grid2[a][b] = grid[a][b];}
    }
}

void liveOrDie(bool grid[gridsize+1][gridsize+1]){
    bool grid2[gridsize+1][gridsize+1] = {};
    CopyGrid(grid, grid2);
    for(int a = 1; a < gridsize; a++){
        for(int b = 1; b < gridsize; b++){
            int life = 0;
        for(int c = -1; c < 2; c++){
            for(int d = -1; d < 2; d++){
                if(!(c == 0 && d == 0)){
                    if(grid2[a+c][b+d]) {++life;}
                }
            }
        }
            if(life < 2) {grid[a][b] = false;}
            else if(life == 3){grid[a][b] = true;}
            else if(life > 3){grid[a][b] = false;}
        }
    }
}

int main(){

    bool grid[gridsize+1][gridsize+1] = {};

    grid[gridsize/2][gridsize/2] = true;
    grid[gridsize/2-1][gridsize/2] = true;
    grid[gridsize/2][gridsize/2+1] = true;
    grid[gridsize/2][gridsize/2-1] = true;
    grid[gridsize/2+1][gridsize/2+1] = true;

    while (true){

        Display(grid);
        liveOrDie(grid);
        system("CLS");
    }
    sleep(1000);  //usleep
}