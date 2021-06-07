#include <iostream>
#include "fileReader.h"

using namespace std;

void FileReader::openFile(string fileName) {
    inFile.open("input.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        exit(1);
    }
}

vector<int> FileReader::readAsInts() {
    vector<int> entries;
    string inputString;
    while(std::getline(inFile, inputString)) {
        entries.push_back(std::stoi(inputString));
    }
    return entries;
}