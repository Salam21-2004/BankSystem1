#pragma once
#include <iostream>
using namespace std;
#include "Validation.h"
class validation {

public:
    static bool set_name(string name) {
        if (name.length() < 3 || name.length() > 20) {
            cout << "invalid name length \n";
            return false;
        }
        for (auto n : name) {
            if (!isalpha(n)) {
                cout << "name must contian letters";
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
        for (auto p : password) {
            if (isspace(p)) {
                cout << "password mustnot contain space";
                return false;
            }
        }
        return true;
    }
    static bool set_balance(double balance) {
        if (balance < 1500) {
            cout << "balance must be greater 1500";
            return false;
        }
        return true;
    }
    static bool set_salary(double salary) {
        if (salary < 5000) {
            cout << "salary must be greater 5000";
            return false;
        }
        return true;
    }

};
