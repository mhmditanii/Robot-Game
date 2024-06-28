//
// Created by mhmd on 6/28/24.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include<optional>
#include<limits>
using namespace std;

class filehandler {
public:
    int Mrow;
    int Ncol;
    int steps;
    int robotsNumber;
    vector<string> typeNames;
    vector<string> names;
    vector<optional<pair<size_t, size_t>>> locations;

    filehandler(const std::string& filename);
    void printDetails() const;
};


#endif //FILEHANDLER_H
