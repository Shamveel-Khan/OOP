#include <iostream>
#include <string>
using namespace std;

enum LicenseType { LEARNER, INTERMEDIATE, FULL };

class User {
private:
    string name;
    int age;
    string userID;
    LicenseType license;

public:
    User(string n, int a, string id, LicenseType l) 
        : name(n), age(a), userID(id), license(l) {}

    string getUserID() { return userID; }
    LicenseType getLicense() { return license; }
    
    void display() {
        cout << "Name: " << name << ", Age: " << age 
             << ", ID: " << userID << ", License: " << license << endl;
    }
};

class Vehicle {
private:
    string model;
    double price;
    LicenseType minLicense;
    bool available;

public:
    Vehicle(string m, double p, LicenseType l) 
        : model(m), price(p), minLicense(l), available(true) {}

    bool isAvailable() { return available; }
    LicenseType getMinLicense() { return minLicense; }
    void setAvailable(bool status) { available = status; }
    
    void display() {
        cout << "Model: " << model << ", Price: $" << price 
             << ", Min License: " << minLicense 
             << ", Available: " << (available ? "Yes" : "No") << endl;
    }
};

class RentalSystem {
private:
    User** users;
    Vehicle** vehicles;
    int userCount;
    int vehicleCount;
    int maxUsers;
    int maxVehicles;

public:
    RentalSystem(int maxU = 10, int maxV = 10) {
        maxUsers = maxU;
        maxVehicles = maxV;
        users = new User*[maxUsers];
        vehicles = new Vehicle*[maxVehicles];
        userCount = vehicleCount = 0;
    }

    ~RentalSystem() {
        for(int i = 0; i < userCount; i++) delete users[i];
        for(int i = 0; i < vehicleCount; i++) delete vehicles[i];
        delete[] users;
        delete[] vehicles;
    }

    void addUser(string name, int age, string id, LicenseType license) {
        if(userCount < maxUsers) {
            users[userCount++] = new User(name, age, id, license);
            cout << "User added successfully\n";
        }
    }

    void addVehicle(string model, double price, LicenseType minLicense) {
        if(vehicleCount < maxVehicles) {
            vehicles[vehicleCount++] = new Vehicle(model, price, minLicense);
            cout << "Vehicle added successfully\n";
        }
    }

    void showAvailableVehicles() {
        for(int i = 0; i < vehicleCount; i++) {
            if(vehicles[i]->isAvailable()) {
                cout << "Vehicle " << i << ": ";
                vehicles[i]->display();
            }
        }
    }

    void rentVehicle(string userID, int vehicleIndex) {
        User* user = nullptr;
        for(int i = 0; i < userCount; i++) {
            if(users[i]->getUserID() == userID) {
                user = users[i];
                break;
            }
        }

        if(!user || vehicleIndex >= vehicleCount || !vehicles[vehicleIndex]->isAvailable()) {
            cout << "Invalid rental request\n";
            return;
        }

        if(user->getLicense() >= vehicles[vehicleIndex]->getMinLicense()) {
            vehicles[vehicleIndex]->setAvailable(false);
            cout << "Vehicle rented successfully\n";
        } else {
            cout << "License requirements not met\n";
        }
    }
};

int main() {
    RentalSystem system;
    cout<<"\nShamveel Khan\n24k-0962\n";
    cout << "\n=== Vehicle Rental System Demo ===\n";

    cout << "\n1. Adding Vehicles:\n";
    system.addVehicle("Toyota Corolla", 50.0, LEARNER);
    system.addVehicle("Honda Civic", 60.0, INTERMEDIATE);
    system.addVehicle("bugati chiron", 100.0, FULL);
    system.addVehicle("mehran dabba", 55.0, LEARNER);
    
    cout << "\n2. Initial Vehicle Inventory:\n";
    system.showAvailableVehicles();

    cout << "\n3. Registering Users:\n";
    system.addUser("Shamveel khan", 20, "U001", LEARNER);
    system.addUser("usman hassan", 25, "U002", INTERMEDIATE);
    system.addUser("moiz mughal", 30, "U003", FULL);

    cout << "\n4. Testing Rental Restrictions:\n";
    
    cout << "\nLearner License Tests (Shamveel - U001):\n";
    system.rentVehicle("U001", 0); 
    system.rentVehicle("U001", 1);  
    system.rentVehicle("U001", 2);  

    cout << "\nIntermediate License Tests (Usman - U002):\n";
    system.rentVehicle("U002", 1);
    system.rentVehicle("U002", 2);  
    cout << "\nFull License Tests (Moiz - U003):\n";
    system.rentVehicle("U003", 2); 

    cout << "\n5. Updated Vehicle Inventory:\n";
    system.showAvailableVehicles();

    cout << "\n6. Testing Error Cases:\n";

    cout << "Attempting to rent an already rented vehicle:\n";
    system.rentVehicle("U002", 0); 
    
    cout << "Attempting to rent with invalid user ID:\n";
    system.rentVehicle("U999", 3); 

    cout << "Attempting to rent with invalid vehicle index:\n";
    system.rentVehicle("U003", 9); 
    cout << "\n=== Demo Complete ===\n";
    return 0;
}