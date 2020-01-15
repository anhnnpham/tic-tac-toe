#include "mainClasses.cpp"

void gameBegin();
void gameBegin(Gameboard theGame)
{
    int pos;
    for (size_t turn = 0; turn < 8; turn++)
    {
        int res;
        cout << "x player's grid position? ";
        cin >> pos;
        cout << pos << '\n';
        theGame.setGameSpace(pos, 'x');

        theGame.printInfo();

        res = theGame.fourInRow('x');
        if (res == 1)
        {
            cout << "Endgame";
            return;
        }

        cout << "o player's grid position? ";
        cin >> pos;
        cout << pos << '\n';
        theGame.setGameSpace(pos, 'o');

        res = theGame.fourInRow('o');
        if (res == 1)
        {
            cout << "Endgame";
            return;
        }
    }
    cout << "It's a tie" << endl;
}