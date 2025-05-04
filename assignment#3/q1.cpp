#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Vehicle;
class Driver;
class Route;

class User {
protected:
    string id;
    string name;
    string contactNumber;
    bool isStudent;
    int bookingsThisMonth;
    bool paymentCompleted;

public:
    User(string id, string name, string contactNumber, bool isStudent)
        : id(id), name(name), contactNumber(contactNumber), isStudent(isStudent), 
          bookingsThisMonth(0), paymentCompleted(false) {}
    
    string getId() const { return id; }
    string getName() const { return name; }
    bool getIsStudent() const { return isStudent; }
    int getBookingsThisMonth() const { return bookingsThisMonth; }
    
    bool canBook() const {
        return bookingsThisMonth < 1;
    }
    
    void incrementBooking() {
        bookingsThisMonth++;
    }
    
    void resetMonthlyBookings() {
        bookingsThisMonth = 0;
    }
    
    void makePayment() {
        paymentCompleted = true;
        cout << "Payment of Rs. 2000 completed for user: " << name << endl;
    }
    
    bool hasCompletedPayment() const {
        return paymentCompleted;
    }
    
    void resetPaymentStatus() {
        paymentCompleted = false;
    }
    
    void displayInfo() const {
        cout << "User ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Type: " << (isStudent ? "Student" : "Faculty") << endl;
        cout << "Bookings this month: " << bookingsThisMonth << endl;
    }
};

class Route {
private:
    string routeId;
    string startLocation;
    string endLocation;
    double distance;
    bool isLongDistance;

public:
    Route(string routeId, string startLocation, string endLocation, double distance)
        : routeId(routeId), startLocation(startLocation), endLocation(endLocation), 
          distance(distance) {
        isLongDistance = (distance > 25.0);
    }
    
    string getRouteId() const { return routeId; }
    double getDistance() const { return distance; }
    bool getIsLongDistance() const { return isLongDistance; }
    
    void displayInfo() const {
        cout << "Route: " << routeId << endl;
        cout << "From: " << startLocation << " To: " << endLocation << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Type: " << (isLongDistance ? "Long Distance" : "Regular") << endl;
    }
};

class Driver {
private:
    string driverId;
    string name;
    string licenseNumber;
    string contactNumber;
    Vehicle* assignedVehicle;

public:
    Driver(string driverId, string name, string licenseNumber, string contactNumber)
        : driverId(driverId), name(name), licenseNumber(licenseNumber), 
          contactNumber(contactNumber), assignedVehicle(NULL) {}
    
    string getDriverId() const { return driverId; }
    string getName() const { return name; }
    
    void assignVehicle(Vehicle* vehicle) {
        assignedVehicle = vehicle;
    }
    
    Vehicle* getAssignedVehicle() const {
        return assignedVehicle;
    }
    
    bool isAvailable() const {
        return assignedVehicle == NULL;
    }
    
    void displayInfo() const {
        cout << "Driver ID: " << driverId << endl;
        cout << "Name: " << name << endl;
        cout << "License: " << licenseNumber << endl;
        cout << "Contact: " << contactNumber << endl;
        cout << "Status: " << (isAvailable() ? "Available" : "Assigned to a vehicle") << endl;
    }
};

class Vehicle {
private:
    string vehicleId;
    string type;
    int totalSeats;
    bool hasAC;
    Driver* driver;
    Route* route;
    User** seats;
    bool* seatAvailability;
    string designation;

public:
    Vehicle(string vehicleId, string type, int totalSeats, bool hasAC, string designation)
        : vehicleId(vehicleId), type(type), totalSeats(totalSeats), hasAC(hasAC), 
          driver(NULL), route(NULL), designation(designation) {
        
        seats = new User*[totalSeats];
        seatAvailability = new bool[totalSeats];
        
        for (int i = 0; i < totalSeats; i++) {
            seats[i] = NULL;
            seatAvailability[i] = true;
        }
    }
    
    ~Vehicle() {
        delete[] seats;
        delete[] seatAvailability;
    }
    
    string getVehicleId() const { return vehicleId; }
    int getTotalSeats() const { return totalSeats; }
    bool getHasAC() const { return hasAC; }
    string getDesignation() const { return designation; }
    
