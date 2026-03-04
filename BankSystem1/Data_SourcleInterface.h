#pragma once
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include<vector>
class Data_SourcleInterface
{
public:
	
	virtual void Addclint(client& obj) = 0;
	virtual void AddEmployee(Employee& obj) = 0;
	virtual void AddAdmin(Admin& obj) = 0;

	virtual vector<client>getAllclients() = 0;
	virtual vector<Employee>getAllEmployee() = 0;
	virtual vector<Admin>getAllAdmin() = 0;
	
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;

	virtual ~Data_SourcleInterface() {};




};

