#pragma once
#include "Person.h"
class Employee : Person
{
protected:

    double salary;
public:
    Employee() :Person() {

        salary = 0;
    }
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {

        setsalary(salary);
    }



    void setSalary(double salary) {
        if (Validation::isValidSalary(salary)) {
            this->salary = salary;
        }
    }



    double getSalary() {
        return salary;
    }
    void display() {
        Person::display();

        cout << "Salary: " << salary << endl;
    }


};
