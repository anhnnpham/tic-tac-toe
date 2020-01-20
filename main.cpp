#include "mainClasses.cpp"
#include "mainFunctions.cpp"

int main()
{
    Board gameBoard;
    string nameX;
    string nameO;
    //get the names of the players
    getUserNames(nameX, nameO);

    int numTurns = 0;
    bool isWinner;
    char symbol;
    //the game is played for 8 turns maximum
    while (numTurns < 8)
    {
        symbol = 'x'; // x's turn
        //print a board that has the postions numbered
        printTheBoard(gameBoard);
        //ask player X where they want to put an 'x'
        printUserPrompt(nameX, symbol);
        //check that the input is a valid position and that
        //it has not already been taken
        checkResponse(gameBoard, symbol);

        //check to see if player 'x' has four in a row somewhere on the board
        isWinner = determineWinner(gameBoard, symbol, nameX);
        //if player 'x' has won, end the game
        if (isWinner)
            return 0;

        symbol = 'o'; // o's turn
        printTheBoard(gameBoard);
        //ask player O where they want to put an 'o'
        printUserPrompt(nameO, symbol);
        checkResponse(gameBoard, symbol);

        //check to see if player 'o' has four in a row somewhere on the board
        isWinner = determineWinner(gameBoard, symbol, nameO);
        //if player 'o' has won, end the game
        if (isWinner)
            return 0;
        
        numTurns++; // end of 1 turn
    }
    
    //if there is no winner at this point, the game is a tie
    cout << "Tie game.\n";
    return 0;
}
