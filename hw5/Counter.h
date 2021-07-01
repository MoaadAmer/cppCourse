//
// Created by moaad on 6/25/2021.
//

#ifndef CPPCOURSE_COUNTER_H
#define CPPCOURSE_COUNTER_H

#include "iostream"
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>      // std::stringstream

using namespace std;


template<class T>
class Counter {

public:

    map<T, int> data;

    void clear() { data.clear(); }

    void add(T elem) {
        data[elem] = data[elem] + 1;
    }

    int operator[](T elem) const {
        int res;
        try {
            res = data.at(elem);
        }
        catch (exception &e) {

            return 0;
        }
        return res;
    }

    T most_common() {


        if (data.size() == 0)
            throw "The counter is empty";

        T val = data.begin()->first;

        for (typename map<T, int>::iterator it = data.begin(); it != data.end(); ++it) {
            if (data[val] < it->second)
                val = it->first;
        }

        for (typename map<T, int>::iterator it = data.begin(); it != data.end(); ++it) {
            if (data[val] == it->second)
                if (val > it->first)
                    val = it->first;
        }

        return val;
    }


    int add_from_stream(istream &stream) {

        T t;
        while (stream >> t) {
            if (stream.fail()) {
                return -1;
            } else
                add(t);
        }
        if (!stream.eof())
            return -1;
        return 0;
    }

    void print_to_stream(const string &cName, ostream &stream) {

        stringstream s;

        s << "counter " << cName << " = " << "{ ";
        for (typename map<T, int>::iterator it = data.begin(); it != data.end(); ++it) {
            s << it->first << ":" << it->second << " ";
        }
        s << "}" << endl;
        stream << s.str();

    }


    void print_most_common(ostream &stream, const string &cName) {
        T key = most_common();
        stream << "most common element for counter " << cName << " is " << key << ":" << data[key] << endl;
    }

    int size() { return data.size(); }
};


#endif //CPPCOURSE_COUNTER_H
