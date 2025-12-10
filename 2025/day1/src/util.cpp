#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void readFile(string filename, vector<string>& lines) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
       lines.push_back(line);
        
    }

}
