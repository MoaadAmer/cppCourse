//
// Created by moaad on 4/18/2021.
//

#include "Backgammon.h"
#include "Utils.h"

using namespace std;


Backgammon::Backgammon(int seed) : numGenerator(seed) {
    initPieces();
    setFirstPlayer();
}

void Backgammon::printBoard() const {
    int tempWhite[26], tempBlack[26];

    for (int i = 0; i < 26; ++i) {
        tempWhite[i] = whitePieces[i];
        tempBlack[i] = blackPieces[i];
    }
    if (currPlayer == WHITE) {
        printUpperBoardSide();
    } else {
        printLowerBoardSide();
    }

    printUpperBoard(tempWhite, tempBlack);
    printLowerBoard(tempWhite, tempBlack);


    if (currPlayer == WHITE) {
        printLowerBoardSide();
    } else {
        printUpperBoardSide();
    }
    cout << endl;
}

void
Backgammon::printLowerBoard(int *tempWhite, int *tempBlack) const {//print the lower half

    int max1 = Utils::findMax(tempWhite, 1, 13);
    int max2 = Utils::findMax(tempBlack, 1, 13);
    int depth = Utils::max(max1, max2);
    depth = depth < 5 ? 5 : depth;

    for (int i = 0; i < depth; i++) {
        for (int j = 12; j > 0; j--) {
            if (j == 12)
                cout << "+";
            if (tempWhite[j] != 0 && tempWhite[j] == depth - i) {
                cout << " W ";
                tempWhite[j] -= 1;
            } else if (tempBlack[j] != 0 && tempBlack[j] == depth - i) {
                cout << " B ";
                tempBlack[j] -= 1;
            } else
                cout << " | ";
            if (j == 7) {
                if (tempBlack[PRISON_INDEX] != 0 && tempBlack[PRISON_INDEX] == depth - i) {
                    cout << "+B+";
                    tempBlack[PRISON_INDEX]--;
                } else
                    cout << "+ +";
            }
        }
        cout << "+" << endl;
    }
}

void Backgammon::printUpperBoard(int *tempWhite, int *tempBlack) const {//        print the upper half

    int max1 = Utils::findMax(tempWhite, 13, 26);
    int max2 = Utils::findMax(tempBlack, 13, 25);
    int depth = Utils::max(max1, max2);
    depth = depth < 5 ? 5 : depth;
    for (int i = 0; i < depth; i++) {
        for (int j = 13; j < 25; j++) {
            if (j == 13)
                cout << "+";
            if (tempWhite[j] != 0) {
                cout << " W ";
                tempWhite[j] -= 1;
            } else if (tempBlack[j] != 0) {
                cout << " B ";
                tempBlack[j] -= 1;
            } else
                cout << " | ";
            if (j == 18) {
                if (tempWhite[PRISON_INDEX] != 0) {
                    cout << "+W+";
                    tempWhite[PRISON_INDEX]--;
                } else
                    cout << "+ +";
            }

        }

        cout << "+" << endl;
    }

    cout << "+                  + +                  +" << endl;
}

void Backgammon::printLowerBoardSide() const {

    if (currPlayer == WHITE) {
        cout << "+------------------+-+------------------+" << endl;

    }

    for (int i = 12; i > 0; --i) {
        if (i >= 10)
            cout << " " << i;
        else
            cout << "  " << i;

        if (i == 7)
            cout << "   ";
    }

    if (currPlayer == BLACK) {
        cout << endl;
        cout << "+------------------+-+------------------+" << endl;
    }

}

void Backgammon::printUpperBoardSide() const {

    if (currPlayer == BLACK) {
        cout << "+------------------+-+------------------+" << endl;
    }

    for (int i = 13; i < 25; i++) {
//        one space needed in case its 2 digits number
        if (i >= 10)
            cout << " " << i;
        else
            cout << "  " << i;

//            Middle of the board needs more spaces
        if (i == 18)
            cout << "   ";
    }
    if (currPlayer == WHITE) {
        cout << endl;
        cout << "+------------------+-+------------------+" << endl;
    }
}

void Backgammon::setPlayer(Player player) {

    currPlayer = player;
}

void Backgammon::setFirstPlayer() {

    int w, b;
    while (true) {
        w = throwCube();
        b = throwCube();
        if (w > b) {
            setPlayer(WHITE);
        } else if (b > w) {
            setPlayer(BLACK);
        }

        cout << "White player casts " << w << ", black player casts " << b << endl;
        if (w > b || b > w) {

            if (w > b)
                cout << "White plays first." << endl;
            else
                cout << "Black plays first." << endl;
            return;
        }


    }


}

int Backgammon::throwCube() {
    return (numGenerator.generateRandomNum() % 6) + 1;

}

