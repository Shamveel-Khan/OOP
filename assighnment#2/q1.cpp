#include <iostream>
#include <string>
using namespace std;

class person {
    protected:
        string id;
        string name;
        string assignedStop;
        bool feePaid;
    public:
        virtual void display() {
            cout<<"..................\n";
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Assigned Stop: "<<assignedStop<<endl;
        }
};

class Teacher : public person {  
    public:
        Teacher(string i, string n, string stop) {
            id = i;
            name = n;
            assignedStop = stop;
            feePaid = false;
        }
    
        void payFees(int monthsPaid) {
            if (monthsPaid >= 1) {
                feePaid = true;
                cout << name << " (Teacher) has paid fees for " << monthsPaid << " month(s).\n";
            } else {
                cout << "Invalid payment duration.\n";
            }
        }
    
        void recordAttendance() {
            if (feePaid) {
                cout << "Attendance recorded for " << name << endl;
            } else {
                cout << "Card inactive. Please pay fees." << endl;
            }
        }
    };
    

class Staff : public person {  
    public:
        Staff(string i, string n, string stop) {
            id = i;
            name = n;
            assignedStop = stop;
            feePaid = true; 
        }
        
        void recordAttendance() {
            cout << "Attendance recorded for " << name << " (Staff, Free Transport)\n";
        }
};
        

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

    bool operator==(const Route& other) const {
        if (routeId != other.routeId) return false;
        if (stopCount != other.stopCount) return false;

        for (int i = 0; i < stopCount; i++) {
            if (stops[i]->getName() != other.stops[i]->getName() ||
                stops[i]->getLocation() != other.stops[i]->getLocation()) {
                return false;
            }
        }
        return true;
    }
    
    void displayStops() {
        cout << "Route " << routeId << " stops:\n";
        for(int i = 0; i < stopCount; i++) {
            cout << stops[i]->getName() << " at " << stops[i]->getLocation() << endl;
        }
    }
};

class Student:private person {
private:
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
        Teacher** teachers;
        Staff** staffMembers;
        Route** routes;
        
        int studentCount, teacherCount, staffCount, routeCount;
        
        static const int MAX_STUDENTS = 100;
        static const int MAX_TEACHERS = 20;
        static const int MAX_STAFF = 20;
        static const int MAX_ROUTES = 10;
    
    public:
        TransportSystem() {
            students = new Student*[MAX_STUDENTS];
            teachers = new Teacher*[MAX_TEACHERS];
            staffMembers = new Staff*[MAX_STAFF];
            routes = new Route*[MAX_ROUTES];
            studentCount = teacherCount = staffCount = routeCount = 0;
        }
    
        ~TransportSystem() {
            for(int i = 0; i < studentCount; i++) delete students[i];
            for(int i = 0; i < teacherCount; i++) delete teachers[i];
            for(int i = 0; i < staffCount; i++) delete staffMembers[i];
            for(int i = 0; i < routeCount; i++) delete routes[i];
            delete[] students;
            delete[] teachers;
            delete[] staffMembers;
            delete[] routes;
        }
    
        void registerStudent(string id, string name, string stop) {
            if(studentCount < MAX_STUDENTS) {
                students[studentCount++] = new Student(id, name, stop);
                cout << "Student registered successfully\n";
            }
        }
    
        void registerTeacher(string id, string name, string stop) {
            if(teacherCount < MAX_TEACHERS) {
                teachers[teacherCount++] = new Teacher(id, name, stop);
                cout << "Teacher registered successfully\n";
            }
        }
    
        void registerStaff(string id, string name, string stop) {
            if(staffCount < MAX_STAFF) {
                staffMembers[staffCount++] = new Staff(id, name, stop);
                cout << "Staff registered successfully\n";
            }
        }
    
        void processCardTap(string personId) {
            for(int i = 0; i < studentCount; i++) {
                if(students[i]->getId() == personId) {
                    students[i]->recordAttendance();
                    return;
                }
            }
            for(int i = 0; i < teacherCount; i++) {
                if(teachers[i]->getId() == personId) {
                    teachers[i]->recordAttendance();
                    return;
                }
            }
            for(int i = 0; i < staffCount; i++) {
                if(staffMembers[i]->getId() == personId) {
                    staffMembers[i]->recordAttendance();
                    return;
                }
            }
            cout << "Person not found in the system\n";
        }
    };
    

    int main() {
        TransportSystem system;
        cout<<"\nShamveel Khan\n24k-0962\n";
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
    
        cout << "\nRegistering People:\n";
        system.registerStudent("S1", "Shamveel", "Stop1");
        system.registerTeacher("T1", "Dr. Ahmed", "Stop2");
        system.registerStaff("ST1", "Mr. Khan", "Stop3");
    
        cout << "\nTesting Card Taps (Before Fee Payment):\n";
        system.processCardTap("S1"); 
        system.processCardTap("T1"); 
        system.processCardTap("ST1");

        cout << "\nProcessing Fee Payments:\n";
        for(int i = 0; i < 1; i++) {
            if (system.students[i]->getId() == "S1") {
                system.students[i]->payFees();
            }
        }
        for(int i = 0; i < 1; i++) {
            if (system.teachers[i]->getId() == "T1") {
                system.teachers[i]->payFees(1);
            }
        }
    
        cout << "\nTesting Card Taps (After Fee Payment):\n";
        system.processCardTap("S1");  
        system.processCardTap("T1");  
        system.processCardTap("ST1");
    
        delete stop1;
        delete stop2;
        delete stop3;
        delete route1;
    
        return 0;
    }
    