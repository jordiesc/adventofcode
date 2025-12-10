#include <iostream>
#include <ostream>
#include <vector>
#include <string>

#include "util.h"

using namespace std;

int lineparser( string line, int rotation );
int read_input( string filename,int initial);

int main() {
    string FILE = "src/input.txt";
    int numberOfZeros = 0;
    int INITIAL = 50;
    cout << "Hello, World!" << endl;
    numberOfZeros += read_input(FILE, INITIAL);
    cout << "Number of Zeros: " << numberOfZeros << endl;
    return 0;
}


int lineparser( string line, int initial, DivisioSenzera &division ) {

    string direction = "L";
    string indicator = line.substr(0, 1);
    int distance = stoi(line.substr(1, line.size()));
    if (indicator == "R") {
        initial += distance;
    
    } else if (indicator == "L") {
        initial -= distance;
    } 
    division.quocient = initial / 100;
    division.rest = initial % 100;
    return  division.rest;
}

int read_input( string filename, int initial) {
    vector<string> vlines;
    int  rotation = initial; 
    int numberOfZeros = 0;
    readFile(filename, vlines);

    DivisioSenzera division ;

    for (string line : vlines) {
        cout << line << endl;
        rotation = lineparser(line, rotation, division);

        cout << "Rotation: " << rotation << " Quocient: " << division.quocient << " Rest: " << division.rest << endl;

        if ( division.rest == 0 ) {
            numberOfZeros ++;
        }

    }   
    return numberOfZeros;
}
