#include <iostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int lineparser( string line, int rotation );
int read_input( string filename);

int main() {
    int rotation = 0;
    cout << "Hello, World!" << endl;
    rotation = read_input("input.txt");
    cout << "Rotation: " << rotation << endl;
    return 0;
}


int lineparser( string line, int rotation ) {

    string direction = "L";
    string indicator = line.substr(0, 1);
    int distance = stoi(line.substr(1, line.size()));

    if (indicator == "R") {
        rotation += distance;
    } else if (indicator == "L") {
        rotation -= distance;
    } 

    return rotation;
}

int read_input( string filename) {
    vector<string> vlines;
    int  rotation = 0; 
    readFile(filename, vlines);

    for (string line : vlines) {
        rotation = lineparser(line, rotation);
    }   
    return rotation;
}
