#pragma once
#include <iostream>
#include <string>

using namespace std;

class Validation {
public:
    static bool isValidName(const string& name) {
        if (name.length() <= 3 || name.length() >= 20) return false;
        for (int i = 0; i < name.length(); i++) {
            if (!(name[i] >= 'A' && name[i] <= 'Z') && !(name[i] >= 'a' && name[i] <= 'z')) {
                return false;
            }
        }
        return true;
    }

    static bool isValidPassword( string& password) {
        return password.length() >= 8 && password.length() <= 20;
    }
};
