//
// Created by moaad on 5/6/2021.
//

#ifndef CPPCOURSE_DISCSLIST_H
#define CPPCOURSE_DISCSLIST_H

#include <iostream>
#include "Disc.h"

using namespace std;

class DiscsList {
public:

    /**
     * Create an empty list of integers
     */
    DiscsList();

    /* big three */
    DiscsList(const DiscsList &other);

    DiscsList &operator=(const DiscsList &rhs);

    ~DiscsList();

    /**
     * insert an element to the head of the list
     * @param elem
     */
    void insert(const Disc &elem);

    /**
     * remove the first occurrence of elem in the list
     * @param elem
     */
    void remove(const Disc &elem);

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
    Disc &operator[](int index);


    /**
     * return an element at a given index
     * @param index
     * @return
     */
    const Disc &operator[](int index) const;

    friend ostream &operator<<(ostream &out, const DiscsList &list);

private:
    struct Node {
        Disc data;
        Node *next;

        Node(const Disc &data, Node *next);
    };

    Node *head;
    int count;
};

ostream &operator<<(ostream &out, const DiscsList &list);

#endif //CPPCOURSE_DISCSLIST_H
