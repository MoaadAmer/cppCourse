//
// Created by moaad on 3/28/2021.
//

#ifndef CPPCOURSE_BOARD_H
#define CPPCOURSE_BOARD_H

#include <iostream>

using namespace std;

typedef struct Board *BoardPtr;

BoardPtr createBoard(string name, int rows, int cols, char color = ' ');

void plot(int x, int y, char color, BoardPtr board);

void drawLine(int x1, int y1, int x2, int y2, char color, BoardPtr board);

void drawCircle(int cx, int cy, int r, char color, BoardPtr board);

void plot8(int cx, int cy, int x, int y, char color, BoardPtr board);

void floodFill(int x, int y, char color, BoardPtr board);

void deleteBoard(BoardPtr board);

string getBoardName(BoardPtr board);

void printBoard(BoardPtr board);

void stamp(BoardPtr board, int x, int y, BoardPtr stampBoard);


#endif //CPPCOURSE_BOARD_H
