//Sarah Fieg, section 5
class Grid 
{
public:
    // public static class constants, for direction indicators
    static const int NORTH = 0;
    static const int WEST = 1;
    static const int SOUTH = 2;
    static const int EAST = 3;

    // public member funcitons

    Grid();			// build 1 x 1 grid with mover in only
    //  square, facing east
    Grid(int r, int c);		// build grid with r rows, c cols,
    //  blocks around edge with random exit
    //  and random mover position and direction

    bool Move(int s);		// move forward s spaces, if possible
    void TurnLeft();		// turn the mover to the left
    void Display() const;	// display the grid on screen

    // Accessors
    bool FrontIsClear() const;	// check to see if space in front of 
    //  mover is clear
    bool RightIsClear() const;	// check to see if space to right of 
    //  mover is clear
    int GetRow() const;		// return row of the mover
    int GetCol() const;		// return column of the mover
    int GetNumRows() const;	// return number of rows in the grid
    int GetNumCols() const;	// return number of columns in the grid
    int GetDirection() const;  // returns current mover direction 

private:
    void Set(int r, int c);  // Sets up the beginning grid of characters for constructors 
    int mrow, mcol; //mover row and column
    int direction; //direction of mover 
    int rows, cols; 
    int LastRow, LastCol; //function helpers
    int ExitWall, Exit; //find random exit 
    char mover; 
    char grid[40][40];          // grid with path showing
};


