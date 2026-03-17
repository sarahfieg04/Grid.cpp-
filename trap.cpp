//Sarah Fieg, section 5 
#include <iostream>
#include "grid.h"
using namespace std;

int main()
{
    int row, col;
    // track numberand type of moves made 
    int ups = 0; 
    int downs = 0; 
    int lefts = 0; 
    int rights = 0; 

   
    cout << "Enter in the grid rows and columns ";
    cin >> row >> col;  //get user input for grid size
    Grid g(row, col);   //call constructor                                                        
    g.Display();
    bool Escape = false;  //flag for escape tracking 

    while (!Escape)   //run if not escaped yet                                                                 
    {
        if(g.RightIsClear())     // check if right is clear, if not turn 
        {
            g.TurnLeft();
            g.TurnLeft();
            g.TurnLeft();
        }
        else if(!g.FrontIsClear())  // check if front is clear then turn 
        {
            g.TurnLeft();
            continue;
        }

        int d=g.GetDirection();  // get direction mover went it 

        g.Move(1);

        if(d==Grid::NORTH) ups++;    // track moves made 
        if(d==Grid::SOUTH) downs++;
        if(d==Grid::WEST) lefts++;
        if(d==Grid::EAST) rights++;

        if(g.GetRow()==0 || g.GetRow()==g.GetNumRows()-1 || g.GetCol()==0 || g.GetCol()==g.GetNumCols()-1)
        {  
             Escape=true;       // Escape if at border of maze 
        } 

    }

    cout << "You Escaped!" << endl;
    cout << "You escaped at: " << g.GetRow() << ' ' << g.GetCol() << endl;  //print final exit area
    g.Display();  //print final grid

    cout << "\nMoves Made:\n";   // display total moves 
    cout<<"Up moves: "<<ups<<endl;
    cout<<"Down moves: "<<downs<<endl;
    cout<<"Left moves: "<<lefts<<endl;
    cout<<"Right moves: "<<rights<<endl;
    
    return 0;

}