#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "fileReader.h"

using namespace std;

// Returns the index of the biggest number <= target
// Returns -1 if no numbers are <= target
int binarySearch(vector<int> entries, int target, int lower, int upper) {
    int check;
    if (entries[upper] <= target) {
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

// Returns the product of the two numbers that make up sum
// Returns -1 if there are no such numbers
int find2Complements(vector<int> entries, int sum, int lower, int upper) {
    int target;
    for (int i = lower; i < upper; i++) {
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

// Returns the highest possible entry that could be used, assuming all the other values used are the lowest available
// Returns -1 if there are no 
int findUpperBound(vector<int> entries, int sum, int count, int lower, int upper) {
    int lowestValues = 0;
    for (int i = lower; i < lower + count - 1; i++) {
        lowestValues += entries[i];
    }
    return binarySearch(entries, sum - lowestValues, lower + count, upper);
}

// Returns the product of the #count numbers that make up sum
// Returns -1 if there is no solution
int findNComplements(vector<int> entries, int sum, int count, int lower, int upper) {
    if (count == 2) {
        return find2Complements(entries, sum, lower, upper);
    }

    upper = findUpperBound(entries, sum, count, lower, upper);

    int result;
    for (int i = lower; i < upper - count + 2; i++) {
        result = findNComplements(entries, sum - entries[i], count - 1, i + 1, upper);
        if (result != -1) {
            return entries[i] * result;
        }
    }
    return -1;
}

int main() {
    FileReader fr;
    fr.openFile("input.txt");
    vector<int> entries = fr.readAsInts();

    sort(entries.begin(), entries.end());

    printf("%d\n", findNComplements(entries, 2020, 2, 0, entries.size() - 1));
    printf("%d\n", findNComplements(entries, 2020, 3, 0, entries.size() - 1));
}
