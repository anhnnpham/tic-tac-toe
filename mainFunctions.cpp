
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
    getline(cin, userX);
    std::cout << "\nName of user to be 'o' :";
    getline(cin, userY);
    cout << "\n";
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
}

void printUserPrompt(string nameIn, char letter)
{ //prompt for user input
    std::cout << nameIn << ", where would you like to place an " << letter << "?\n";
}

void printGameWinner(Board boardIn, string nameIn)
{ //print the winner statement
    cout << "\n";
    cout << "Congrats " << nameIn << " you won!\n";
}

int getUserResponse()
{   //get the chosen user position, check that it is an integer
    //check that it is between 0 and 15 inclusive
    int position = -1;
    cout << "Enter an integer between 0 and 15: ";
    std::cin >> position;

    while (position > 15 || position < 0 || !cin)
    {
        cin.clear();
        cin.ignore();
        std::cout << "\nThat is not a valid position";
        cout << "\nEnter an integer between 0 and 15: ";
        cin >> position;
    }
    cout << "\n";
    return position;
}

bool determineWinner(Board gameBoard, char symbol, string nameIn)
{   //if 4 in a row/column/diagonal, then there is a winner
    bool isWinner = false;
    isWinner = gameBoard.checkRows(symbol);
    if (!isWinner)
        isWinner = gameBoard.checkColumns(symbol);
    if (!isWinner)
        isWinner = gameBoard.checkDiagonals(symbol);

    if (isWinner) // if there is a winner
    {
        printTheBoard(gameBoard);
        printGameWinner(gameBoard, nameIn);
        gameBoard.setWinner(symbol);
    }
    return isWinner;
}

