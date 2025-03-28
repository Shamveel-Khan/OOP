#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string n, int a, string c, string ad = "") : name(n), age(a), contactNumber(c), address(ad) {}
    virtual void displayInfo()
    {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber << "\nAddress: " << address << "\n";
    }
    virtual void updateInfo(string newContact)
    {
        contactNumber = newContact;
    }
};

class Patient : public Person
{
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string n, int a, string c, int id, string mh, string doc) : Person(n, a, c), patientID(id), medicalHistory(mh), doctorAssigned(doc) {}
    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory << "\nDoctor Assigned: " << doctorAssigned << "\n";
    }
};

class Doctor : public Person
{
    string specialization;
    double consultationFee;
    string patientsList;

public:
    Doctor(string n, int a, string c, string spec, double fee, string plist) : Person(n, a, c), specialization(spec), consultationFee(fee), patientsList(plist) {}
    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nConsultation Fee: " << consultationFee << "\nPatients List: " << patientsList << "\n";
    }
};

class Nurse : public Person
{
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string n, int a, string c, string ward, string shift) : Person(n, a, c), assignedWard(ward), shiftTimings(shift) {}
    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << "\n";
    }
};

class Administrator : public Person
{
    string department;
    double salary;

public:
    Administrator(string n, int a, string c, string dept, double sal) : Person(n, a, c), department(dept), salary(sal) {}
    void updateInfo(string newContact) override
    {
        contactNumber = newContact;
        cout << "Administrator contact updated.\n";
    }
};

int main()
{
    Patient p1("Ali Khan", 30, "03001234567", 101, "Diabetes", "Dr. Ahmed");
    Doctor d1("Dr. Ahmed", 45, "03211234567", "Cardiologist", 5000, "Ali Khan, Bilal");
    Nurse n1("Sara Bibi", 28, "03151234567", "Emergency", "Night");
    Administrator a1("Umer Farooq", 50, "03451234567", "HR", 100000);

    cout << "--- Patient Info ---\n";
    p1.displayInfo();

    cout << "--- Doctor Info ---\n";
    d1.displayInfo();

    cout << "--- Nurse Info ---\n";
    n1.displayInfo();

    cout << "--- Administrator Info ---\n";
    a1.updateInfo("03456789012");

    return 0;
}