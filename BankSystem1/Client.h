#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"

using namespace std;

class Client : public Person {
protected:
    double balance;

public:
    Client() : Person() {
        balance = 1500;
    }

    Client(int id, string name, string password, double balance)
        : Person(id, name, password) {
        this->balance = 1500;   // ãåã: ÞíãÉ ÇÝÊÑÇÖíÉ ÂãäÉ
        setBalance(balance);    // ÈÚÏåÇ äÍÇæá äØÈÞ validation
    }

    void setBalance(double balance) {
        if (Validation::set_balance(balance)) {
            this->balance = balance;
        }
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "invalid deposit amount\n";
            return;
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "invalid withdraw amount\n";
            return;
        }
        if (balance - amount < 1500) {
            cout << "Cannot withdraw, minimum balance is 1500\n";
            return;
        }
        balance -= amount;
    }

    void transferTo(double amount, Client& recipient) {
        if (amount <= 0) {
            cout << "invalid transfer amount\n";
            return;
        }
        if (balance - amount < 1500) {
            cout << "Cannot transfer, minimum balance is 1500\n";
            return;
        }
       
        balance -= amount;
        recipient.balance += amount;
    }

    void checkBalance() const {
        cout << "Balance = " << balance << endl;
    }

    void display() const override {
        Person::display();
        cout << "Balance = " << balance << endl;
    }
};