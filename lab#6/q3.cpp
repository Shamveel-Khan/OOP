#include <iostream>
using namespace std;

class person
{
protected:
    string name;
    int age;

public:
    person(string n, int a) : name(n), age(a) {}
    void display()
    {
        cout << "\n.....................\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "\n.....................\n";
    }
};

class teacher : protected person
{
protected:
    string subject;

public:
    teacher(string n, int a, string su) : person(n, a), subject(su) {}
    void display()
    {
        cout << "\n.....................\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "\n.....................\n";
    }
};

class researcher : protected teacher
{
protected:
    string researchArea;

public:
    researcher(string n, int a, string su, string ra) : teacher(n, a, su), researchArea(ra) {}
    void display()
    {
        cout << "\n.....................\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "\n.....................\n";
    }
};

class professor : protected researcher
{
protected:
    string publications;

public:
    professor(string n, int a, string su, string ra, string pu) : researcher(n, a, su, ra), publications(pu) {}
    void display()
    {
        cout << "\n.....................\n";
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
        cout << "\n.....................\n";
    }
};

int main()
{
    professor Shamveel("Shamveel", 18, "CS", "AI", "Deepseek meri hai!");
    Shamveel.display();
}