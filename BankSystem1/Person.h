#pragma once
#include <iostream>
#include <string>
#include"Validation.h"
class Person
{
	protected:
		int id;
		string name;
		string password;
	public:

		Person() {
			this->id = 0;
			this->name = "Unknown";
			this->password = "00000000";
		}

		Person(int id, string name, string password) {
			this->id = id;

			// ÇÓÊÎÏã setters ÚÔÇä validation
			setName(name);
			setPass(password);
		}
		
		void setId(int id) {

			this->id = id;
		}
		void setName(string name) {
			if (Validation::set_name (name)) {
				this->name = name;
			}
		}
		void setPass(string password) {
			if (Validation::set_password(password)) {
				this->password = password;
			}
		}
		
		int getId() const{
			return this->id;

		}
		string getName() const{
			return this->name;
		}
		string getPassword() const{

			return this->password;
		}
		
		virtual void display() const{
			cout << "name=" << name << endl;
			cout << "id=" << id << endl;
		}

	};


