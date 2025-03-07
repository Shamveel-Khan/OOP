#include <iostream>
using namespace std;

class employee
{
protected:
    string name;
    float salary;

public:
    employee(string n, float f) : name(n), salary(f) {}
    void display()
    {
        cout << "\n....................\n";
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "....................\n";
    }
};

class manager : protected employee
{
    float bonus;

public:
    manager(string n, float f, float b) : employee(n, f), bonus(b) {}
    void display()
    {
        cout << "\n....................\n";
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "....................\n";
    }
};

int main()
{
    employee emp1("moiz", 100.0);
    manager m1("Shamveel", 1000.0, 10.0);
    m1.display();
    emp1.display();
}