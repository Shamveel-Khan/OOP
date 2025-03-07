#include <iostream>
using namespace std;

class device {
protected:
    int ID;
    bool status;

public:
    device(int id, bool s) : ID(id), status(s) {}

    void display() {
        cout << "....................\n";
        cout << "Device ID: " << ID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "....................\n";
    }
};

class smartPhone : virtual public device {
protected:
    float screenSize;

public:
    smartPhone(int id, bool s, float size) : device(id, s), screenSize(size) {}

    void display() {
        cout << "....................\n";
        cout << "Device ID: " << ID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "....................\n";
    }
};

class smartWatch : virtual public device {
protected:
    bool heartRateMonitor;

public:
    smartWatch(int id, bool s, bool hrm) : device(id, s), heartRateMonitor(hrm) {}

    void display() {
        cout << "....................\n";
        cout << "Device ID: " << ID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "....................\n";
    }
};

class smartWearable : public smartPhone, public smartWatch {
protected:
    int stepCounter;

public:
    smartWearable(int id, bool s, float size, bool hrm, int steps)
        : device(id, s), smartPhone(id, s, size), smartWatch(id, s, hrm), stepCounter(steps) {}

    void display() {
        cout << "....................\n";
        cout << "Device ID: " << ID << endl;
        cout << "Status: " << (status ? "On" : "Off") << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << endl;
        cout << "....................\n";
    }
};

int main() {
    smartWearable sw(501, true, 6.5, true, 10000);
    sw.display();
    return 0;
}
