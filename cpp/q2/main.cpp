#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fileReader.h"
#include "policy.h"

using namespace std;

int main() {
    FileReader fr;
    fr.openFile("input.txt");
    vector<tuple<Policy, string>> entries = fr.readAsPoliciesAndPasswords();
    int counter = 0;
    for (int i = 0; i < entries.size(); i++) {
        Policy policy = get<0>(entries[i]);
        if (policy.CheckPassword(get<1>(entries[i]))) {
            counter++;
        }
    }
    printf("%d\n", counter);
}



