//
// Created by moaad on 4/18/2021.
//

#ifndef CPPCOURSE_BACKGAMMON_H
#define CPPCOURSE_BACKGAMMON_H

#include "iostream"
#include "RandomNumGenerator.h"

/*
 * I Have initialized the pieces from white perspective both whites and blacks
 * when playing from the black view use @convertIndexToBlackView function to convert the index
 * */

using namespace std;

class Backgammon {

public:

    explicit Backgammon(int seed);

//    prints ths board, the results depends on the current player
    void printBoard() const;

    void start();

private:

    int whitePieces[26];
    int blackPieces[26];


    RandomNumGenerator numGenerator;
    enum Player {
        WHITE, BLACK
    } currPlayer;

//    string currPlayer;
    string winner;
    static const int PRISON_INDEX = 25;
    static const int OUT_INDEX = 0;

    void setPlayer(Player player);

    void setFirstPlayer();

    int throwCube();

    bool isThereAPossibleMove(int cube1, int cube2);

    /*
    *  whitePerspective
    */
    void printUpperBoardSide() const;

    /*
    *  whitePerspective
    */
    void printLowerBoardSide() const;

    void printUpperBoard(int *tempWhite, int *tempBlack) const;

    void printLowerBoard(int *tempWhite, int *tempBlack) const;

/*
 * white perspective;
 */
    void initPieces();

    bool isThisMoveLegal(int from, int to, int cube1, int cube2) const;

    bool isAllPiecesAtHome() const;

    void replacePlayer();

    void move(int from, int to);

    bool didIWin() const;


/*
 * Since the board is white perspective 
  need to calculate the black index
  this function used when need to the black pieces
 */
    int convertIndexToBlackView(int index) const;
};

#endif //CPPCOURSE_BACKGAMMON_H
