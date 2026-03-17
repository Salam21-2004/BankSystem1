#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"FileManager.h"
#include"ClintManager.h"
#include"Validation.h"
#include "EmployeeManager.h"
#include "AdminManager.h"



class Login_screen
    {
    static void loginOptions() {
       
        cout << "\n1. Login as  Admin \n";
        cout << "2. Login as Employee\n";
        cout << "3. Login as Client \n";
        
        //cout << "Choose option: ";
    }

    static int loginAs() {
        loginOptions();
        int choice = Validation::getIntegrNumber("login as:");
        if (choice == 1 || choice == 2 || choice == 3)  {
            system("cls");
            return choice;
        }
        else {
            system("cls");
            return loginAs();


        }
    }

    static void invalid(int c) {
        cout << "\nInvalid option: " << c << ". Please try again.\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }

    static void logout() {
        cout << "\nLogged out successfully!\n";
        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }

public:


    static void loginScreen(int c) {
        int choice = c, id;
        string pass;


        
        id = Validation::getIntegrNumber("Enter ID:");
        cout << "Enter Password: ";
        cin >> pass;
        switch (choice) {

        case1://admin
            if (AdminManger::login(id, pass) != nullptr)
            {
                while (AdminManger::adminOptions(AdminManger::login(id, pass)) != false);
                logout();
            }
            else invalid(1);
            break;
        case2://employee
            if (EmployeeManger::login(id, pass) != nullptr)
            {
                while (EmployeeManger::employeeOptions(EmployeeManger::login(id, pass)) != false);
                logout();
            }
            else invalid(2);
            break;
        case3://client
            if (ClientManger::login(id, pass) != nullptr)
            {
                while (ClientManger::clientOptions(ClientManger::login(id, pass)) != false);
                logout();
            }
            else invalid(3);
            break;
        default:
            system("cls");
            loginOptions();


        }

        static void runApp() {
        
            FileManager::getAllData();
            welcome();
            loginScreen(loginAs());
        
        }




    };