void Backgammon::start() {

    while (winner.empty()) {


        printBoard();

        int cube1 = throwCube();
        int cube2 = throwCube();
        int count;
        if (cube1 == cube2)
            count = 4;
        else count = 2;
        string player = (currPlayer == WHITE) ? "White" : "Black";
        cout << player << " rolls " << cube1 << "-" << cube2 << "." << endl;

        while (count != 0) {
            if (isThereAPossibleMove(cube1, cube2)) {
                int from, to;
                bool notLegal;
                do {
                    cout << "Enter " << player << " move: " << endl;
                    if (!(cin >> from >> to)) {
                        cout << "Missing user input - quiting game." << endl;
                        return;
                    }
                    notLegal = !isThisMoveLegal(from, to, cube1, cube2);
                } while (notLegal);
                move(from, to);
                count--;
            } else {
                cout << "No possible move for " << player << endl;
                break;
            }
            if (didIWin()) {
                cout << player << " player wins!" << endl;
                winner = player;
                return;
            }
        }
        replacePlayer();
    }


}

void Backgammon::replacePlayer() {
    if (currPlayer == WHITE)
        setPlayer(BLACK);
    else
        setPlayer(WHITE);
}

bool Backgammon::isThereAPossibleMove(int cube1, int cube2) {

    bool needToSetFree = false;
    if (currPlayer == WHITE) {
        needToSetFree = whitePieces[PRISON_INDEX] != 0 ? true : false;

        if (needToSetFree) {
            if ((whitePieces[PRISON_INDEX - cube1] >= 0 && blackPieces[PRISON_INDEX - cube1] == 0) ||
                (blackPieces[PRISON_INDEX - cube1] <= 1) ||
                (whitePieces[PRISON_INDEX - cube2] >= 0 && blackPieces[PRISON_INDEX - cube2] == 0) ||
                (blackPieces[PRISON_INDEX - cube2] <= 1))
                return true;
            return false;
        } else {
            for (int i = 24; i > 0; i--) {
                if (whitePieces[i] != 0) {
                    if ((i - cube1 >= 1 && whitePieces[i - cube1] >= 0) || blackPieces[i - cube1] <= 1)
                        return true;
                    if ((i - cube2 >= 1 && whitePieces[i - cube2] >= 0) || blackPieces[i - cube2] <= 1)
                        return true;
                }
            }
            if (isAllPiecesAtHome()) {
                if (whitePieces[cube1] != 0 || whitePieces[cube2] != 0)
                    return true;
                for (int i = 6; i > 0; i--) {
                    if (whitePieces[i] != 0 && (i <= cube1 || i <= cube2))
                        return true;
                }
            }
            return false;
        }
    } else {
        needToSetFree = blackPieces[PRISON_INDEX] != 0 ? true : false;

        if (needToSetFree) {
            if ((blackPieces[cube1] >= 0 && whitePieces[cube1] == 0) ||
                whitePieces[cube1] <= 1 ||
                (blackPieces[cube2] >= 0 && whitePieces[cube2] == 0) ||
                whitePieces[cube2] <= 1)
                return true;
            return false;
        } else {
            for (int i = 1; i < 25; i++) {
                if (blackPieces[i] != 0) {
                    if ((i + cube1 <= 24 && blackPieces[i + cube1] >= 0) || whitePieces[i + cube1] <= 1)
                        return true;
                    if ((i + cube2 <= 24 && blackPieces[i + cube2] >= 0) || whitePieces[i + cube2] <= 1)
                        return true;
                }
            }
            if (isAllPiecesAtHome()) {
                if (blackPieces[convertIndexToBlackView(cube1)] != 0 ||
                    blackPieces[convertIndexToBlackView(cube2)] != 0)
                    return true;
                for (int i = 19; i < 25; i++) {
                    if (blackPieces[i] != 0 && (i <= convertIndexToBlackView(cube1) ||
                                                i <= convertIndexToBlackView(cube2)))
                        return true;
                }
            }

        }
        return false;
    }
}


void Backgammon::initPieces() {

    for (int i = 0; i < 26; ++i) {
        whitePieces[i] = blackPieces[i] = 0;
    }
    whitePieces[24] = 2;
    blackPieces[19] = 5;
    blackPieces[17] = 3;
    whitePieces[13] = 5;
    blackPieces[12] = 5;
    whitePieces[8] = 3;
    whitePieces[6] = 5;
    blackPieces[1] = 2;

}

