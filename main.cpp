/* Create a 4x4 game board
Prompt the first user (the 'x' user) to enter their name
Prompt the second user (the 'o' user) to enter their name
Prompt the 'x' user to select a grid position where they would like to place an 'x'.
Prompt the 'o' user to select a grid position where they would like to place an 'o'.
After each user has a turn, check for any row, column, diagonal that has 4 'x's or 4 'o's.
If 4 'x's are found in the same col, row, diagonal, declare the 'x' user the winner.
If 4 'o's are found in the same col, row, diagonal, declare the 'o' user the winner.
End the game and declare the winner.
If the grid is filled (each player gets 8 turns) and there is not a row, column, diagonal
with 4 of the same symbol, the game is tied. Declare a tie game. */

#include "mainFunctions.cpp"
int main()
{
    string xPlayer, oPlayer;
    Gameboard theGame;

    /* cout << "x player pls: ";
    getline(cin, xPlayer);
    cout << xPlayer << '\n';
    theGame.setName(xPlayer, 0);
    
    cout << "o player pls: ";
    getline(cin, oPlayer);
    cout << oPlayer << '\n';
    theGame.setName(oPlayer, 1); */

    gameBegin(theGame);
    theGame.printInfo();
    return 0;
}
