#include "filehandler.h"

filehandler::filehandler(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }

    string line;

    // Read dimensions (not used in class, but can be stored if needed)
    getline(file, line);
    istringstream dimStream(line);
    string temp;
    dimStream.ignore(numeric_limits<streamsize>::max(), ':'); // Skip until ':'
    dimStream >> Mrow >> Ncol;

    if (dimStream.fail()) {
        throw runtime_error("Failed to read dimensions");
    }

    // Read steps
    getline(file, line);
    istringstream stepsStream(line);
    stepsStream >> temp >> steps;

    // Read number of robots
    getline(file, line);
    istringstream robotsNumberStream(line);
    robotsNumberStream >> temp >> robotsNumber;

    // Initialize the vectors
    typeNames.resize(robotsNumber);
    names.resize(robotsNumber);
    locations.resize(robotsNumber);

    // Read each robot's details
    for (int i = 0; i < robotsNumber; ++i) {
        getline(file, line);
        istringstream robotStream(line);
        string typeName, name;
        string xStr, yStr;
        size_t x, y;
        robotStream >> typeName >> name >> xStr >> yStr;

        typeNames[i] = typeName;
        names[i] = name;

        if (xStr == "random" || yStr == "random") {
            locations[i] = nullopt;
        } else {
            x = stoi(xStr);
            y = stoi(yStr);
            locations[i] = make_pair(x, y);
        }
    }

    file.close();
}

void filehandler::printDetails() const {
    cout << "Steps: " << steps << "\n";
    cout << "Number of Robots: " << robotsNumber << "\n";
    for (int i = 0; i < robotsNumber; ++i) {
        cout << "Type Name: " << typeNames[i] << " ";
        cout << "Name: " << names[i] << " ";
        if (locations[i]) {
            cout << "Location: (" << locations[i]->first << ", " << locations[i]->second << ")";
        } else {
            cout << "Location: random";
        }
        cout << "\n";
    }
}