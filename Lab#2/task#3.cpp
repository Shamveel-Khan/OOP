#include <iostream>
using namespace std;

struct Employee {
    string name;
    int hourlyRate;
    int hoursWorked;
};

int main() {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    Employee* employees = new Employee[numEmployees];
    for (int i = 0; i < numEmployees; i++) {
        cout << "Enter details for employee #" << i + 1 << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Hourly Rate: ";
        cin >> employees[i].hourlyRate;
        cout << "Hours Worked: ";
        cin >> employees[i].hoursWorked;
    }
    int totalSalary;
    cout << "\nEmployee Salary Details:\n";
    for (int i = 0; i < numEmployees; i++) {
        totalSalary = employees[i].hourlyRate * employees[i].hoursWorked;
        cout << "Name: " << employees[i].name
             << ", Hourly Rate: " << employees[i].hourlyRate
             << ", Hours Worked: " << employees[i].hoursWorked
             << ", Total Salary: " << totalSalary << endl;
    }
    delete[] employees;
    return 0;
}
