#pragma once
#include "Employee.h"
class Admin : public Employee
{
	public:
	Admin():Employee()
	{
		
	}
	Admin(int id , string name, string password, double salary):Employee(id, name, password , salary)
	{
	
	}
	void addEmployee(Employee& employee)
	{
		allEmployees.push_back(employee);
	}
	Employee* searchEmployee(int id)
	{
		for (int i = 0; i < allEmployees.size(); i++)
		{
			if (allEmployees[i].getId() == id)
			{
				return &allEmployees[i];
			}
		}
		return nullptr;
	}
	void editEmployee(Employee* e , string name, string password, double salary)
	{
			e->setName(name);
			e->setPass(password);
			e->setSalary(salary);
	}
	void listEmployees()
	{
		for (int i = 0; i < allEmployees.size(); i++)
		{
			allEmployees[i].display();
		}
	}
};

