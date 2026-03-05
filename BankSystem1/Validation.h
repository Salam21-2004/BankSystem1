#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#include "Validation.h"
class Validation {

public:
    static bool set_name(string name) {
        if (name.length() < 3 || name.length() > 20) {
            cout << "invalid name length \n";
            return false;
        }
        for (char n : name) {
            if (!isalpha((unsigned char)n)) {
                cout << "name must contain letters only\n";
                return false;
            }
        }
        return true;
    }
    static bool set_password(string password) {
        if (password.size() < 8 || password.size() > 20) {
            cout << "invalid password size \n";
            return false;
        }
        for (char p : password) {
            if (isspace((unsigned char)p)) {
                cout << "password must not contain spaces\n";
                return false;
            }
        }
        return true;
    }
    static bool set_balance(double balance) {
        if (balance < 1500) {
            cout << "balance must be >= 1500\n";
            return false;
        }
        return true;
    }
    static bool set_salary(double salary) {
        if (salary < 5000) {
            cout << "salary must be >= 5000\n";
            return false;
        }
        return true;
    }

};
