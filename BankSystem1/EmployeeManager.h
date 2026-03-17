#pragma once
include "ClientManager.h"

class EmployeeManager
{
	static void printEmployeeMenu() {
		system("cls");
		cout << "(1)Display my info" << endl;
		cout << "(2)Update my password" << endl;
		cout << "(3)Add new client" << endl;
		cout << "(4)Search for client" << endl;
		cout << "(5)List all clients" << endl;
		cout << "(6)Edit client info" << endl;
		cout << "(7) logout" << endl;
		

	}
	
public:
	static void newClient(Employee* employee) {
		Client client;
		int id = FilesHelper::getLastId(CID_FILE_PATH) + 1;
		client.setId(id);
		client.setName(Validation::enterName("Client name : "));
		client.setPassword(Validation::enterPassword("Client password : "));
		client.setBalance(Validation::enterBalance("Client balance : "));
		employee->addClient(client);
		FileManager::updateClients(client);
		cout << "Client added successfully\n";
		
	}
	static void listAllClient(Employee* employee) {
		cout << "All Clients:\n";
		employee->listClient();
	}
	static void searchForClient(Employee* employee) {
		int id;
		id = Validation::getIntegerNumber("Enter client ID : ");
		
		
		Client* client = employee->searchClient(id);
		if (client==nullptr) cout << "Client not found\n";
			
		else 
		client->display();
			
		
	}
	static void editClientInfo(Employee* employee) {
		int id= Validation::getIntegerNumber("Enter client ID : ");
		Client* client = employee->searchClient(id);
		if (client != nullptr) {
			cout << "update date" << endl;
			string name = Validation::enterName("Client name : ");
			string password = Validation::enterPassword("Client password : ");
			dou balance = Validation::enterBalance("Client balance : ");

			employee->editClient(client, name, password, balance);
			FileManager::updateClients();
			cout << "Client information updated successfully\n";
		}
		else {
			cout << "Client not found\n";
			
			
		}
		
	}
	static Employee* login( int id,string password) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getId()==id &&eIt->getpassword()==passwors {
				return eIt._Ptr;
			}
		}
		return nullptr;
		
	}
	

	static bool employeeOptions(Employee* employee) {
		printEmployeeMenu();
		int choice;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch (choice) {
			case 1:
				system("cls");
				employee->display();
				break;
			case 2:
				system("cls");
				ClientManager::updatepassword(employee);
				FileManager::updateEmployees();
				break;
			case 3:
				system("cls");
				newClient(employee);
				break;
			case 4:
				system("cls");
				searchForClient(employee);
				break;
			case 5:
				system("cls");
				listAllClient(employee);
				break;
			case 6:
				system("cls");
				editClientInfo(employee);
				break;
			case 7:
				return false;
				break;
			defau:
				system("cls");
				employeeOptions(employee);
				return true;
		}
		back_exit(employee);
		return true;
	}
};

