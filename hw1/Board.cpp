//
// Created by moaad on 3/28/2021.
//

#include "Board.h"
#include "Utils.h"

#include <iostream>

using namespace std;

const char BACKGROUND_COLOR = ' ';

inline int abs(int a) { return a > 0 ? a : a * -1; }

inline int sign(int i) {
    return i > 0 ? 1 : i < 0 ? -1 : 0;
}


inline int getIndex(int x, int y, int cols) { return (x * cols) + y; }

struct Board {
    string name;
    int rows, cols;
    char *data;
};


BoardPtr createBoard(string name, int rows, int cols, char color) {
    BoardPtr board = new Board();
    board->name = name;
    board->rows = rows;
    board->cols = cols;

    board->data = new char[rows * cols];


    for (int i = 0; i < rows * cols; ++i) {
        (board->data)[i] = color;
    }

    return board;
}

string getBoardName(BoardPtr board) {
    return board->name;
}

void plot(int y, int x, char color, BoardPtr board) {
    if (x >= 0 && y >= 0 && x < board->rows && y < board->cols)
        board->data[getIndex(x, y, board->cols)] = color;

}


void drawLine(int x1, int y1, int x2, int y2, char color, BoardPtr board) {

    bool plotyx = false;
    if (abs(x2 - x1) < abs(y2 - y1)) {
        swap(x1, y1);
        swap(x2, y2);
        plotyx = true;

    }
    if (x2 < x1) {
        swap(x1, x2);
        swap(y1, y2);

    }

    int dx = x2 - x1;
    int dy = abs(y2 - y1);
    int sy = sign(y2 - y1);

    int e = -dx;
    int x = x1, y = y1;

    while (x <= x2) {
        if (plotyx) {
            plot(y, x, color, board);
        } else plot(x, y, color, board);
        x += 1;
        e += 2 * dy;
        if (e > 0) {
            y += sy;
            e -= 2 * dx;
        }
    }
}


void drawCircle(int cx, int cy, int r, char color, BoardPtr board) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    plot8(cx, cy, x, y, color, board);
    while (y >= x) {
        x += 1;
        if (d > 0) {
            y -= 1;
            d += 4 * (x - y) + 10;
        } else {
            d += 4 * x + 6;
        }
        plot8(cx, cy, x, y, color, board);
    }
}


void plot8(int cx, int cy, int x, int y, char color, BoardPtr board) {


    plot(cx + x, cy + y, color, board);
    plot(cx + x, cy - y, color, board);
    plot(cx - x, cy + y, color, board);
    plot(cx - x, cy - y, color, board);

    plot(cx + y, cy + x, color, board);
    plot(cx + y, cy - x, color, board);
    plot(cx - y, cy + x, color, board);
    plot(cx - y, cy - x, color, board);

}

void floodFill(int x, int y, char color, BoardPtr board) {

    if (!(x >= 0 && y >= 0 && x < board->cols && y < board->rows) ||
        board->data[getIndex(y, x, board->cols)] != BACKGROUND_COLOR)
        return;
    plot(x, y, color, board);
    floodFill(x + 1, y, color, board);
    floodFill(x - 1, y, color, board);
    floodFill(x, y + 1, color, board);
    floodFill(x, y - 1, color, board);
}

void deleteBoard(BoardPtr board) {
    delete board->data;

}

void printBoard(BoardPtr board) {
    int j = 0;
    for (int i = 0; i < board->rows * board->cols; ++i) {
        cout << board->data[i];
//        print new line each line finish's
        if (j == board->cols - 1) {
            cout << endl;
            j = -1;
        }
        j++;
    }


}

void stamp(BoardPtr board, int x, int y, BoardPtr stampBoard) {
    int rowCounter = 0;
    for (int j = getIndex(y, x, board->cols), i = 0; i < stampBoard->cols * stampBoard->rows;
         i++, j++) {
        board->data[j] = stampBoard->data[i];
//        checking when need to jump to the next row
        if (rowCounter == stampBoard->cols - 1) {
            j = getIndex(++y, x, board->cols) - 1;
            rowCounter = -1;
        }
        rowCounter++;
    }
}

