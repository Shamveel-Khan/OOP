#include <iostream>
using namespace std;

class car {
    string brand;
    string model;
    int fuelCapacity;
    int currentFuelLevel=0;
    public:
        void driveCar(int fuelSpent) {
            currentFuelLevel-=fuelSpent;
        }
        void refuelCar(int fuelInput) {
            currentFuelLevel+=fuelInput;
        }
        void checkFuel() {
            cout<<"the fuel remaining is: "<<currentFuelLevel<<endl;
        }
        void setBrand(string name) {
            brand=name;
        }
        void setModel(string name) {
            model = name;
        }
};

int main() {
    int start=1;
    int choice;
    int tmp;
    car shamveel;
    shamveel.setBrand("bugati");
    shamveel.setModel("chorin");
    while(start) {
        cout<<"---fuel management system---"<<endl;
        cout<<"1.Drive Car\n2.Refuel Car\n3.Check Fuel\n4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"enter fuel consumed: ";
                cin>>tmp;
                shamveel.driveCar(tmp);
                break;
            case 2:
                cout<<"enter fuel filled: ";
                cin>>tmp;
                shamveel.refuelCar(tmp);
                break;
            case 3:
                shamveel.checkFuel();
                break;
            case 4:
                start=0;
                break;
            default:
                cout<<"Wrong choice try again!!"<<endl;
                break;
        }
    }
}