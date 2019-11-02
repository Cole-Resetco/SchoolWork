//  Paste over this comment with your assessment header.


//        Requires grid file as input (input redirection).
//        Grid file looks similar to:
//
//            xxxSxxxxxxxxxxxxxxx
//            x                 x
//            xxxxxxx xxxxxxxxxxx
//            x                 x
//            xxxxxxxxxxxxxxGxxxx
//
//        Spaces represent empty grid blocks.  Init in EMPTY state.
//        S represents the starting grid block(s). Init in COLOR state.
//        G represents the goal grid block. More than one can exist.
//        Any non-space (x here) is considered a wall. Init in WALL state.

#include <iostream>
#include <vector>

using namespace std;

// Provided functions
void animationPause();
void clearScreen();
void printEmpty();
void printColor();
void printWall();
void readGrid(vector <vector <int> > &, vector <vector <bool> > &);
void printGrid(const vector <vector <int> > &);
bool percComplete(const vector <vector<int> > &, const vector <vector<bool> >&);


// States for grid spots for use throughout the program
const int EMPTY = 1;
const int WALL = 2;
const int COLOR = 3;
const int TO_BE_COLORED = 4;



/// @brief percolates the fluid from grid blocks with fluid in them
/// @param grid the current grid filled with current states
void perc(vector <vector <int> > &grid)
{
    // TODO: Implement this function
    
    /// Traverse 2D grid setting intermediate state where applicable

    /// Traverse 2D grid converting intermediate states to color state
    
    
    
}



// DO NOT alter code in main
int main()
{
    // 2D vectors to store states of grid and whether it is a goal cell
    vector <vector <int> > grid;
    vector <vector <bool> > goals;
   
    // Read in the grid from input
    readGrid(grid, goals);

    // Print initial grid
    printGrid(grid);

    // Run the simulation
    do
    {
        // Animation
        animationPause();

        // Percolate
        perc(grid);

        // Print updated grid
        printGrid(grid);
    }while(!percComplete(grid, goals));

    return 0;
}
