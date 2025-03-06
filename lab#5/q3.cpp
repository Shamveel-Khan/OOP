#include <iostream>
using namespace std;

class employee
{
    string name;
    string designation;

public:
    employee(string name, string de) : name(name), designation(de) {}
    void display()
    {
        cout << "\nName: " << name << endl;
        cout << "designation: " << designation << endl;
    }
};

class project
{
    string title;
    string deadline;
    int numberOfEmployees = 0;
    employee **list;

public:
    project(string t, string de, int num)
    {
        title = t;
        deadline = de;
        numberOfEmployees = num;
        list = new employee *[numberOfEmployees];
    }
    ~project()
    {
        for (int i = 0; i < numberOfEmployees; i++)
        {
            delete list[i];
        }
        delete[] list;
    }

    void addEmployee(employee *e)
    {
        list[numberOfEmployees++] = e;
    }
    void display()
    {
        cout << "\n.......................\n";
        cout << "TITLE: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "employees on the project\n";
        for (int i = 0; i < numberOfEmployees; i++)
        {
            cout << "Employee # " << i + 1 << endl;
            list[i]->display();
        }
        cout << "\n.......................\n";
    }
};

int main()
{
    employee *e1 = new employee("shamveel", "Manager");
    employee *e2 = new employee("moiz", "Developer");
    employee *e3 = new employee("usman", "Designer");
    employee *e4 = new employee("kabeer", "Analyst");
    employee *e5 = new employee("ali", "Tester");
    employee *e6 = new employee("ahmed", "HR");
    employee *e7 = new employee("awais", "Support");

    project p1("AI System", "30-04-2025", 7);

    p1.addEmployee(e1);
    p1.addEmployee(e2);
    p1.addEmployee(e3);
    p1.addEmployee(e4);
    p1.addEmployee(e5);
    p1.addEmployee(e6);
    p1.addEmployee(e7);

    p1.display();

    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    delete e6;
    delete e7;

    return 0;
}