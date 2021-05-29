#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        cerr << "Unable to open file input.txt";
        exit(1);
    }

    vector<int> entries;
    string inputString;
    while(std::getline(inFile, inputString)) {
        entries.push_back(std::stoi(inputString));
    }

    int target = 2020;

    for (int i = 0; i < entries.size(); i++) {
        for (int j = i + 1; j < entries.size(); j++) {
            if (entries[i] + entries[j] == target) {
                cout << entries[i] << endl;
                cout << entries[j] << endl;
                cout << entries[i] * entries[j] << endl;
            }
        }
    }

    for (int i = 0; i < entries.size(); i++) {
        for (int j = i + 1; j < entries.size(); j++) {
            for (int k = j + 1; k < entries.size(); k++) {
                if (entries[i] + entries[j] + entries[k] == target) {
                    cout << entries[i] << endl;
                    cout << entries[j] << endl;
                    cout << entries[k] << endl;
                    cout << entries[i] * entries[j] * entries[k] << endl;
                }
            }
        }
    }
}