bool Backgammon::isThisMoveLegal(int from, int to, int cube1, int cube2) const {

    if (from > 25 || from < 1 || to < 0 || to > 24 || from - to < 1 || from - to > 6) {
        cout << "Illegal move: From/to out of bounds (from=" << from << ", to=" << to << ")." << endl;
        return false;
    }

    if (currPlayer == WHITE) {
        if (whitePieces[25] != 0 && from != 25) {
            cout << "Illegal move: Player still has captured piece(s)." << endl;
            return false;
        }

        if (whitePieces[from] == 0 && !isAllPiecesAtHome()) {
            cout << "Illegal move: No pieces at from location " << from << "." << endl;
            return false;
        }


        if (to != 0 && blackPieces[to] > 1) {
            cout << "Illegal move: Cannot capture more that one piece at location " << to << "." << endl;
            return false;
        }

    } else {
        if (blackPieces[25] != 0 && from != 25) {
            cout << "Illegal move: Player still has captured piece(s)." << endl;
            return false;
        }

        if (blackPieces[convertIndexToBlackView(from)] == 0 && !isAllPiecesAtHome()) {
            cout << "Illegal move: No pieces at from location " << from << "." << endl;
            return false;
        }


        if (to != 0 && whitePieces[convertIndexToBlackView(to)] > 1) {
            cout << "Illegal move: Cannot capture more that one piece at location " << to << "." << endl;
            return false;
        }

    }
    if (to == 0 && !isAllPiecesAtHome()) {
        cout << "Illegal move: Cannot bear off while not all pieces at home." << endl;
        return false;
    }
    if ((from - to) != cube1 && (from - to) != cube2 && !isAllPiecesAtHome() && to != 0) {
        cout << "Illegal move: No value of " << (from - to) << " in dice roll " << endl;
        return false;

    }

    return true;
}

bool Backgammon::isAllPiecesAtHome() const {
    if (currPlayer == WHITE) {

        for (int i = 25; i > 6; i--)
            if (whitePieces[i] != 0)
                return false;
    } else {
        for (int i = 1; i < 19; i++)
            if (blackPieces[i] != 0)
                return false;
    }

    return true;
}

void Backgammon::move(int from, int to) {
    if (currPlayer == WHITE) {
//        The case when there is all of the pieces are below the cube
        if (isAllPiecesAtHome()) {
            bool needToGoOut = true;
            int cube = from - to;
            if (whitePieces[cube] == 0) {
                for (int i = 6; i > cube; i++) {
//                    no need to do anything
                    if (whitePieces[i] != 0) {
                        needToGoOut = false;
                        break;
                    }
                }
                if (needToGoOut)
                    for (int i = cube - 1; i > 0; i--) {
                        if (whitePieces[i] != 0) {
                            whitePieces[i]--;
                            whitePieces[OUT_INDEX]++;
                            return;
                        }
                    }
            }
        }
        whitePieces[from]--;
        whitePieces[to]++;
        if (blackPieces[to] == 1) {
            blackPieces[to]--;
            blackPieces[PRISON_INDEX]++;
        }

    } else {

        if (isAllPiecesAtHome()) {
            bool needToGoOut = true;
            int cube = from - to;
            if (blackPieces[convertIndexToBlackView(cube)] == 0) {
                for (int i = 6; i > cube; i++) {
//                    no need to do anything
                    if (blackPieces[i] != 0) {
                        needToGoOut = false;
                        break;
                    }
                }
                if (needToGoOut)
                    for (int i = cube - 1; i > 0; i--) {
                        if (blackPieces[convertIndexToBlackView(i)] != 0) {
                            blackPieces[convertIndexToBlackView(i)]--;
                            blackPieces[OUT_INDEX]++;
                            return;
                        }
                    }
            }
        }

        blackPieces[convertIndexToBlackView(from)]--;
        blackPieces[convertIndexToBlackView(to)]++;
        if (whitePieces[convertIndexToBlackView(to)] == 1) {
            whitePieces[convertIndexToBlackView(to)]--;
            whitePieces[PRISON_INDEX]++;
        }

    }
}

bool Backgammon::didIWin() const {
    if (currPlayer == WHITE)
        return whitePieces[OUT_INDEX] == 15;
    else
        return blackPieces[OUT_INDEX] == 15;
}

int Backgammon::convertIndexToBlackView(int index) const {
    switch (index) {
        case 1:
            return 24;
        case 2:
            return 23;
        case 3:
            return 22;
        case 4:
            return 21;
        case 5:
            return 20;
        case 6:
            return 19;
        case 7:
            return 18;
        case 8:
            return 17;
        case 9:
            return 16;
        case 10:
            return 15;
        case 11:
            return 14;
        case 12:
            return 13;
        case 13:
            return 12;
        case 14:
            return 11;
        case 15:
            return 10;
        case 16:
            return 9;
        case 17:
            return 8;
        case 18:
            return 7;
        case 19:
            return 6;
        case 20:
            return 5;
        case 21:
            return 4;
        case 22:
            return 3;
        case 23:
            return 2;
        case 24:
            return 1;
        default:
            return index;
    }
}




