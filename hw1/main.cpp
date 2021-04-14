//
// Created by moaad on 3/23/2021.
//
#include <iostream>
#include "LinkedList.h"

using namespace std;


bool isBoardNameValid(string basicString);

bool isBoardExist(LinkedListPtr linkedList, string boardName);

char convertColor(string num);


int main() {
    LinkedListPtr linkedList = LLCreate();
    string cmd;

    while (cin >> cmd && cmd != "quit") {

        string name;
        if (cmd == "board") {

            int rows, cols = 0;
            cin >> name >> rows >> cols;
            if (rows <= 0 || cols <= 0) {
                cerr << "Board: number of rows and columns must be greater that zero" << endl;
                return -1;
            }
            if (!isBoardNameValid(name)) {
                cerr << "Invalid board name " << "'" << name << "'" << endl;
                return -1;
            }
            addBoard(linkedList, name, rows, cols);

        } else if (cmd == "plot") {
            int x, y = 0;
            string color;
            cin >> name >> x >> y >> color;
            if (!isBoardNameValid(name)) {
                cerr << "Invalid board name " << "'" << name << "'" << endl;
                return -1;
            }
            if (!isBoardExist(linkedList, name)) {
                cerr << "Board named " << "'" << name << "' not found" << endl;
                return -1;
            }
            if (convertColor(color) == '0') {
                cerr << "Invalid color number " << color << endl;
                return -1;

            }
            plot(x, y, convertColor(color), getBoard(linkedList, name));
        } else if (cmd == "line") {
            string color;
            int x1, x2, y1, y2;
            cin >> name >> x1 >> y1 >> x2 >> y2 >> color;
            if (!isBoardNameValid(name)) {
                cerr << "Invalid board name " << "'" << name << "'" << endl;
                return -1;
            }
            if (!isBoardExist(linkedList, name)) {
                cerr << "Board named " << "'" << name << "' not found" << endl;
                return -1;
            }
            if (convertColor(color) == '0') {
                cerr << "Invalid color number " << color << endl;
                return -1;

            }

            drawLine(x1, y1, x2, y2, convertColor(color), getBoard(linkedList, name));
        } else if (cmd == "circle") {
            string color;
            int cx, cy, r;
            cin >> name >> cx >> cy >> r >> color;
            if (!isBoardNameValid(name)) {
                cerr << "Invalid board name " << "'" << name << "'" << endl;
                return -1;
            }
            if (!isBoardExist(linkedList, name)) {
                cerr << "Board named " << "'" << name << "' not found" << endl;
                return -1;
            }
            if (convertColor(color) == '0') {
                cerr << "Invalid color number " << color << endl;
                return -1;

            }
            if (r < 0) {
                cerr << "Circle: radius must be non-negative" << endl;
                return -1;
            }
            drawCircle(cx, cy, r, convertColor(color), getBoard(linkedList, name));
        } else if (cmd == "fill") {
            string color;
            int x, y;
            cin >> name >> x >> y >> color;
            if (!isBoardNameValid(name)) {
                cerr << "Invalid board name " << "'" << name << "'" << endl;
                return -1;
            }
            if (!isBoardExist(linkedList, name)) {
                cerr << "Board named " << "'" << name << "' not found" << endl;
                return -1;
            }
            if (convertColor(color) == '0') {
                cerr << "Invalid color number " << color << endl;
                return -1;

            }
            if (color == "0") {
                cerr << "FloodFill: cannot flood with the background color" << endl;
                return -1;
            }
            floodFill(x, y, convertColor(color), getBoard(linkedList, name));
        } else if (cmd == "stamp") {
            string stampName;
            int x, y;
            cin >> name >> x >> y >> stampName;
            if (!isBoardNameValid(name)) {
                cerr << "Invalid board name " << "'" << name << "'" << endl;
                return -1;
            }
            if (!isBoardExist(linkedList, name)) {
                cerr << "Board named " << "'" << name << "' not found" << endl;
                return -1;
            }

            stamp(getBoard(linkedList, name), x, y, getBoard(linkedList, stampName));

        } else if (cmd == "print") {

            cin >> name;
            if (!isBoardNameValid(name)) {
                cerr << "Invalid board name " << "'" << name << "'" << endl;
                return -1;
            }
            if (!isBoardExist(linkedList, name)) {
                cerr << "Board named " << "'" << name << "' not found" << endl;
                return -1;
            }
            printBoard(getBoard(linkedList, name));

        } else {
            cerr << "unknown command " << "'" << cmd << "'" << endl;
            return -1;
        }
    }


//    clean

    LLDestroy(linkedList);


}


bool isBoardExist(LinkedListPtr linkedList, string boardName) {
    return getBoard(linkedList, boardName) != NULL;

}

bool isBoardNameValid(string str) {
    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')))
        return false;
    for (unsigned int i = 1; i < str.size(); i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= '0' && str[i] <= '9')))
            return false;

    }
    return true;

}

/*returns 0 in case invalid color code provided*/

char convertColor(string num) {

    if (num == "0")
        return ' ';
    if (num == "1")
        return '.';
    if (num == "2")
        return '+';
    if (num == "3")
        return '*';
    if (num == "4")
        return '/';
    if (num == "5")
        return '\\';
    if (num == "6")
        return '|';
    if (num == "7")
        return '-';

    return '0';

}





















