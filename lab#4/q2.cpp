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
        carSystem(string name1,string name2,double price,bool st) {
            brand=name1;
            model=name2;
            rentalPrice=price;
            status=st;
        }
        void applyDiscount(int days) {
            if(status) {
                if(days >=5) {
                    if(days>=10) {
                        rentalPrice*=0.9;
                    }
                    else {
                        rentalPrice*=0.95;
                    }
                }
            }
            else {
                cout<<"car is not avaliable";
            }
        }
};

int main() {
    
}

