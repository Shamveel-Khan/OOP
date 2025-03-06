#include <iostream>
using namespace std;

class doctor
{
    string name;
    string specialization;
    string experience;

public:
    doctor(string n, string s, string e) : name(n), specialization(s), experience(e) {}
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << endl;
    }
};

class hospital
{
    string name;
    string owner;
    int numberOfDoctors = 0;
    doctor **list;

public:
    hospital(string n, string o, int num)
    {
        name = n;
        owner = o;
        numberOfDoctors = num;
        list = new doctor *[num];
    }
    ~hospital() { delete[] list; }
    void addDoctor(doctor *d, int index)
    {
        if (index < numberOfDoctors)
            list[index] = d;
    }
    void display()
    {
        cout << "\n\n......HOSPITAL......\n";
        cout << "Name: " << name << endl;
        cout << "Owner: " << owner << endl;
        cout << "Number of doctors: " << numberOfDoctors << endl;
        cout << "\n...DOCTORS...\n";
        for (int i = 0; i < numberOfDoctors; i++)
        {
            cout << "\nDoctor # " << i + 1 << endl;
            list[i]->display();
        }
    }
};

int main()
{
    hospital h("Shamveel hospital", "Shamveel the King", 3);
    doctor d1("Shamveel", "Cardiologist", "500 years");
    doctor d2("Moiz", "Neurologist", "8 years");
    doctor d3("Usman", "Orthopedic", "5 years");

    h.addDoctor(&d1, 0);
    h.addDoctor(&d2, 1);
    h.addDoctor(&d3, 2);

    h.display();

    return 0;
}
