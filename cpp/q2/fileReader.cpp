#ifndef FILE_READER
#define FILE_READER

#include <iostream>
#include <sstream>
#include <tuple>
#include "fileReader.h"
#include "policy.h"

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
    while(getline(inFile, inputString)) {
        entries.push_back(stoi(inputString));
    }
    return entries;
}

vector<tuple<Policy, string>> FileReader::readAsPoliciesAndPasswords() {
    vector<tuple<Policy, string>> entries;
    string inputString;
    while(getline(inFile, inputString)) {
        vector<string> parts = split(inputString, ' ');
        tuple<int, int> range = convertRange(parts[0]);
        Policy policy = Policy(get<0>(range), get<1>(range), parts[1].at(0));
        entries.push_back(make_tuple(policy, parts[2]));
    }
    return entries;
}

tuple<int, int> FileReader::convertRange(string rangeText) {
    vector<string> ranges = split(rangeText, '-');
    return make_tuple(stoi(ranges[0]), stoi(ranges[1]));
}

vector<string> FileReader::split(const string &s, char delim) {
    vector<string> result;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

#endif