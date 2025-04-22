#include <iostream>
#include <string>

using namespace std;

class Patient
{
protected:
    string name;
    string id;

public:
    Patient(string name, string id) : name(name), id(id) {}

    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;

    string getName() const { return name; }
    string getId() const { return id; }
};

class InPatient : public Patient
{
private:
    int daysStay;
    bool surgeryRequired;

public:
    InPatient(string name, string id, int daysStay, bool surgeryRequired)
        : Patient(name, id), daysStay(daysStay), surgeryRequired(surgeryRequired) {}

    void displayTreatment() override
    {
        cout << "InPatient Treatment for " << name << " (ID: " << id << "):" << endl;
        cout << "- Hospital stay for " << daysStay << " days" << endl;
        if (surgeryRequired)
        {
            cout << "- Surgical procedure required" << endl;
        }
        cout << "- Daily monitoring and medication" << endl;
        cout << "- Regular physician visits" << endl;
    }

    double calculateCost() override
    {
        double cost = 1200.0 * daysStay;

        if (surgeryRequired)
        {
            cost += 4500.0;
        }

        return cost;
    }
};

class OutPatient : public Patient
{
private:
    bool diagnostic;
    int treatmentSessions;

public:
    OutPatient(string name, string id, bool diagnostic, int treatmentSessions)
        : Patient(name, id), diagnostic(diagnostic), treatmentSessions(treatmentSessions) {}

    void displayTreatment() override
    {
        cout << "OutPatient Treatment for " << name << " (ID: " << id << "):" << endl;
        if (diagnostic)
        {
            cout << "- Diagnostic procedures" << endl;
        }
        cout << "- " << treatmentSessions << " treatment sessions" << endl;
        cout << "- Medication prescription" << endl;
        cout << "- Follow-up appointment" << endl;
    }

    double calculateCost() override
    {
        double cost = 200.0;

        if (diagnostic)
        {
            cost += 350.0;
        }

        cost += 150.0 * treatmentSessions;

        return cost;
    }
};

int main()
{
    Patient *patients[4];

    patients[0] = new InPatient("Shamveel", "IP001", 5, true);
    patients[1] = new InPatient("Usman", "IP002", 3, false);
    patients[2] = new OutPatient("Moiz", "OP001", true, 2);
    patients[3] = new OutPatient("Abdullah", "OP002", false, 4);

    for (int i = 0; i < 4; i++)
    {
        cout << "\n===================================" << endl;
        patients[i]->displayTreatment();
        cout << "Total cost: $" << patients[i]->calculateCost() << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete patients[i];
    }

    return 0;
}