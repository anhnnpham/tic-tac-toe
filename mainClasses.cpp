/*header file for main.cpp*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Gameboard
{
    char gameSpace[16];
    string name[2];
public:
    Gameboard();
    void setName(string nameInput, int index);
    void setGameSpace(int pos, char value);
    char getGameSpace(int pos);
    int fourInRow(char sym);
    void printInfo();
};

Gameboard::Gameboard()
{
    for (int i = 0; i < 16; i++)
    {
        gameSpace[i] = '-';
    }
}
void Gameboard::setName(string nameInput, int index)
{
    name[index] = nameInput;    
}
void Gameboard::setGameSpace(int pos, char value)
{
    gameSpace[pos] = value;
}

char Gameboard::getGameSpace(int pos)
{
    return gameSpace[pos];
}

int Gameboard::fourInRow(char sym)
{
    int pos, count = 0;
    // same column
    for (pos = 0; pos < 16; pos += 4)
    {
        for (size_t incr = 0; incr < 4; incr++)
        {
            if (gameSpace[pos + incr] == sym)
            {
                ++count;
                if (count == 4)
                {
                    cout << sym << " player is the winner!\n";
                    return 1;
                }
            }
        }
        count = 0; // must reset count b4 going to "same row"
    }

    // same row
    for (pos = 0; pos < 4; pos++)
    {
        for (size_t incr = 0; incr < 4; incr += 4) // 0 4 8 12
        {
            if (gameSpace[pos + incr] == sym)
            {
                ++count;
                if (count == 4)
                {
                    cout << sym << " player is the winner!\n";
                    return 1;
                }
            }
        }
        count = 0; // must reset count b4 going to "same diagonal"
    }

    // same diagonal, top left -> bot right
    for (pos = 0; pos < 16; pos += 5) // 0 5 10 15
    {
        if (gameSpace[pos] == sym) // every pos
        {
            ++count;
            if (count == 4)
            {
                cout << sym << " player is the winner!\n";
                return 1;
            }
        }
    }
    count = 0;

    // same diagonal, top right -> bot left
    for (pos = 12; pos > 0; pos -= 3) // 12 9 6 3
    {
        if (gameSpace[pos] == sym) // every pos
        {
            ++count;
            if (count == 4)
            {
                cout << sym << " player is the winner!\n";
                return 1;
            }
        }
    }
    count = 0;
    return 0;
}
void Gameboard::printInfo()
{
    cout << std::setw(5);
    cout << "\n";
    for (int pos = 0; pos < 4; pos++)
    {
        for (size_t incr = 0; incr < 4; incr++)
        {
            cout << gameSpace[pos + incr] << " ";
        }
        cout << '\n';
    }
}