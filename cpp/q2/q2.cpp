#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        exit(1);
    }

    vector<string> entries;
    string inputString;
    while(std::getline(inFile, inputString)) {
        entries.push_back(std::stoi(inputString));
    }

    for (int i = 0; i < entries.size(); i++) {
        vector<string> parts;
        split(entries[i], ' ', parts);
        cout << parts[0] << endl;
    }
}



void split(const std::string &s, char delim, std::vector<std::string> result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        result.push_back(item);
    }
}