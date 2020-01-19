#include "main.hpp"

class Board
{
private:
    //the class tracks the game and the winner
    char positionsSelected[16];
    char winner;

public:
    Board(); // if private --> can't access positionsSelected
    char* getPositions(void);
    int setPosition(int gridNumber, char user);
    // char determineWinner();
    // char checkRows();
    // char checkColumns();
    // char checkDiagonals();
};

Board::Board()
{   // sets the board to blanks and the winner to 'z'
    // z = not determined or tie
    winner = 'z';
    for (int i = 0; i < 16; i++)
    {
        positionsSelected[i] = '_';
    }
}

char* Board::getPositions(void)
{   //return all the positions on the board
    return positionsSelected; // get whole string/all chars
    // static_cast if want to get address of char[]
}

int Board::setPosition(int gridNumber, char user)
{   //set a given position to x or o
    if (positionsSelected[gridNumber] == '_')
    {
        positionsSelected[gridNumber] = user;
        return 0;
    }
    else
    {
        cout << "That postition is taken. ";
        return -1;
    }
    return 0;
}

/* char Board::determineWinner()
{ //if 4 in a row, then there is a winner
    char winner = 'z';
    winner = checkRows();
    if (winner == 'z')
        winner = checkColumns();
    if (winner == 'z')
        winner = checkDiagonals();
    return winner;
} */

/* char Board::checkRows()
{   //check the rows for a winner
    int rows = 0;
    int columns = 0;
    int fourInRowX = 0;
    int fourInRowO = 0;

    //Check rows for a winner
    for (int rows = 0; rows < 16; rows = rows + 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (positionsSelected[i + rows] == 'x')
                fourInRowX++;
            if (positionsSelected[i + rows] == 'o')
                fourInRowO++;
        }
        if (fourInRowX == 4)
        {
            winner = 'x';
            return 'x';
        }
        if (fourInRowO == 4)
        {
            winner = 'o';
            return 'o';
        }
        fourInRowX = 0;
        fourInRowO = 0;
    }
    return 'z';
}

char Board::checkColumns()
{ //check the columns for a winner
    int rows = 0;
    int columns = 0;
    int fourInRowX = 0;
    int fourInRowO = 0;

    //Check columns for a winner
    for (int columns = 0; columns < 4; columns++)
    {
        for (int i = 0; i < 16; i = i + 4)
        {
            if (positionsSelected[i + columns] == 'x')
                fourInRowX++;
            if (positionsSelected[i + columns] == 'o')
                fourInRowO++;
        }
        if (fourInRowX == 4)
        {
            winner = 'x';
            return 'x';
        }
        if (fourInRowO == 4)
        {
            winner = 'o';
            return 'o';
        }
        fourInRowX = 0;
        fourInRowO = 0;
    }
    return 'z';
}

char Board::checkDiagonals()
{ //check the diagonals for a winner
    char winner = 'z';
    int fourInRowX = 0;
    int fourInRowO = 0;

    //check left to right diagonal
    for (int i = 0; i < 16; i = i + 5)
    {
        if (positionsSelected[i] == 'x')
            fourInRowX++;
        if (positionsSelected[i] == 'o')
            fourInRowO++;
    }

    //check right to left diagonal
    if (fourInRowO != 4 and fourInRowX != 4)
    {
        fourInRowX = 0;
        fourInRowO = 0;
        for (int i = 3; i < 15; i = i + 3)
        {
            if (positionsSelected[i] == 'x')
                fourInRowX++;
            if (positionsSelected[i] == 'o')
                fourInRowO++;
        }
    }

    if (fourInRowX == 4)
    {
        winner = 'x';
        return winner;
    }
    if (fourInRowO == 4)
    {
        winner = 'o';
        return winner;
    }
    fourInRowX = 0;
    fourInRowO = 0;
    return winner;
} */