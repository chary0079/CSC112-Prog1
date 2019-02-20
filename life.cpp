#include "grid.h"
#include "cell.h"
#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
#include <vector>


using namespace std;
std::vector<std::vector<Cell*>> _grid;
//gets the arguments entered in command line
vector<string> getCommandLine(int argc, char **argv){
    vector<string> result;
    //makes a vector of the arguments and how many there are
    for(int i=0; i<argc; i++) {
        result.push_back(argv[i]);
    }
    return result;
}

//main function
int main(int argc, char **argv)
{
    //new grid
    Grid *grid = new Grid();
    vector<string> args = getCommandLine(argc,argv);
    //if there is only one argument in the command line, create a random grid
    if(args.size()==1){
        grid->randomGrid();
    }
    //more than one command, open the name of the specified grid
    else if (args.size() >1) {
        ifstream file;
        char c;
        char c1;
        //open the file named
        file.open(args[1]);
        for(int y=0; y<24; y++){
            for (int x=0; x<80; x++){
                file.get(c);
                c1=file.peek();
                //ignore if new line character
                if(c1=='\n'){
                    file.ignore(1,'\n');
                }
                //within the file if theres a* a cell is set to living
                if(c=='*'){
                    grid->getCell(y,x)->setCurrentState(true);
                }
                else if(c=='\n') {
                    
                }
                else {
                    grid->getCell(y,x)->setCurrentState(false);
                }
            }
        }
    }
    
    //infinite loop that prints the graph, checks for the next state, sleeps for .25 seconds, then reprints
    for (;;){
        grid->display();
        grid->updateGrid();
        usleep(1000000);
    }
    delete grid;
}
    