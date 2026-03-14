#include <iostream>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"
#include "Admin.h"
#include "Client.h"

using namespace std;

int main() {
    cout << "=== Phase 1 Test Start ===\n\n";

    // 1) Validation tests
    cout << "[Validation]\n";
    cout << "Name 'Ahmad' -> " << (Validation::set_name("Ahmad") ? "PASS" : "FAIL") << "\n";
    cout << "Name 'A1' -> " << (!Validation::set_name("A1") ? "PASS" : "FAIL") << "\n";

    cout << "Password 'Password12' -> " << (Validation::set_password("Password12") ? "PASS" : "FAIL") << "\n";
    cout << "Password 'Pass word12' (space) -> " << (!Validation::set_password("Pass word12") ? "PASS" : "FAIL") << "\n";

    cout << "Balance 1500 -> " << (Validation::set_balance(1500) ? "PASS" : "FAIL") << "\n";
    cout << "Balance 1499 -> " << (!Validation::set_balance(1499) ? "PASS" : "FAIL") << "\n";

    cout << "Salary 5000 -> " << (Validation::set_salary(5000) ? "PASS" : "FAIL") << "\n";
    cout << "Salary 4000 -> " << (!Validation::set_salary(4000) ? "PASS" : "FAIL") << "\n\n";

    // 2) Client tests
    cout << "[Client]\n";
    Client c1(1, "Ahmad", "Password12", 2000);
    Client c2(2, "Omar", "StrongPass", 1500);

    cout << "Initial c1:\n"; c1.display();
    cout << "Initial c2:\n"; c2.display();

    cout << "\nDeposit 500 to c1 (expected 2500)\n";
    c1.deposit(500);
    c1.checkBalance();

    cout << "\nWithdraw 700 from c1 (expected 1800)\n";
    c1.withdraw(700);
    c1.checkBalance();

    cout << "\nWithdraw 200 from c1 (expected 1600)\n";
    c1.withdraw(200);
    c1.checkBalance();

    cout << "\nWithdraw 200 from c1 (should FAIL because would go < 1500)\n";
    c1.withdraw(200);
    c1.checkBalance();

    cout << "\nTransfer 100 from c1 to c2 (expected c1=1500, c2=1600)\n";
    c1.transferTo(100, c2);
    cout << "c1: "; c1.checkBalance();
    cout << "c2: "; c2.checkBalance();

    cout << "\nTransfer 100 from c1 to c2 (should FAIL because c1 would go < 1500)\n";
    c1.transferTo(100, c2);
    cout << "c1: "; c1.checkBalance();
    cout << "c2: "; c2.checkBalance();

    // 3) Employee/Admin tests
    cout << "\n[Employee/Admin]\n";
    Employee e1(10, "Yazan", "EmpPass123", 6000);
    cout << "Employee e1:\n";
    e1.display();

    Admin a1(99, "Admin", "AdminPass1", 8000);
    cout << "Admin a1:\n";
    a1.display();

    cout << "\n=== Phase 1 Test End ===\n";
    return 0;
}