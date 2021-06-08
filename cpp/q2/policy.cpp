#ifndef POLICY
#define POLICY

#include <string>
#include "policy.h"

using namespace std;

Policy::Policy(int initMin, int initMax, char initLetter) {
    min = initMin;
    max = initMax;
    letter = initLetter;
}

bool Policy::CheckPassword(string password) {
    int counter = 0;
    for (int i = 0; i < password.size(); i++) {
        if (password[i] == letter) {
            counter++;
        }
    }
    return (min <= counter) && (max >= counter);
}

#endif