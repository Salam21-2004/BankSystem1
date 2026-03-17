#pragma once
#include"EmployeeManger.h"
class AdminManger
{
private:
	static void printAdminMenu() {
		system("cls");
		cout << "1- Display my info" << endl;
		cout << "2- Update Password" << endl;
		cout << "3- Add new client" << endl;
		cout << "4- Search new client" << endl;
		cout << "5- list all clients" << endl;
		cout << "6- Edit client info" << endl;
		cout << "7- Add new employee" << endl;
		cout << "8- Search for employee" << endl;
		cout << "9- list all employees" << endl;
		cout << "10- Edit employee info" << endl;
		cout << "11- Logout \n" << endl;
	}
	static void back_exit(Admin* admin) {
		int option;
		cout << "1- Back to menu" << endl;
		cout << "2- Exit" << endl;
		cout << "Enter your option: ";
		cin >> option;
		switch (option) {
		case 1:
			exit(0);
			break;
		case 2:
			system("cls");
			adminOptions(admin);
		default:
			system("cls");
			cout << "Invalid option, try again." << endl;
			back_exit(admin);
		}
	}
public:
	static Admin* login( int id , string password) {
		for (int i = 0; i < EmployeeManger::getAdmins().size(); i++) {
			if (EmployeeManger::getAdmins()[i]->getId() == id && EmployeeManger::getAdmins()[i]->getPassword() == password) {
				return EmployeeManger::getAdmins()[i];
			}
		}
		return nullptr;
	}
	static void newEmployee(Admin* admin) {
		Employee emp;
		int id = FilesHelper::getLastId(EID_FILE_PATH) + 1;
		emp.setId(id);
		emp.setName(Validation::enterName("Enter employee name: "));
		emp.setPassword(Validation::enterPassword("Enter employee password: "));
		emp.setSalary(Validation::enterSalary("Enter employee salary: "));
		admin->addEmployee(emp);
		FileManger::addEmployee(emp);
		cout << "Employee added successfully " << endl;
	}
	static void searchForEmployee(Admin* admin) {
		int id = Validation::getIntegerNumber("Enter employee id: ");
		Employee* emp = admin->searchForEmployee(id);
		if (emp != nullptr) {
			emp->display();
		}
		else {
			cout << "Employee not found" << endl;
		}
	}
	static void listAllEmployees(Admin* admin) {
		cout << "All Employees: " << endl;
		admin->listEmployee();
	}
	static void editEmployeeInfo(Admin* admin) {
		int id = Validation::getIntegerNumber("Enter employee id: ");
		Employee* emp = admin->searchForEmployee(id);
		if (emp != nullptr) {
			emp->setName(Validation::enterName("Enter employee name: "));
			emp->setPassword(Validation::enterPassword("Enter employee password: "));
			emp->setSalary(Validation::enterSalary("Enter employee salary: "));
			FileManger::updateEmployee(*emp);
			cout << "Employee info updated successfully " << endl;
		}
		else {
			cout << "Employee not found" << endl;
		}
	}
	static bool adminOptions(Admin* admin) {
		printAdminMenu();
		int option;
		cout << "Enter your option: ";
		cin >> option;
		switch (option) {
		case 1:
			system("cls");
			admin->display();
			break;
		case 2:
			system("cls");
			ClintManger :: updatePassword(admin);
			FileManger::updateAdmis();
			break;
		case 3:
			system("cls");
			EmployeeManger::newClient(admin);
			break;
		case 4:
			system("cls");
			EmployeeManger::searchForClient(admin);
			break;
		case 5:
			system("cls");
			EmployeeManger::listAllClients(admin);
			break;
		case 6:
			system("cls");
			EmployeeManger::editClientInfo(admin);
			break;
		case 7:
			system("cls");
			newEmployee(admin);
			break;
		case 8:
			system("cls");
			searchForEmployee(admin);
			break;
		case 9:
			system("cls");
			listAllEmployees(admin);
			break;
		case 10:
			editEmployeeInfo(admin);
			break;
		case 11:
			return false;
		default:
			system("cls");
			cout << "Invalid option, try again." << endl;
		}
		system("pause");
		return true;
	}
};

