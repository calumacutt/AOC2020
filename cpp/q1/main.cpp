#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include "fileReader.h"

using namespace std;

// Returns the index of the biggest number <= target
// Returns -1 if no numbers are <= target
int binarySearch(vector<int> entries, int target, int lower, int upper) {
    int check;
    if (entries[upper] < target) {
        return upper;
    }
    if (entries[lower] > target) {
        return -1;
    }
    while(lower + 1 < upper) {
        check = (lower + upper) / 2;
        if (entries[check] < target) {
            lower = check;
        } else if (entries[check] > target) {
            upper = check;
        } else {
            return check;
        }
    }
    return lower;
}

// Returns the product of the two numbers that sum to the input
// Returns -1 if there are no such numbers
int findComplements(vector<int> entries, int sum) {
    int target;
    int upper = entries.size() - 1;
    for (int i = 0; i < entries.size(); i++) {
        target = sum - entries[i];
        upper = binarySearch(entries, target, i + 1, upper);
        if (upper == -1) {
            return -1;
        } else if (entries[upper] == target) {
            return entries[i] * target;
        }
    }
    return -1;
}

int main() {
    FileReader fr;
    fr.openFile("input.txt");
    vector<int> entries = fr.readAsInts();

    sort(entries.begin(), entries.end());

    int result = findComplements(entries, 2020);

    printf("%d\n", result);

}
