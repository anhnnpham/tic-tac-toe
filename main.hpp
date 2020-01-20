#pragma once

#ifndef MAIN_HPP
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

class Board;

void printBlankBoard();
void printTheBoard(Board boardIn);
void checkResponse(Board &boardIn, char input);
void getUserNames(string &userX, string &userY);
void printUserPrompt(string nameIn, char letter);
void printGameWinner(Board boardIn, string nameIn);
int getUserResponse();
bool determineWinner(Board gameBoard, char symbol, string nameIn);

#endif // MAIN_HPP