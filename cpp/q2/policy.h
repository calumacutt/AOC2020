#ifndef POLICY_H
#define POLICY_H

#include <string>

using namespace std;

class Policy {
    int min;
    int max;
    char letter;

    public:
        Policy(int initMin, int initMax, char initLetter);
        bool CheckPassword(string password);
};

#endif