#include <iostream>
using namespace std;

class device
{
protected:
    int deviceId;
    string name;
    bool status;
    string location;

public:
    device(int id, string n, string loc) : deviceId(id), name(n), status(false), location(loc) {}
    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    virtual bool getStatus() { return status; }
    virtual void display()
    {
        cout << "..................\n";
        cout << "Device Id: " << deviceId << endl;
        cout << "Device Name: " << name << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Location: " << location << endl;
        cout << "..................\n";
    }
};

class light : public device
{
private:
    int brightnessLevel;
    string colorMode;

public:
    light(int id, string n, string loc, int brightness, string color) : device(id, n, loc), brightnessLevel(brightness), colorMode(color) {}
    void display() override
    {
        cout << "..................\n";
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
        cout << "..................\n";
    }
};

class thermostat : public device
{
private:
    int temp;
    int targetTemp;
    string mode;

public:
    thermostat(int id, string n, string loc, int t, int target, string m) : device(id, n, loc), temp(t), targetTemp(target), mode(m) {}
    bool getStatus() override
    {
        cout << "The current temperature is: " << temp << endl;
        return status;
    }
};

class securityCamera : public device
{
private:
    int resolution;
    bool isRecording;
    bool isNightVisionOn;

public:
    securityCamera(int id, string n, string loc, int res) : device(id, n, loc), resolution(res), isRecording(false), isNightVisionOn(false) {}
    void turnOn() override { isRecording = true; }
};

class smartPlug : public device
{
private:
    int powerConsumption;
    string timer;

public:
    smartPlug(int id, string n, string loc, int power, string t) : device(id, n, loc), powerConsumption(power), timer(t) {}
    void turnOff() override
    {
        cout << "Power consumed is: " << powerConsumption << endl;
        cout << "Timer: " << timer << endl;
    }
};

int main()
{
}