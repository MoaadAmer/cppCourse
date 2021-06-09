//
// Created by moaad on 5/15/2021.
//

#ifndef CPPCOURSE_WALLSLIST_H
#define CPPCOURSE_WALLSLIST_H

#include "Wall.h"
#include "iostream"

using namespace std;

class WallsList {
public:

    /**
     * Create an empty list of integers
     */
    WallsList();

    /* big three */
    WallsList(const WallsList &other);

    WallsList &operator=(const WallsList &rhs);

    ~WallsList();

    /**
     * insert an element to the head of the list
     * @param elem
     */
    void insert(const Wall &elem);

    /**
     * remove the first occurrence of elem in the list
     * @param elem
     */
    void remove(const Wall &elem);

    /**
     * remove all elements from the list
     */
    void clear();

    /**
     * return how many elements are in the list
     */
    int size() const;

    /**
     * access an element at a given index
     * @param index
     * @return
     */
    Wall &operator[](int index);


    /**
     * return an element at a given index
     * @param index
     * @return
     */
    const Wall &operator[](int index) const;

//    friend ostream &operator<<(ostream &out, const WallsList &list);

private:
    struct Node {
        Wall data;
        Node *next;

        Node(const Wall &data, Node *next);
    };

    Node *head;
    int count;
};

//ostream &operator<<(ostream &out, const WallsList &list);

#endif //CPPCOURSE_WALLSLIST_H
