//
// Created by moaad on 5/6/2021.
//

#include "DiscsList.h"
#include <cstdlib>
#include <iomanip>

DiscsList::DiscsList() : head(NULL), count(0) {}

void DiscsList::insert(const Disc &elem) {
    head = new Node(elem, head);
    count++;
}

void DiscsList::clear() {
    while (head) {
        Node *temp = head;
        head = head->next;
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
    return temp->data;
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
    return temp->data;
}

ostream &operator<<(ostream &out, const DiscsList &DiscsList) {
    DiscsList::Node *temp = DiscsList.head;
    while (temp) {
        if (temp != DiscsList.head) {
            out << " ";
        }
        cout << temp->data;
        temp = temp->next;
    }
    return out;
}

void DiscsList::remove(const Disc &elem) {
    if (!head) { return; }
    Node *temp = head;
    if (temp->data == elem) {
        head = head->next;
        delete temp;
        count--;
        return;
    }
    while (temp->next && temp->next->data != elem) {
        temp = temp->next;
    }
    if (temp->next) {
        Node *victim = temp->next;
        temp->next = victim->next;
        delete victim;
        count--;
    }
}

int DiscsList::size() const {
    return count;
}

DiscsList::Node::Node(const Disc &data, Node *next) : data(data), next(next) {}
