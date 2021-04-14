#ifndef LINKEDLIST_h
#define LINKEDLIST_h

#include "Board.h"
#include <iostream>

using namespace std;

typedef struct Node *NodePtr;
typedef struct LinkedList *LinkedListPtr;

LinkedListPtr LLCreate();

void LLDestroy(LinkedListPtr ll);

void addBoard(LinkedListPtr ll, string name, int rows, int cols, char color = ' ');

BoardPtr getBoard(LinkedListPtr ll, string name);


#endif
