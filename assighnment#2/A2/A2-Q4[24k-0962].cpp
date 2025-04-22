#include <iostream>
#include <string>
using namespace std;

class User
{
protected:
    string name, id, email, password;
    string role;

public:
    User(string n, string i, string e, string pwd, string r)
        : name(n), id(i), email(e), password(pwd), role(r) {}

    bool authenticate(string pwd)
    {
        return password == pwd;
    }

    virtual void display()
    {
        cout << "Name: " << name << "\nID: " << id
             << "\nEmail: " << email << "\nRole: " << role << endl;
    }

    string getRole() { return role; }
};

class Student : public User
{
    bool assignments[10] = {false};
    int assignmentCount = 0;

public:
    Student(string n, string i, string e, string pwd)
        : User(n, i, e, pwd, "Student") {}

    void addAssignment()
    {
        if (assignmentCount < 10)
            assignmentCount++;
    }

    void submit(int index)
    {
        if (index < assignmentCount)
            assignments[index] = true;
    }

    void display() override
    {
        User::display();
        cout << "Assignments: " << assignmentCount << endl;
    }
};

class TA : public Student
{
    Student *students[10];
    string projects[2];
    int studentCount = 0, projectCount = 0;

public:
    TA(string n, string i, string e, string pwd)
        : Student(n, i, e, pwd) { role = "TA"; }

    bool addStudent(Student *s)
    {
        if (studentCount < 10)
        {
            students[studentCount++] = s;
            return true;
        }
        return false;
    }

    bool addProject(string p)
    {
        if (projectCount < 2)
        {
            projects[projectCount++] = p;
            return true;
        }
        return false;
    }

    void display() override
    {
        User::display();
        cout << "Managing " << studentCount << " students\n"
             << "Projects: " << projectCount << endl;
    }
};

class Professor : public User
{
public:
    Professor(string n, string i, string e, string pwd)
        : User(n, i, e, pwd, "Professor") {}

    bool assignProject(TA &ta, string p)
    {
        return ta.addProject(p);
    }

    void display() override
    {
        User::display();
        cout << "Lab Supervisor" << endl;
    }
};

void authenticateAndPerformAction(User *user, string action)
{
    string role = user->getRole();

    if ((role == "Student" && action == "submit") ||
        (role == "TA" && (action == "view" || action == "manage")) ||
        (role == "Professor" && (action == "assign" || action == "full-access")))
    {
        cout << "Action permitted: " << action << endl;
    }
    else
    {
        cout << "Action denied: " << action << endl;
    }
}

int main()
{
    cout<<"Shamveel Khan -24K-0962\n";
    Student s("Shamveel", "S001", "k240962@nu.edu.pk", "student123");
    TA t("TA", "T001", "TA.com", "ta456");
    Professor p("prof", "P001", "PROF.com", "prof789");

    s.addAssignment();
    s.submit(0);
    t.addStudent(&s);
    t.addProject("AI Research");
    p.assignProject(t, "ML Project");

    s.display();
    cout << endl;
    t.display();
    cout << endl;
    p.display();
    cout << endl;

    authenticateAndPerformAction(&s, "submit");
    authenticateAndPerformAction(&t, "manage");
    authenticateAndPerformAction(&p, "assign");
    authenticateAndPerformAction(&s, "view"); 

    cout << "\nAuthentication test: " << s.authenticate("student123") << endl;

    return 0;
}