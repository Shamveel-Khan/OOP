#include <iostream>
using namespace std;

class AlarmSystem
{
    string securityLevel;

public:
    AlarmSystem(string level) : securityLevel(level) {}
    void display()
    {
        cout << "Security Level: " << securityLevel << endl;
    }
};

class SmartHome
{
    string homeName;
    AlarmSystem alarm;

public:
    SmartHome(string name, string level) : homeName(name), alarm(level) {}
    void display()
    {
        cout << "\n.......................\n";
        cout << "Home Name: " << homeName << endl;
        alarm.display();
        cout << ".......................\n";
    }
};

int main()
{
    SmartHome home1("Luxury Villa", "High");
    home1.display();

    return 0;
}