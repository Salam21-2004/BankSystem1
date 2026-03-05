#pragma once
#include "Person.h"
class Employee :public Person
{
protected:

    double salary;
public:
    Employee() :Person() {

        salary = 5000;
    }
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {

        setSalary(salary);
    }



    void setSalary(double salary) {
        if (Validation::set_salary(salary)) {
            this->salary = salary;
        }
    }



    double getSalary() const{
        return salary;
    }
    void display() const override{
        Person::display();

        cout << "Salary: " << salary << endl;
    }


};
