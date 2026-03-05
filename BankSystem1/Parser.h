#pragma once
#include<vector>
#include"Admin.h"
#include"Employee.h"
#include<sstream>
#include<string>

class Parser
{
	static vector<string>split(string line) {


		vector<string> parts;

		//1000|AhmedWeal|ahmed123|6000
		stringstream ss(line);
		string part;
		while (getline(ss, part, '|')) {
			parts.push_back(part);
		}
		//[0]   [1]    [2]     [3]
		//id    name   passw   balance
		return parts;
	}
public:
	
	static Client parseToClient(string line) {
		vector<string> parts = split(line);
		Clinet c;
		c.setId(stoi(parts[0]));
		c.setName((parts[1]));
		c.setPass((parts[2]));
		c.setBalance(stod(parts[3]));
		return c;

	}
	static Employee parseToEmployee(string line) {
		vector<string> parts = split(line);
		Employee e;
		e.setId(stoi(parts[0]));
		e.setName((parts[1]));
		e.setPass((parts[2]));
		e.setSlary(stod(parts[3]));
		return e;

	}
	static Admin parseToAdmin(string line) {
		vector<string> parts = split(line);
		Admin a;
		a.setId(stoi(parts[0]));
		a.setName((parts[1]));
		a.setPass((parts[2]));
		a.setSlary(stod(parts[3]));
		return a;

	}
}; 

  