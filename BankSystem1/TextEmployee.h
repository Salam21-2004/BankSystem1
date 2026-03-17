#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include "Employee.h"
class TextEmployee {
    public:


        static void saveEmployee(Employee e) {

            fstream file("Employees.txt", ios::app);

            file << e.getId() << ","
                << e.getName() << ","
                << e.getPassword() << ","
                << e.getSalary() << endl;

            file.close();
        }


        static vector<Employee> getEmployees() {

            vector<Employee> employees;
            ifstream file("Employees.txt");
            string line;

            while (getline(file, line)) {

                stringstream ss(line);

                string id, name, password, salary;

                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, password, ',');
                getline(ss, salary, ',');

                Employee e(
                    stoi(id),
                    name,
                    password,
                    stod(salary)
                );

                employees.push_back(e);
            }

            file.close();
            return employees;
        }

    };