    void assignDriver(Driver* d) {
        driver = d;
        if (d != NULL) {
            d->assignVehicle(this);
        }
    }
    
    void assignRoute(Route* r) {
        route = r;
    }
    
    bool bookSeat(int seatNumber, User* user) {
        if (seatNumber < 0 || seatNumber >= totalSeats) {
            cout << "Invalid seat number." << endl;
            return false;
        }
        
        if (!seatAvailability[seatNumber]) {
            cout << "Seat " << seatNumber << " is already booked." << endl;
            return false;
        }
        
        if (user->getBookingsThisMonth() >= 1) {
            cout << "User has already used their monthly booking limit." << endl;
            return false;
        }
        
        if (!user->hasCompletedPayment()) {
            cout << "Payment must be completed before booking." << endl;
            return false;
        }
        
        if (designation == "Faculty" && user->getIsStudent()) {
            cout << "This vehicle is designated for faculty only." << endl;
            return false;
        }
        
        if (designation == "Student" && !user->getIsStudent()) {
            cout << "This vehicle is designated for students only." << endl;
            return false;
        }
        
        seats[seatNumber] = user;
        seatAvailability[seatNumber] = false;
        user->incrementBooking();
        
        cout << "Seat " << seatNumber << " booked successfully for " << user->getName() << endl;
        return true;
    }
    
    bool cancelBooking(int seatNumber) {
        if (seatNumber < 0 || seatNumber >= totalSeats) {
            cout << "Invalid seat number." << endl;
            return false;
        }
        
        if (seatAvailability[seatNumber]) {
            cout << "Seat " << seatNumber << " is not booked." << endl;
            return false;
        }
        
        seats[seatNumber] = NULL;
        seatAvailability[seatNumber] = true;
        
        cout << "Booking for seat " << seatNumber << " cancelled successfully." << endl;
        return true;
    }
    
    void displayInfo() const {
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Type: " << type << " (" << totalSeats << " seats)" << endl;
        cout << "AC: " << (hasAC ? "Yes" : "No") << endl;
        cout << "Designation: " << designation << endl;
        
        if (driver != NULL) {
            cout << "Driver: " << driver->getName() << " (ID: " << driver->getDriverId() << ")" << endl;
        } else {
            cout << "Driver: Not assigned" << endl;
        }
        
        if (route != NULL) {
            cout << "Route: " << route->getRouteId() << endl;
        } else {
            cout << "Route: Not assigned" << endl;
        }
    }
    
    void displaySeats() const {
        cout << "Seat availability for " << vehicleId << ":" << endl;
        for (int i = 0; i < totalSeats; i++) {
            cout << "Seat " << i << ": ";
            if (seatAvailability[i]) {
                cout << "Available" << endl;
            } else {
                cout << "Booked by " << seats[i]->getName() << endl;
            }
        }
    }
};

class TransportManagementSystem {
private:
    User** users;
    Vehicle** vehicles;
    Driver** drivers;
    Route** routes;
    int userCount;
    int vehicleCount;
    int driverCount;
    int routeCount;
    int maxUsers;
    int maxVehicles;
    int maxDrivers;
    int maxRoutes;

public:
    TransportManagementSystem(int maxUsers, int maxVehicles, int maxDrivers, int maxRoutes)
        : maxUsers(maxUsers), maxVehicles(maxVehicles), maxDrivers(maxDrivers), maxRoutes(maxRoutes),
          userCount(0), vehicleCount(0), driverCount(0), routeCount(0) {
        
        users = new User*[maxUsers];
        vehicles = new Vehicle*[maxVehicles];
        drivers = new Driver*[maxDrivers];
        routes = new Route*[maxRoutes];
    }
    
    ~TransportManagementSystem() {
        for (int i = 0; i < userCount; i++) {
            delete users[i];
        }
        
        for (int i = 0; i < vehicleCount; i++) {
            delete vehicles[i];
        }
        
        for (int i = 0; i < driverCount; i++) {
            delete drivers[i];
        }
        
        for (int i = 0; i < routeCount; i++) {
            delete routes[i];
        }
        
        delete[] users;
        delete[] vehicles;
        delete[] drivers;
        delete[] routes;
    }
    
