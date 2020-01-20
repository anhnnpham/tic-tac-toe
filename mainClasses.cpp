#include "main.hpp"

class Board
{ //the class tracks the game and the winner
private:
    char _winner;
    char _positionsSelected[16]; // can also be a 2D char [4][4]
public:
    Board(); // if private --> can't access positionsSelected
    char *getPositions(void);
    int setPosition(int gridNumber, char user);
    void setWinner(char symbol);
    bool checkRows(char symbol);
    bool checkColumns(char symbol);
    bool checkDiagonals(char symbol);
};

Board::Board()
{ // sets the board to blanks and the winner to 'z'
    // z = not determined or tie
    _winner = 'z';
    for (int i = 0; i < 16; i++)
    {
        _positionsSelected[i] = '_';
    }
}

char *Board::getPositions(void)
{                              //return all the positions on the board
    return _positionsSelected; // get whole string/all chars
    // static_cast if want to get address of char[]
}

int Board::setPosition(int gridNumber, char user)
{ //set a given position to x or o
    if (_positionsSelected[gridNumber] == '_')
    {
        _positionsSelected[gridNumber] = user;
        return 0;
    }
    cout << "That postition is taken. ";
    return -1;
}

void Board::setWinner(char symbol)
{
    _winner = symbol;
}

bool Board::checkRows(char symbol)
{ //check the rows for a winner
    int fourInRowX = 0, counter = 0;
    // better time complexity than nested for-loops
    for (int i = 0; i < 16; i++)
    {
        ++counter;
        if (_positionsSelected[i] == symbol)
        {
            fourInRowX++;
            if (fourInRowX == 4)
            {
                // ('x');
                return true;
            }
        }
        if (counter == 4)
        {
            counter = 0;
            fourInRowX = 0;
        }
    }
    return false;
}

bool Board::checkColumns(char symbol)
{ //check the columns for a winner
    int fourInRowX = 0;

    //Check columns for a winner
    for (int columns = 0; columns < 4; columns++)
    {
        for (int i = 0; i < 16; i = i + 4) // 0 4 8 12
        {
            if (_positionsSelected[i] == symbol)
            {
                fourInRowX++;
            }
        }
        if (fourInRowX == 4)
        {
            // ('x');
            return true;
        }
        fourInRowX = 0;
    }
    return false;
}

bool Board::checkDiagonals(char symbol)
{ //check the diagonals for a winner
    bool winner;
    int fourInRowX = 0;

    //check top left to bottom right diagonal
    for (int i = 0; i < 16; i = i + 5) // 0 5 10 15
    {
        if (_positionsSelected[i] == symbol)
        {
            fourInRowX++;
        }
    }
    if (fourInRowX == 4)
    {
        // ('x');
        return true;
    }

    //check top right to bottom left diagonal
    fourInRowX = 0;
    for (int i = 3; i < 15; i = i + 3) // 3 6 9 12
    {
        if (_positionsSelected[i] == symbol)
        {
            fourInRowX++;
        }
    }
    if (fourInRowX == 4)
    {
        // ('x');
        return true;
    }
    return false;
}