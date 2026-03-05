#include <iostream>
#include <vector>
#include"Person.h"
#include"Admin.h"
#include<string>
#include <sstream>
#include <fstream>
using namespace std;
int main()
{
    const string filename = "Admin.txt";
    Admin a;
    Admin a(1000, "malak khaled", "malak123", 5000);
    fstream file;
    file.open(filename, ios::app);
    file << a.getId() << " | " << a.getName() << " | " << a.getPassword() << " | " << a.getSalary() << endl;
    file.close();

    vector<Admin> VecAdmin;

    string line;
    string part;
    fstream file;

    file.open(filename, ios::in);
    getline(file, line);

    stringstream ss(line);

    vector<string> parts;

    while (getline(ss, part, '|')) {
        parts.push_back(part);
    }

    a.setId(stoi(parts[0]));
    a.setName(parts[1]);
    a.setPassword(parts[2]);
    a.setSalary(stod(parts[3]));

    a.display();
}