#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include "policy.h"

using namespace std;

class FileReader {
    public:
        void openFile(string fileName);
        vector<int> readAsInts();
        vector<tuple<Policy, string>> readAsPoliciesAndPasswords();

    private:
        ifstream inFile;
        tuple<int, int> convertRange(string rangeText);
        vector<string> split(const string &s, char delim);
};

#endif