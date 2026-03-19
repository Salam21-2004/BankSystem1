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
		FilesHelper::getClients();
	}
	void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	void removeAllClients() {
		FilesHelper::clearFile(C_File_Path, C_last_Id_Path, 0);
	}
	void removeAllEmployees() {
		FilesHelper::clearFile(E_File_Path, E_last_Id_Path, 100);

	}
	void removeAllAdmins() {
		FilesHelper::clearFile(C_File_Path, C_last_Id_Path, 1000);
	}
};
