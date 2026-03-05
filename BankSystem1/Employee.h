#pragma once
#include "Person.h"
class Employee :public Person
{
protected:

    double salary;
public:
    Employee() :Person() {

        salary = 0;
    }
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {

        this->salary = salary;
    }



    void setSalary(double salary) {
        if (Validation::set_salary(salary)) {
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
