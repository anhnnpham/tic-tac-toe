void getUserNames(string &, string &);
void printBlankBoard(string);
void printTheBoard(Board, string);
void printUserPrompt(string, char);
void printGameWinner(Board, string, string);
int getUserResponse();
void checkResponse(Board &, char);
char determineWinner(Board gameBoard);
char checkRows(Board gameBoard);
char checkColumns(Board gameBoard);
char checkDiagonals(Board gameBoard);

void checkResponse(Board &boardIn, char input)
{   //check that the position selected is not already selected
    int position;
    int userInput;
    do
    {
        position = getUserResponse();
        userInput = boardIn.setPosition(position, input);
    } 
    while (userInput == -1);
}

void getUserNames(string &userX, string &userY)
{ //get the user names
    std::cout << "Name of user to be 'x' :";
    std::cin >> userX;
    std::cout << "\nName of user to be 'o' :";
    std::cin >> userY;
}

void printBlankBoard()
{   //print a blank board, with numbered squares
    cout << "\n";
    for (int i = 0; i < 16; i++)
    {
        std::cout << "|" << i << ":";
        if (i <= 9)
            cout << " ";
        if (i % 4 == 3)
        {
            std::cout << "|\n";
        }
    }
    cout << "\n";
}

void printTheBoard(Board boardIn)
{ //print the board with player moves
    printBlankBoard();

    for (int i = 0; i < 16; i++)
    {
        std::cout << "|" << boardIn.getPositions()[i];
        if (i % 4 == 3)
        {
            std::cout << "|\n";
        }
    }
    // cout << "\n";
}

void printUserPrompt(string nameIn, char letter)
{ //prompt for user input
    std::cout << nameIn << ", where would you like to place an " << letter << "?\n";
}

void printGameWinner(Board boardIn, string nameX, string nameO)
{ //print the winner statement
    char winner;
    winner = determineWinner(boardIn);
    cout << "\n";
    if (winner == 'x')
    {
        cout << "Congrats " << nameX << " you won!\n";
    }
    if (winner == 'o')
    {
        cout << "Congrats " << nameO << " you won!\n";
    }
}

int getUserResponse()
{   //get the chosen user position, check that it is an integer
    //check that it is between 0 and 15 inclusive
    int position = -1;
    cout << "Enter an integer between 0 and 15: ";
    std::cin >> position;

    while (position > 15 or position < 0 or !cin)
    {
        cin.clear();
            // cin.ignore(256, '\n');
        cin.ignore();
        std::cout << "\nThat is not a valid position";
        cout << "\nEnter an integer between 0 and 15: ";
        cin.clear();
        cin.ignore();
        cin >> position;
    }
    cout << "\n";
    return position;
}

char determineWinner(Board gameBoard)
{ //if 4 in a row, then there is a winner
    char winner = 'z';
    winner = checkRows(gameBoard);
    if (winner == 'z')
        winner = checkColumns(gameBoard);
    if (winner == 'z')
        winner = checkDiagonals(gameBoard);
    return winner;
}

char checkRows(Board gameBoard)
{   //check the rows for a winner
    int rows = 0, columns = 0;
    int fourInRowX = 0, fourInRowO = 0;

    //Check rows for a winner
    for (int rows = 0; rows < 16; rows = rows + 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (gameBoard.getPositions[i + rows] == 'x')
                fourInRowX++;
            if (gameBoard.getPositions[i + rows] == 'o')
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

char checkColumns(Board gameBoard)
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
            if (gameBoard.getPositions[i + columns] == 'x')
                fourInRowX++;
            if (gameBoard.getPositions[i + columns] == 'o')
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

char checkDiagonals(Board gameBoard)
{ //check the diagonals for a winner
    char winner = 'z';
    int fourInRowX = 0;
    int fourInRowO = 0;

    //check left to right diagonal
    for (int i = 0; i < 16; i = i + 5)
    {
        if (gameBoard.getPositions[i] == 'x')
            fourInRowX++;
        if (gameBoard.getPositions[i] == 'o')
            fourInRowO++;
    }

    //check right to left diagonal
    if (fourInRowO != 4 and fourInRowX != 4)
    {
        fourInRowX = 0;
        fourInRowO = 0;
        for (int i = 3; i < 15; i = i + 3)
        {
            if (gameBoard.getPositions[i] == 'x')
                fourInRowX++;
            if (gameBoard.getPositions[i] == 'o')
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
}