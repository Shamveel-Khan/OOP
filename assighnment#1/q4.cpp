#include <iostream>
#include <string>
using namespace std;

class Stop {
private:
    string name;
    string location;
public:
    Stop(string n, string l): name(n), location(l) {}
    string getName() { return name; }
    string getLocation() { return location; }
};

class Route {
private:
    string routeId;
    Stop** stops;
    int stopCount;
    static const int MAX_STOPS = 10;
public:
    Route(string id): routeId(id), stopCount(0) {
        stops = new Stop*[MAX_STOPS];
    }
    
    ~Route() {
        delete[] stops;
    }
    
    void addStop(Stop* stop) {
        if(stopCount < MAX_STOPS) {
            stops[stopCount++] = stop;
            cout << "Stop added to route " << routeId << endl;
        }
    }
    
    void displayStops() {
        cout << "Route " << routeId << " stops:\n";
        for(int i = 0; i < stopCount; i++) {
            cout << stops[i]->getName() << " at " << stops[i]->getLocation() << endl;
        }
    }
};

class Student {
private:
    string id;
    string name;
    bool feePaid;
    string assignedStop;
    static int totalStudents;
public:
    Student(string i, string n, string stop): 
        id(i), name(n), feePaid(false), assignedStop(stop) {
        totalStudents++;
    }
    
    string getId() { return id; }
    bool isFeesPaid() { return feePaid; }
    
    void payFees() {
        feePaid = true;
        cout << "Fees paid for student " << name << endl;
    }
    
    void recordAttendance() {
        if(feePaid) {
            cout << "Attendance recorded for " << name << endl;
        } else {
            cout << "Card inactive. Please pay fees." << endl;
        }
    }
    
    void display() {
        cout << "Student: " << name << " (ID: " << id << ")\n"
             << "Stop: " << assignedStop << "\n"
             << "Fees Status: " << (feePaid ? "Paid" : "Unpaid") << endl;
    }
};

int Student::totalStudents = 0;

class TransportSystem {
private:
    Student** students;
    Route** routes;
    int studentCount;
    int routeCount;
    static const int MAX_STUDENTS = 100;
    static const int MAX_ROUTES = 10;
    
public:
    TransportSystem() {
        students = new Student*[MAX_STUDENTS];
        routes = new Route*[MAX_ROUTES];
        studentCount = routeCount = 0;
    }
    
    ~TransportSystem() {
        for(int i = 0; i < studentCount; i++) delete students[i];
        for(int i = 0; i < routeCount; i++) delete routes[i];
        delete[] students;
        delete[] routes;
    }
    
    void registerStudent(string id, string name, string stop) {
        if(studentCount < MAX_STUDENTS) {
            students[studentCount++] = new Student(id, name, stop);
            cout << "Student registered successfully\n";
        }
    }
    
    void addRoute(Route* route) {
        if(routeCount < MAX_ROUTES) {
            routes[routeCount++] = route;
        }
    }
    
    void processCardTap(string studentId) {
        for(int i = 0; i < studentCount; i++) {
            if(students[i]->getId() == studentId) {
                students[i]->recordAttendance();
                return;
            }
        }
        cout << "Student not found\n";
    }
    
    void displayAllStudents() {
        for(int i = 0; i < studentCount; i++) {
            students[i]->display();
            cout << endl;
        }
    }
};

int main() {
    TransportSystem system;
    
    cout << "=== FAST Transportation System Demo ===\n\n";
    
    Stop* stop1 = new Stop("Stop1", "Location A");
    Stop* stop2 = new Stop("Stop2", "Location B");
    Stop* stop3 = new Stop("Stop3", "Location C");
    
    Route* route1 = new Route("R1");
    route1->addStop(stop1);
    route1->addStop(stop2);
    route1->addStop(stop3);
    
    cout << "\nDisplaying Route Information:\n";
    route1->displayStops();
    
    cout << "\nRegistering Students:\n";
    system.registerStudent("S1", "Shamveel", "Stop1");
    system.registerStudent("S2", "Moiz", "Stop2");
    system.registerStudent("S3", "Usman", "Stop3");
    
    cout << "\nInitial Student Status:\n";
    system.displayAllStudents();
    
    cout << "\nTesting Card Taps (Before Fee Payment):\n";
    system.processCardTap("S1");
    system.processCardTap("S2");
    
    cout << "\nProcessing Fee Payments:\n";
    Student* student1 = new Student("S1", "Shamveel", "Stop1");
    student1->payFees();
    
    cout << "\nTesting Card Taps (After Fee Payment):\n";
    system.processCardTap("S1");
    
    cout << "\nInvalid Card Tap Test:\n";
    system.processCardTap("S99");
    
    delete stop1;
    delete stop2;
    delete stop3;
    delete route1;
    delete student1;
    
    return 0;
}