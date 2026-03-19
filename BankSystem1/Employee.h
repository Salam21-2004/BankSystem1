#pragma once
#include "Person.h"
#include "Client.h"
#include <vector>

static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;

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
    void display() {
        Person::display();

        cout << "Salary: " << salary << endl;
    }
    void addClient(Client& client) {
        allClient.push_back(client);
    }

    Client* searchClient(int id) {

        for (cIt = allClient.begin(); cIt != allClient.end(); cIt++) {
            if (cIt->getId() == id) {
                return &(*cIt);
            }
            return nullptr;
        }
    }

    void listClient() {

        for (cIt = allClient.begin(); cIt != allClient.end(); cIt++) {
            cIt->display();
        }


    }

    void editClient(Client* c, string name, string password, double balance) {
        c->setName(name);
        c->setPass(password);
        c->setBalance(balance);


    }


};


