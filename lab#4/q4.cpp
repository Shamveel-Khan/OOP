#include <iostream>
using namespace std;

class carSystem{
    string brand;
    string model;
    double rentalPrice;
    bool status;
    double totalRevenue=0.0;
    
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
        void updateRevenue(int days) {
            if(!status) {
                cout<<"car is not avaliable for rent!!";
            }
            else {
                double revenue = days * rentalPrice;
                this->totalRevenue+=revenue;
                status=false;
                cout<<"revenue added: "<<revenue<<endl;
            }
        }
        carSystem(string name1,string name2,double price,bool st) {
            brand=name1;
            model=name2;
            rentalPrice=price;
            status=st;
        }
        carSystem(const carSystem &c) {
            brand=c.brand;
            model=c.model;
            rentalPrice=c.rentalPrice;
            status=true;
        }
        void display() {
            cout<<"...................................."<<endl;
            cout<<"brand: "<<brand<<endl;
            cout<<"model: "<<model<<endl;
            cout<<"price: "<<rentalPrice<<endl;
            cout<<"status: "<<status<<endl;
            cout<<"total revenue: "<<totalRevenue<<endl;
            cout<<"...................................."<<endl;
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
    carSystem car1;
    carSystem car2=car1;
    car1.setBrand("toyota");
    car1.setModel("model");
    car1.setPrice(100);
    cout<<"DISPLAYING CAR1: "<<endl;
    car1.display();
    cout<<"DISPLAYING CAR2: "<<endl;
    car2.display();
}