//Sarah Fieg, section 5 
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "grid.h"
using namespace std; 

Grid::Grid() //Default Constructor initializes grid 
{                                               
    rows = 1;
    cols = 1;

    grid[0][0] = '>';
    mover = '>';
    direction = EAST;    // default direction 

    mrow = 0;
    mcol = 0;                 
}

Grid::Grid(int r, int c)
{
    Set(r,c);                         // error checking for grid parameters before set 
    srand(time(0));                  // Seed rng 
    direction=rand()%4;              // Pick random starting direction 
    mrow = rand() % rows;
    mcol = rand() % cols;

    while(mrow == 0 || mrow == (rows-1)) // Make sure mover isn't put on the border
    {
        mrow = rand() % rows;
    }
    while(mcol == 0 || mcol == (cols-1)) 
        mcol = rand() % cols;

    ExitWall = rand() % 4;   //Choose random exit wall 
    if(ExitWall == 0)      //random exit on top wall 
    {
        Exit = rand() % cols;
        while(Exit == 0 || Exit == (cols-1))
            Exit = rand() % cols;
    }
    else if(ExitWall == 1)  //random exit on right wall 
    {
        Exit = rand() % rows;
        while(Exit == 0 || Exit == (rows-1))
            Exit= rand() % rows;
    } 
    else if (ExitWall == 2)  //random exit on bottom wall 
    {
        Exit = rand() % cols;
        while(Exit == 0 || Exit == (cols-1))
            Exit = rand() % cols;
    } 
    else  //random exit on left wall 
    {
        Exit = rand() % rows;
        while(Exit == 0 || Exit == (rows-1))
            Exit = rand() % rows;
    } 

    // Set the mover direction
    if(direction == 0)
    {
        grid[mrow][mcol] = '^';  // Mover facing North
        direction = NORTH;
        mover = '^';
    }
    else if(direction == 1)
    {
        grid[mrow][mcol] = '<'; //Mover facing west
        direction = WEST;
        mover = '<';
    }

    else if(direction==2)
    {
        grid[mrow][mcol] = 'v'; //Mover facing south
        direction = SOUTH;
        mover = 'v';
    }

    else if(direction==3)
    {
        grid[mrow][mcol] = '>';  //Mover facing east 
        direction = EAST;
        mover = '>';
    }

    grid[mrow][mcol]=mover;  // set up mover 

    int items = rand()%2+1;  // add in 1-2 random items 

    for(int i = 0; i < items; i++)
    {
        int r=rand()%rows;
        int c=rand()%cols;

        while(r==0||r==rows-1||c==0||c==cols-1||grid[r][c]!='.') //make sure item is not placed over grid 
        {
            r=rand()%rows;
            c=rand()%cols;
        }

        grid[r][c]='@';
    
    }
}

void Grid::Set(int r,int c)
{
    // grid min and max sizes 
    if(r<3) r=3;       
    if(c<3) c=3;
    if(r>40) r=40;   
    if(c>40) c=40;

    rows=r;
    cols=c;

    for(int i=0;i<rows;i++)           // set up grid with border 
    {
        for(int j=0;j<cols;j++)
        {
            if(i==0 || j==0 || i==rows-1 || j==cols-1)
                grid[i][j]='#';
            else
                grid[i][j]='.';
        }
    }
}

void Grid::Display() const                              
{
    cout << "The Grid:" << endl;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
             cout << grid[i][j] << " ";  //displaying updated grid 
        }
        cout << endl;
    }
}

bool Grid::Move(int s)
{
    for (int i = 0; i < s; i++)                    
    {
        LastRow = mrow;   //move to the last row position
        LastCol = mcol;   //move to last col position 

        // mover directions 
        if(mover == '^')
        {
            mrow--; 
        }
        else if(mover == 'v')
        {
            mrow++; 
        }
        else if(mover == '<')
        {
            mcol--; 
        }
        else if(mover == '>')
        {
            mcol++; 
        }

        //display mover path 
         if(LastRow!=0 && LastRow!=rows-1 && LastCol!=0 && LastCol!=cols-1)
           { 
                grid[LastRow][LastCol]='*';
           } 

        grid[mrow][mcol]=mover;   //set mover 
    }
    return true;
}


void Grid::TurnLeft()    //turn mover to the left, update mover character 
{
    if(mover == '^')
    {
        mover = '<';
        direction = WEST;  //if north turn west
    }
    else if(mover == '<')
    {
        mover = 'v';
        direction = SOUTH;   //if west turn south 
    }
    else if(mover == 'v')
    {
        mover = '>';
        direction = EAST; //if south turn east 
    }
    else if(mover == '>')
    {
        mover = '^';
        direction = NORTH;  //if east turn north 
    }
                                       
        grid[mrow][mcol] = mover; //update mover position 
}


bool Grid::FrontIsClear() const
{
    // Checks if the anything is in front of the mover
    // Returns grid move if not border or obstacle in the way 
    if(mover == '^')
    {
       return grid[mrow-1][mcol]!='#' && grid[mrow-1][mcol]!='@';
    }
    if(mover == '<')
    {
        return grid[mrow][mcol-1]!='#' && grid[mrow][mcol-1]!='@';
    }
    if(mover == 'v')
    {
        return grid[mrow+1][mcol]!='#' && grid[mrow+1][mcol]!='@';
    }
    if(mover == '>')
    {
       return grid[mrow][mcol+1]!='#' && grid[mrow][mcol+1]!='@';
    }
    return false; 
}

bool Grid::RightIsClear() const
{
    // Checks if the right of the mover is clear returns true if clear false otherwise
    if(mover == '^')
    {
        return grid[mrow][mcol+1]!='#' && grid[mrow][mcol+1]!='@';
                   
    }
    if(mover == '<')
    {
        return grid[mrow-1][mcol]!='#' && grid[mrow-1][mcol]!='@';
    }
    if(mover == 'v')
    {
       return grid[mrow][mcol-1]!='#' && grid[mrow][mcol-1]!='@';
    }
    if(mover == '>')
    {
        return grid[mrow+1][mcol]!='#' && grid[mrow+1][mcol]!='@';
    }

    return false; 
}

int Grid::GetRow() const
{
    return mrow;  //mover row
}

int Grid::GetCol() const
{
    return mcol;  //mover column 
}

int Grid::GetNumRows() const
{
    return rows;  //total rows
}

int Grid::GetNumCols() const
{
    return cols;  //total columns 
}

int Grid::GetDirection() const 
{
    return direction;   // current direction 
}