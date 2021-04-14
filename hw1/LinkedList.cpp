#include <cstdlib>
#include <typeinfo>
#include "LinkedList.h"
#include "Board.h"


/*******************************************************************************/


struct Node {
    BoardPtr board;
    NodePtr next;
};

struct LinkedList {
    NodePtr head;
};

/*******************************************************************************/

LinkedListPtr LLCreate() {
    LinkedListPtr ll;
    try {
        ll = new LinkedList();
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
        cout << typeid(ex).name() << endl;
        exit(-1);

    }
    return ll;
}

void LLDestroy(LinkedListPtr ll) {

    NodePtr temp, curr;
    temp = curr = ll->head;

    while (curr) {
        if (curr->board) {
            deleteBoard(curr->board);
        }
        curr = curr->next;
        delete temp;
        temp = curr;

    }

    delete ll;

}

/*******************************************************************************/
void addBoard(LinkedListPtr ll, string name, int rows, int cols, char color) {

    // Create the new node

    Node *new_node;
    try {
        new_node = new Node();
    }
    catch (exception &ex) {
        cout << ex.what() << endl;
        cout << typeid(ex).name() << endl;
        exit(-1);
    }

//    create the board and set the desired background color
    new_node->board = createBoard(name, rows, cols, color);


    new_node->next = ll->head;
    ll->head = new_node;

}

BoardPtr getBoard(LinkedListPtr ll, string boardName) {
    NodePtr currNode = ll->head;
    while (currNode) {
        if (getBoardName(currNode->board) == boardName) {
/*
            BoardPtr boardPtr = new Board();
            boardPtr->name = currNode->board->name;
            boardPtr->rows = currNode->board->rows;
            boardPtr->cols = currNode->board->cols;
            return boardPtr;*/

            return currNode->board;
        }
        currNode = currNode->next;
    }

    return NULL;
}





