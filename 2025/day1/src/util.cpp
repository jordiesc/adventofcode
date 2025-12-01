#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void readFile(string filename, vector<string>& lines) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
       lines.push_back(line);
        cout << line << endl;
    }

}
