#include "mainClasses.cpp"
#include "mainFunctions.cpp"

int main()
{
    Board gameBoard;
    string nameX;
    string nameO;

    int tieGame = 0;
    char gameWinner = 'z';
    int numTurns = 0;

    //get the names of the players
    getUserNames(nameX, nameO);

    //the game is played for 8 turns maximum
    while (numTurns < 8)
    {
        //print a board that has the postions numbered
        printTheBoard(gameBoard);
        //ask player x where they want to put an 'x'
        printUserPrompt(nameX, 'x');
        //check that the input is a valid position and that
        //it has not already been taken
        checkResponse(gameBoard, 'x');

        //check to see if player 'x' has four in a row somewhere on the board
        gameWinner = determineWinner(gameBoard);
        //if player 'x' has won, end the game
        if (gameWinner != 'z')
        {
            printTheBoard(gameBoard);
            // writeTheBoard(gameBoard);
            printGameWinner(gameBoard, nameX, nameO);
            break;
        }

        //Now do the same for player 'o'
        printTheBoard(gameBoard);
        //ask player x where they want to put an 'o'
        printUserPrompt(nameO, 'o');
        checkResponse(gameBoard, 'o');

        //check to see if player 'o' has four in a row somewhere on the board
        gameWinner = determineWinner(gameBoard);
        //if player 'o' has won, end the game
        if (gameWinner != 'z')
        {
            printTheBoard(gameBoard);
            // writeTheBoard(gameBoard);
            printGameWinner(gameBoard, nameX, nameO);
            break;
        }
        numTurns++;
    }

    //if there is no winner at this point, the game is a tie
    if (numTurns >= 8)
        cout << "Tie game.\n";
    return 0;
}
