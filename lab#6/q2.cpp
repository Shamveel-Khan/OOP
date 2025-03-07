#include <iostream>
using namespace std;

class vehicle
{
protected:
    string brand;
    int speed;

public:
    vehicle(string b, int s) : brand(b), speed(s) {}
    void display()
    {
        cout << "\n........................\n";
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
        cout << "\n........................\n";
    }
};

class car : protected vehicle
{
protected:
    int seats;

public:
    car(string b, int s, int se) : vehicle(b, s), seats(s) {}
    void display()
    {
        cout << "\n........................\n";
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
        cout << "Seats: " << seats << endl;
        cout << "\n........................\n";
    }
};

class electricCar : protected car
{
protected:
    int batteryLife;

public:
    electricCar(string b, int s, int se, int ba) : car(b, s, se), batteryLife(ba) {}
    void display()
    {
        cout << "\n........................\n";
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
        cout << "Seats: " << seats << endl;
        cout << "Battery life: " << batteryLife << endl;
        cout << "\n........................\n";
    }
};

int main()
{
    electricCar tesla("tesla", 160, 5, 600);
    tesla.display();
}