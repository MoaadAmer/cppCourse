//
// Created by moaad on 5/15/2021.
//

#include "WallsList.h"
#include <cstdlib>

WallsList::WallsList() : head(NULL), count(0) {}

void WallsList::insert(Wall *elem) {
    head = new Node(elem, head);
    count++;
}

void WallsList::clear() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    count = 0;
    head = NULL;
}

WallsList::WallsList(const WallsList &other) : head(NULL), count(0) {
    Node *temp = other.head;
    while (temp) {
        insert(temp->data);
        temp = temp->next;
    }
}

WallsList &WallsList::operator=(const WallsList &rhs) {
    if (this != &rhs) {
        clear();
        Node *temp = rhs.head;
        while (temp) {
            insert(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

WallsList::~WallsList() {
    clear();
}

Wall &WallsList::operator[](int index) {
    if (index < 0 || index >= count) {
        cerr << "whoa there buddy!" << endl;
        exit(1);
    }
    Node *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return *(temp->data);
}

const Wall &WallsList::operator[](int index) const {
    if (index < 0 || index >= count) {
        cerr << "whoa there buddy" << endl;
        exit(1);
    }
    Node *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return *(temp->data);
}

int WallsList::size() const {
    return count;
}

WallsList::Node::Node(Wall *data, Node *next) : data(data), next(next) {}