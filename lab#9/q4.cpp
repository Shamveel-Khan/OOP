#include <iostream>
#include <string>

using namespace std;

class WeatherSensor {
protected:
    string sensorId;
    string location;

public:
    WeatherSensor(string sensorId, string location) : sensorId(sensorId), location(location) {}
    
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    
    string getSensorId() const { return sensorId; }
    string getLocation() const { return location; }
};

class Thermometer : public WeatherSensor {
private:
    double temperature;
    double humidity;
    string unit;

public:
    Thermometer(string sensorId, string location, string unit = "Celsius") 
        : WeatherSensor(sensorId, location), temperature(0), humidity(0), unit(unit) {}
    
    void readData() override {
        temperature = 22.5 + (rand() % 10) - 5; 
        humidity = 50.0 + (rand() % 30);   
        
        cout << "Thermometer " << sensorId << " reading data from " << location << "..." << endl;
        cout << "Temperature reading: " << temperature << " " << unit << endl;
        cout << "Humidity reading: " << humidity << "%" << endl;
    }
    
    void displayReport() override {
        cout << "TEMPERATURE REPORT - " << location << " (ID: " << sensorId << ")" << endl;
        cout << "- Current temperature: " << temperature << " " << unit << endl;
        cout << "- Current humidity: " << humidity << "%" << endl;
        
        if (temperature > 25.0) {
            cout << "- Status: Above normal temperature for standard room" << endl;
        } else if (temperature < 20.0) {
            cout << "- Status: Below normal temperature for standard room" << endl;
        } else {
            cout << "- Status: Normal temperature range" << endl;
        }
    }
};

class Barometer : public WeatherSensor {
private:
    double pressure;
    double altitude;
    string pressureUnit;

public:
    Barometer(string sensorId, string location, string pressureUnit = "hPa") 
        : WeatherSensor(sensorId, location), pressure(0), altitude(0), pressureUnit(pressureUnit) {}
    
    void readData() override {
        pressure = 1013.25 + (rand() % 20) - 10; 
        altitude = 100 + (rand() % 50);         
        cout << "Barometer " << sensorId << " reading data from " << location << "..." << endl;
        cout << "Pressure reading: " << pressure << " " << pressureUnit << endl;
        cout << "Estimated altitude: " << altitude << " meters" << endl;
    }
    
    void displayReport() override {
        cout << "BAROMETRIC REPORT - " << location << " (ID: " << sensorId << ")" << endl;
        cout << "- Current pressure: " << pressure << " " << pressureUnit << endl;
        cout << "- Estimated altitude: " << altitude << " meters" << endl;
        
        // Simple pressure analysis
        if (pressure > 1020) {
            cout << "- Weather forecast: High pressure system - Likely fair weather" << endl;
        } else if (pressure < 1010) {
            cout << "- Weather forecast: Low pressure system - Potential for unsettled weather" << endl;
        } else {
            cout << "- Weather forecast: Normal pressure - Stable conditions likely" << endl;
        }
    }
};

int main() {
    WeatherSensor* sensors[4];
    
    sensors[0] = new Thermometer("THERM-Shamveel", "Rooftop");
    sensors[1] = new Thermometer("THERM-Usman", "Ground Level");
    sensors[2] = new Barometer("BARO-Moiz", "Weather Station");
    sensors[3] = new Barometer("BARO-Abdullah", "Observatory");
    
    for (int i = 0; i < 4; i++) {
        cout << "\n===================================" << endl;
        sensors[i]->readData();
        cout << "\n";
        sensors[i]->displayReport();
    }
    
    for (int i = 0; i < 4; i++) {
        delete sensors[i];
    }
    
    return 0;
}