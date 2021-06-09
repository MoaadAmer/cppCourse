//
// Created by moaad on 5/15/2021.
//

#include "WallsList.h"
#include <cstdlib>

WallsList::WallsList() : head(NULL), count(0) {}

void WallsList::insert(const Wall &elem) {
    head = new Node(elem, head);
    count++;
}

void WallsList::clear() {
    while (head) {
        Node *temp = head;
        head = head->next;
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
    return temp->data;
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
    return temp->data;
}

/*ostream &operator<<(ostream &out, const WallsList &list) {
    WallsList::Node *temp = list.head;
    while (temp) {
        if (temp != list.head) {
            out << ",";
        }
        out << temp->data;
        temp = temp->next;
    }
    return out;
}*/

void WallsList::remove(const Wall &elem) {
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

int WallsList::size() const {
    return count;
}

WallsList::Node::Node(const Wall &data, Node *next) : data(data), next(next) {}