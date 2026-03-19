#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface
{
public:

    void addClient(Client obj) {
        FilesHelper::saveClient(obj);
    }

    void addEmployee(Employee obj) {
        FilesHelper::saveEmployee(obj);
    }

    void addAdmin(Admin obj) {
        FilesHelper::saveAdmin(obj);
    }

    void getAllClients() {
        vector<Client> clients = FilesHelper::getClients();

        for (int i = 0; i < clients.size(); i++) {
            clients[i].display();
        }
    }

    void getAllEmployees() {
        vector<Employee> employees = FilesHelper::getEmployees();

        for (int i = 0; i < employees.size(); i++) {
            employees[i].display();
        }
    }

    void getAllAdmins() {
        vector<Admin> admins = FilesHelper::getAdmins();

        for (int i = 0; i < admins.size(); i++) {
            admins[i].display();
        }
    }

    void removeAllClients() {
        FilesHelper::clearFile("Clients.txt");
    }

    void removeAllEmployees() {
        FilesHelper::clearFile("Employees.txt");
    }

    void removeAllAdmins() {
        FilesHelper::clearFile("Admins.txt");
    }
};