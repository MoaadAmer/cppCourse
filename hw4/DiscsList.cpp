//
// Created by moaad on 5/6/2021.
//

#include "DiscsList.h"
#include <cstdlib>
#include <iomanip>
#include "Disc.h"

DiscsList::DiscsList() : head(NULL), count(0) {}

void DiscsList::insert(Disc *elem) {
    head = new Node(elem, head);
    count++;
}

void DiscsList::clear() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    count = 0;
    head = NULL;
}

DiscsList::DiscsList(const DiscsList &other) : head(NULL), count(0) {
    Node *temp = other.head;
    while (temp) {
        insert(temp->data);
        temp = temp->next;
    }
}

DiscsList &DiscsList::operator=(const DiscsList &rhs) {
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

DiscsList::~DiscsList() {
    clear();
}

Disc &DiscsList::operator[](int index) {
    if (index < 0 || index >= count) {
        cerr << "whoa there buddy!" << endl;
        exit(1);
    }
    Node *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return *temp->data;
}

const Disc &DiscsList::operator[](int index) const {
    if (index < 0 || index >= count) {
        cerr << "whoa there buddy" << endl;
        exit(1);
    }
    Node *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return *temp->data;
}

ostream &operator<<(ostream &out, const DiscsList &DiscsList) {

    DiscsList::Node *temp = DiscsList.head;
    while (temp) {
        if (temp != DiscsList.head) {
            out << " ";
        }
        Disc &d = *temp->data;
        cout << d;
        temp = temp->next;
    }
    return out;
}

int DiscsList::size() const {
    return count;
}

void DiscsList::printInReverseOrder() const {

    const DiscsList &discs = *this;

    for (int disNum = discs.size() - 1; disNum >= 0; disNum--) {
        cout << discs[disNum] << " ";
    }
}

DiscsList::Node::Node(Disc *data, Node *next) : data(data), next(next) {}