    void registerUser(string id, string name, string contactNumber, bool isStudent) {
        if (userCount < maxUsers) {
            users[userCount] = new User(id, name, contactNumber, isStudent);
            cout << "User registered successfully: " << name << endl;
            userCount++;
        } else {
            cout << "Maximum user limit reached." << endl;
        }
    }
    
    void addVehicle(string vehicleId, string type, int totalSeats, bool hasAC, string designation) {
        if (vehicleCount < maxVehicles) {
            vehicles[vehicleCount] = new Vehicle(vehicleId, type, totalSeats, hasAC, designation);
            cout << "Vehicle added successfully: " << vehicleId << endl;
            vehicleCount++;
        } else {
            cout << "Maximum vehicle limit reached." << endl;
        }
    }
    
    void addDriver(string driverId, string name, string licenseNumber, string contactNumber) {
        if (driverCount < maxDrivers) {
            drivers[driverCount] = new Driver(driverId, name, licenseNumber, contactNumber);
            cout << "Driver added successfully: " << name << endl;
            driverCount++;
        } else {
            cout << "Maximum driver limit reached." << endl;
        }
    }
    
    void addRoute(string routeId, string startLocation, string endLocation, double distance) {
        if (routeCount < maxRoutes) {
            routes[routeCount] = new Route(routeId, startLocation, endLocation, distance);
            cout << "Route added successfully: " << routeId << endl;
            routeCount++;
        } else {
            cout << "Maximum route limit reached." << endl;
        }
    }
    
    User* findUser(string userId) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getId() == userId) {
                return users[i];
            }
        }
        return NULL;
    }
    
    Vehicle* findVehicle(string vehicleId) {
        for (int i = 0; i < vehicleCount; i++) {
            if (vehicles[i]->getVehicleId() == vehicleId) {
                return vehicles[i];
            }
        }
        return NULL;
    }
    
    Driver* findDriver(string driverId) {
        for (int i = 0; i < driverCount; i++) {
            if (drivers[i]->getDriverId() == driverId) {
                return drivers[i];
            }
        }
        return NULL;
    }
    
    Route* findRoute(string routeId) {
        for (int i = 0; i < routeCount; i++) {
            if (routes[i]->getRouteId() == routeId) {
                return routes[i];
            }
        }
        return NULL;
    }
    
    void assignDriverToVehicle(string driverId, string vehicleId) {
        Driver* driver = findDriver(driverId);
        Vehicle* vehicle = findVehicle(vehicleId);
        
        if (driver != NULL && vehicle != NULL) {
            vehicle->assignDriver(driver);
            cout << "Driver " << driver->getName() << " assigned to vehicle " << vehicleId << endl;
        } else {
            cout << "Driver or vehicle not found." << endl;
        }
    }
    
    void assignRouteToVehicle(string routeId, string vehicleId) {
        Route* route = findRoute(routeId);
        Vehicle* vehicle = findVehicle(vehicleId);
        
        if (route != NULL && vehicle != NULL) {
            vehicle->assignRoute(route);
            cout << "Route " << routeId << " assigned to vehicle " << vehicleId << endl;
        } else {
            cout << "Route or vehicle not found." << endl;
        }
    }
    
    bool bookSeat(string userId, string vehicleId, int seatNumber) {
        User* user = findUser(userId);
        Vehicle* vehicle = findVehicle(vehicleId);
        
        if (user != NULL && vehicle != NULL) {
            return vehicle->bookSeat(seatNumber, user);
        } else {
            cout << "User or vehicle not found." << endl;
            return false;
        }
    }
    
    void displayAllUsers() const {
        cout << "\n===== REGISTERED USERS =====" << endl;
        for (int i = 0; i < userCount; i++) {
            users[i]->displayInfo();
            cout << "--------------------------" << endl;
        }
    }
    
    void displayAllVehicles() const {
        cout << "\n===== VEHICLES =====" << endl;
        for (int i = 0; i < vehicleCount; i++) {
            vehicles[i]->displayInfo();
            cout << "--------------------------" << endl;
        }
    }
    
    void displayAllDrivers() const {
        cout << "\n===== DRIVERS =====" << endl;
        for (int i = 0; i < driverCount; i++) {
            drivers[i]->displayInfo();
            cout << "--------------------------" << endl;
        }
    }
    
    void displayAllRoutes() const {
        cout << "\n===== ROUTES =====" << endl;
        for (int i = 0; i < routeCount; i++) {
            routes[i]->displayInfo();
            cout << "--------------------------" << endl;
        }
    }
    
    void saveToFile() const {
        ofstream file("transport_data.txt");
        
        if (file.is_open()) {
            file << "FAST-NUCES TRANSPORT MANAGEMENT SYSTEM DATA\n";
            file << "===========================================\n\n";
            
            file << "USERS (" << userCount << "):\n";
            for (int i = 0; i < userCount; i++) {
                file << "ID: " << users[i]->getId() << ", Name: " << users[i]->getName() 
                     << ", Type: " << (users[i]->getIsStudent() ? "Student" : "Faculty") << "\n";
            }
            
            file << "\nVEHICLES (" << vehicleCount << "):\n";
            for (int i = 0; i < vehicleCount; i++) {
                file << "ID: " << vehicles[i]->getVehicleId() 
                     << ", Seats: " << vehicles[i]->getTotalSeats() 
                     << ", AC: " << (vehicles[i]->getHasAC() ? "Yes" : "No") 
                     << ", Designation: " << vehicles[i]->getDesignation() << "\n";
            }
            
            file << "\nDRIVERS (" << driverCount << "):\n";
            for (int i = 0; i < driverCount; i++) {
                file << "ID: " << drivers[i]->getDriverId() 
                     << ", Name: " << drivers[i]->getName() << "\n";
            }
            
            file << "\nROUTES (" << routeCount << "):\n";
            for (int i = 0; i < routeCount; i++) {
                file << "ID: " << routes[i]->getRouteId() 
                     << ", Distance: " << routes[i]->getDistance() 
                     << "km, Long Distance: " << (routes[i]->getIsLongDistance() ? "Yes" : "No") << "\n";
            }
            
            file.close();
            cout << "Data saved to transport_data.txt successfully." << endl;
        } else {
            cout << "Unable to open file for saving data." << endl;
        }
    }
};

