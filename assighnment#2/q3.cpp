#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string id;
    int speed;
    int capacity;
    int energyEfficiency;
    static int totalDeliveries;

public:
    Vehicle(string id) : id(id) {}

    virtual void calculateRoute() = 0;
    virtual double estimateTime(double distance) = 0;

    virtual void command(string packageID)
    {
        totalDeliveries++;
        cout << "Basic delivery command for package: " << packageID << endl;
    }

    virtual void command(string packageID, string urgency)
    {
        totalDeliveries++;
        cout << "Urgent delivery command for package: " << packageID << endl;
    }

    static int getTotalDeliveries() { return totalDeliveries; }

    friend bool operator==(const Vehicle &a, const Vehicle &b);
    friend Vehicle *resolveConflict(Vehicle *a, Vehicle *b);
};

int Vehicle::totalDeliveries = 0;

bool operator==(const Vehicle &a, const Vehicle &b)
{
    return (a.speed == b.speed) &&
           (a.capacity == b.capacity) &&
           (a.energyEfficiency == b.energyEfficiency);
}

Vehicle *resolveConflict(Vehicle *a, Vehicle *b)
{
    int aScore = a->speed * a->energyEfficiency + a->capacity;
    int bScore = b->speed * b->energyEfficiency + b->capacity;
    return aScore >= bScore ? a : b;
}

class RamzanDrone : public Vehicle
{
public:
    RamzanDrone(string id) : Vehicle(id)
    {
        speed = 100;
        capacity = 10;
        energyEfficiency = 80;
    }

    void calculateRoute() override
    {
        cout << "Calculating aerial route for high-speed delivery" << endl;
    }

    double estimateTime(double distance) override
    {
        return distance / speed;
    }

    void command(string packageID, string urgency) override
    {
        if (urgency == "urgent")
        {
            cout << "Drone activating turbo mode for Iftar meal: " << packageID << endl;
            speed *= 2;
        }
        Vehicle::command(packageID, urgency);
    }
};

class RamzanTimeShip : public Vehicle
{
public:
    RamzanTimeShip(string id) : Vehicle(id)
    {
        speed = 80;
        capacity = 50;
        energyEfficiency = 70;
    }

    void calculateRoute() override
    {
        cout << "Verifying historical consistency for time travel" << endl;
    }

    double estimateTime(double distance) override
    {
        return distance / speed;
    }

    void command(string packageID, string urgency) override
    {
        if (urgency == "urgent")
        {
            cout << "TimeShip validating historical records for: " << packageID << endl;
        }
        Vehicle::command(packageID, urgency);
    }
};

class RamzanHyperPod : public Vehicle
{
public:
    RamzanHyperPod(string id) : Vehicle(id)
    {
        speed = 120;
        capacity = 1000;
        energyEfficiency = 90;
    }

    void calculateRoute() override
    {
        cout << "Navigating underground hyperloop network" << endl;
    }

    double estimateTime(double distance) override
    {
        return distance / speed;
    }
};

int main()
{
    cout<<"\nShamveel Khan\n24k-0962\n";

    RamzanDrone drone("DRONE");
    RamzanTimeShip timeship("TIMESHIP");
    RamzanHyperPod pod("POD");

    drone.command("IFTAR_MEAL1", "urgent");
    drone.command("IFTAR_MEAL2", "urgent");

    timeship.command("HISTORICAL_ITEM", "urgent");

    pod.calculateRoute();
    cout << "Estimated delivery time: " << pod.estimateTime(360) << " hours" << endl;

    Vehicle *result = resolveConflict(&drone, &pod);
    cout << "Conflict resolution winner: " << result->getTotalDeliveries() << endl;

    cout << "Total deliveries: " << Vehicle::getTotalDeliveries() << endl;

    return 0;
}