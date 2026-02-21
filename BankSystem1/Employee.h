#pragma once
#include "Person.h"
class Employee : Person
{
protected:

    double salary;
public:
    Employee() :person() {

        salary = 0;
    }
    Employee(int id, string name, string password, double salary) :person(id, name, password) {

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
        person::display();

        cout << "Salary: " << salary << endl;
    }


};
