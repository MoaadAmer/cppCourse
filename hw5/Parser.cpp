//
// Created by moaad on 6/26/2021.
//

#include "Parser.h"
#include <fstream>

int Parser::start() {

    string line;
    while (getline(cin, line)) {

        stringstream s(line);
        string cmd;
        if (!(s >> cmd)) continue;
        string cName;
        if (cmd == "string_counter") {
            s >> cName;
            if (s.fail()) {
                cerr << "Error: Missing counter name" << endl;
                return -1;
            }
            if (addCounter(cName, STRING) == -1)return -1;
        } else if (cmd == "int_counter") {
            s >> cName;
            if (s.fail()) {
                cerr << "Error: Missing counter name" << endl;
                return -1;
            }
            if (addCounter(cName, INTEGER) == -1) return -1;
        } else if (cmd == "add_from_file") {
            s >> cName;
            if (s.fail()) {
                cerr << "Error: Missing counter name" << endl;
                return -1;
            }
            string fileName;
            s >> fileName;
            if (s.fail()) {
                cerr << "Error: Missing file name" << endl;
                return -1;
            }

            if (addFromFile(cName, fileName) == -1)return -1;
        } else if (cmd == "add_from_string") {
            s >> cName;
            if (s.fail()) {
                cerr << "Error: Missing counter name" << endl;
                return -1;
            }
            if (addFromString(cName, s) == -1)return -1;

        } else if (cmd == "stats") {
            s >> cName;
            if (s.fail()) {
                cerr << "Error: Missing counter name" << endl;
                return -1;
            }
            if (stats(cName) == -1)return -1;

        } else if (cmd == "most_common") {

            s >> cName;
            if (s.fail()) {
                cerr << "Error: Missing counter name" << endl;
                return -1;
            }
            if (mostCommon(cName) == -1)return -1;
        } else {

            cerr << "Error: Unknown command " << cmd << endl;
        }

    }
    return 0;
}

int Parser::addCounter(const string &counterName, Type type) {
    if (doesExists(counterName) != NONE) {
        cerr << "Error: Counter name already exists" << endl;
        return -1;
    }
    if (type == STRING) {
        Counter<string> c;
        mapOfStrings[counterName] = c;

    } else {
        Counter<int> c;
        mapOfInts[counterName] = c;
    }
    return 0;
}

int Parser::addFromFile(const string &counterName, const string &fileName) {

    Type t = doesExists(counterName);

    if (t == STRING) {

        const char *file = fileName.c_str();
        ifstream ifs(file, ios::in);
        if (!ifs) {
            cerr << "Error: Failed to open file" << endl;
            return -1;
        }
        if (mapOfStrings[counterName].add_from_stream(ifs) == -1) {
            cerr << "Error: Read failed" << endl;
            return -1;
        }
        ifs.close();
    } else if (t == INTEGER) {
        const char *file = fileName.c_str();
        ifstream ifs(file, ifstream::in);
        if (!ifs) {
            cerr << "Error: Failed to open file" << endl;
            return -1;
        }
        if (mapOfInts[counterName].add_from_stream(ifs) == -1) {
            cerr << "Error: Read failed" << endl;
            return -1;
        }
        ifs.close();

    } else {
        cerr << "Error: No counter named " << counterName << endl;
        return -1;
    }

    return 0;

}

int Parser::addFromString(const string &counterName, istream &stream) {

    Type t = doesExists(counterName);

    if (t == STRING) {
        if (mapOfStrings[counterName].add_from_stream(stream) == -1) {
            cerr << "Error: Read failed" << endl;
            return -1;
        }

    } else if (t == INTEGER) {
        if (mapOfInts[counterName].add_from_stream(stream) == -1) {
            cerr << "Error: Read failed" << endl;
            return -1;
        }
    } else {
        cerr << "Error: No counter named " << counterName << endl;
        return -1;
    }

    return 0;

}

Parser::Type Parser::doesExists(const string &counterName) const {
    try {
        mapOfStrings.at(counterName);
    } catch (exception &e) {
        try {
            mapOfInts.at(counterName);
        }
        catch (exception &e) {

            return NONE;
        }
        return INTEGER;
    }
    return STRING;

}

int Parser::stats(const string &counterName) const {

    Type t = doesExists(counterName);

    if (t == STRING) {
        Counter<string> c = mapOfStrings.at(counterName);
        c.print_to_stream(counterName, cout);
    } else if (t == INTEGER) {
        Counter<int> c = mapOfInts.at(counterName);
        c.print_to_stream(counterName, cout);

    } else {
        cerr << "Error: No counter named " << counterName << endl;
        return -1;
    }
    return 0;
}

int Parser::mostCommon(const string &counterName) {

    Type t = doesExists(counterName);
    if (t == STRING) {
        Counter<string> c = mapOfStrings.at(counterName);
        if (c.size() == 0) {
            cerr << "Error: Counter is empty" << endl;
            return -1;

        }
        c.print_most_common(cout, counterName);
    } else if (t == INTEGER) {
        Counter<int> c = mapOfInts.at(counterName);
        if (c.size() == 0) {
            cerr << "Error: Counter is empty" << endl;
            return -1;
        }
        c.print_most_common(cout, counterName);

    } else {
        cerr << "Error: No counter named " << counterName << endl;
        return -1;
    }

    return 0;

}




