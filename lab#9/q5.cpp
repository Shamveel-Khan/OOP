#include <iostream>
#include <string>

using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string trackingNumber, double weight) : trackingNumber(trackingNumber), weight(weight) {}
    
    virtual int estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    
    string getTrackingNumber() const { return trackingNumber; }
    double getWeight() const { return weight; }
};

class AirFreight : public Shipment {
private:
    string departureAirport;
    string arrivalAirport;
    int priority;

public:
    AirFreight(string trackingNumber, double weight, string departureAirport, string arrivalAirport, int priority) 
        : Shipment(trackingNumber, weight), departureAirport(departureAirport), 
        arrivalAirport(arrivalAirport), priority(priority) {}
    
    int estimateDeliveryTime() override {
        int baseTime = 24;
        if (priority == 1) {
            baseTime -= 10;
        } else if (priority == 3) {
            baseTime += 24;
        }
        
        if (weight > 50) {
            baseTime += 12;
        }
        
        return baseTime;
    }
    
    void showDetails() override {
        cout << "AIR FREIGHT SHIPMENT" << endl;
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Route: " << departureAirport << " → " << arrivalAirport << endl;
        cout << "Priority Level: " << priority << " (" << (priority == 1 ? "Express" : priority == 2 ? "Standard" : "Economy") << ")" << endl;
        cout << "Estimated Delivery Time: " << estimateDeliveryTime() << " hours" << endl;
        cout << "Special Handling: " << (weight > 20 ? "Required" : "Not Required") << endl;
    }
};

class GroundShipment : public Shipment {
private:
    string originCity;
    string destinationCity;
    double distance;
    bool isExpress;

public:
    GroundShipment(string trackingNumber, double weight, string originCity, string destinationCity, double distance, bool isExpress) 
        : Shipment(trackingNumber, weight), originCity(originCity), destinationCity(destinationCity), 
        distance(distance), isExpress(isExpress) {}
    
    int estimateDeliveryTime() override {
        int baseTime = distance / 50;
        
        baseTime += 12;
        
        if (isExpress) {
            baseTime = baseTime * 0.7;
        }
        
        if (weight > 100) {
            baseTime += 24;
        } else if (weight > 50) {
            baseTime += 12;
        }
        
        return baseTime;
    }
    
    void showDetails() override {
        cout << "GROUND SHIPMENT" << endl;
        cout << "Tracking Number: " << trackingNumber << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Route: " << originCity << " to " << destinationCity << " (" << distance << " km)" << endl;
        cout << "Service Type: " << (isExpress ? "Express" : "Standard") << endl;
        cout << "Estimated Delivery Time: " << estimateDeliveryTime() << " hours" << endl;
        cout << "Handling Requirements: " << (weight > 75 ? "Heavy load equipment needed" : "Standard handling") << endl;
    }
};

int main() {
    Shipment* shipments[4];
    
    shipments[0] = new AirFreight("AIR-Shamveel", 15.5, "KHI", "DXB", 1);
    shipments[1] = new AirFreight("AIR-Usman", 65.0, "ISL", "LHR", 3);
    shipments[2] = new GroundShipment("GND-Moiz", 45.0, "Karachi", "Lahore", 1200, true);
    shipments[3] = new GroundShipment("GND-Abdullah", 120.0, "Islamabad", "Peshawar", 180, false);
    
    for (int i = 0; i < 4; i++) {
        cout << "\n===================================" << endl;
        shipments[i]->showDetails();
        cout << "Delivery time estimate: " << shipments[i]->estimateDeliveryTime() << " hours" << endl;
    }
    
    for (int i = 0; i < 4; i++) {
        delete shipments[i];
    }
    
    return 0;
}