//
// Created by moaad on 6/26/2021.
//

#ifndef CPPCOURSE_PARSER_H
#define CPPCOURSE_PARSER_H

#include "Counter.h"

class Parser {


public:
    enum Type {
        STRING, INTEGER, NONE
    };

    int start();

    int addCounter(const string &counterName, Type type);


private:
    map<string, Counter<string> > mapOfStrings;
    map<string, Counter<int> > mapOfInts;


    int addFromFile(const string &counterName, const string &fileName);

    Type doesExists(const string &counterName) const;

    int addFromString(const string &counterName, istream &istream);

    int stats(const string &counterName) const;

    int mostCommon(const string &counterName);
};


#endif //CPPCOURSE_PARSER_H