int main() {
    cout << "FAST-NUCES TRANSPORT MANAGEMENT SYSTEM" << endl;
    cout << "======================================" << endl;
    
    TransportManagementSystem tms(100, 20, 30, 15);
    
    tms.registerUser("F001", "Shamveel", "0300-1234567", false);
    tms.registerUser("F002", "Usman", "0301-2345678", false);
    tms.registerUser("S001", "Moiz", "0302-3456789", true);
    tms.registerUser("S002", "Abdullah", "0303-4567890", true);
    
    tms.addVehicle("V001", "Bus", 52, true, "Mixed");
    tms.addVehicle("V002", "Bus", 52, false, "Student");
    tms.addVehicle("V003", "Coaster", 32, true, "Faculty");
    
    tms.addDriver("D001", "Nadeem", "LIC-001", "0310-1122334");
    tms.addDriver("D002", "Zulfiqar", "LIC-002", "0311-2233445");
    
    tms.addRoute("R001", "FAST Campus", "DHA", 15.5);
    tms.addRoute("R002", "FAST Campus", "Gulshan", 22.8);
    tms.addRoute("R003", "FAST Campus", "Malir", 35.2);
    
    tms.assignDriverToVehicle("D001", "V001");
    tms.assignDriverToVehicle("D002", "V002");
    
    tms.assignRouteToVehicle("R001", "V001");
    tms.assignRouteToVehicle("R002", "V002");
    tms.assignRouteToVehicle("R003", "V003");
    
    User* user1 = tms.findUser("F001");
    User* user2 = tms.findUser("S001");
    
    if (user1 != NULL) user1->makePayment();
    if (user2 != NULL) user2->makePayment();
    
    tms.bookSeat("F001", "V001", 5);
    tms.bookSeat("S001", "V001", 10);
    tms.bookSeat("F001", "V002", 7);
    tms.bookSeat("S001", "V003", 3);
    
    tms.displayAllUsers();
    tms.displayAllVehicles();
    tms.displayAllDrivers();
    tms.displayAllRoutes();
    
    tms.saveToFile();
    
    return 0;
}