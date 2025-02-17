#include <iostream>
using namespace std;

class carSystem{
    string brand;
    string model;
    double rentalPrice;
    bool status;
    
    public:
        carSystem() {
            brand="unknown";
            model="generic";
            rentalPrice=0.0;
            status=true;
        }
        void setBrand(string name) {
            brand=name;
        }
        void setModel(string name) {
            model=name;
        }
        void setPrice(double num) {
            if(num>0.0) {
                rentalPrice=num;
            }
        }
        void setStatus(bool st) {
            status=st;
        }
        void rentCar() {
            if(status) status = !status;
        }
        void checkStatus() {
            if(status) {
                cout<<"the car is avaliable"<<endl;
            }
            else {
                cout<<"car is not avaliable"<<endl;
            }
        }
        
};

int main() {
    
}

