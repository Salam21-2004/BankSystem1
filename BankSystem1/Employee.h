#pragma once
#include "Person.h"
#include "Client.h"
#include <vector>
static vector<Client> allClients;
static vector<Client>::iterator cIt;

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
        allClients.push_back(client);
    }

    Client* searchClient(int id) {

        for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
            if (cIt->getId() == id) {
                return &(*cIt);
            }
        }
        return nullptr;

    }

    void listClient() {

        for (cIt = allClients.begin(); cIt != allClients.end(); cIt++) {
            cIt->display();
        }


    }

    void editClient(int id, string name, string password, double balance) {

        Client* c = searchClient(id);

        if (c != nullptr) {
            c->setName(name);
            c->setPass(password);
            c->setBalance(balance);
        }
    }


};


