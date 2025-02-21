#include <iostream>
#include <string>
using namespace std;

class Student {
    static int nextID;
    string name;
    const int id;
    double balance;
    bool isActive;
    string assignedStop;
    int attendance;

public:
    Student(string n) : id(nextID++), name(n), balance(0), isActive(false), attendance(0) {}
    
    void payFee(double amount) { 
        balance += amount;
        if(balance >= 2500) isActive = true;
    }
    
    bool checkActive() const { return isActive; }
    string getStop() const { return assignedStop; }
    void setStop(string stop) { assignedStop = stop; }
    void addAttendance() { attendance++; }
    int getID() const { return id; }
};

int Student::nextID = 1000;

class BusStop {
    string name;
    Student** students;
    int capacity;
    int count;

public:
    BusStop(string n) : name(n), students(nullptr), capacity(0), count(0) {}
    
    void addStudent(Student* s) {
        if(count == capacity) {
            capacity = capacity ? capacity*2 : 1;
            Student** newArr = new Student*[capacity];
            for(int i = 0; i < count; i++) newArr[i] = students[i];
            delete[] students;
            students = newArr;
        }
        students[count++] = s;
        s->setStop(name);
    }
};

class Route {
    BusStop** stops;
    int stopCount;
    string routeName;

public:
    Route(string name) : routeName(name), stops(nullptr), stopCount(0) {}
    
    void addStop(BusStop* stop) {
        BusStop** newStops = new BusStop*[stopCount+1];
        for(int i = 0; i < stopCount; i++) newStops[i] = stops[i];
        newStops[stopCount++] = stop;
        delete[] stops;
        stops = newStops;
    }
};

class TransportSystem {
    Student** students;
    Route* currentRoute;
    int studentCount;
    int studentCapacity;

public:
    TransportSystem() : students(nullptr), studentCount(0), studentCapacity(0), currentRoute(nullptr) {}
    
    void registerStudent(string name) {
        if(studentCount == studentCapacity) {
            studentCapacity = studentCapacity ? studentCapacity*2 : 1;
            Student** newArr = new Student*[studentCapacity];
            for(int i = 0; i < studentCount; i++) newArr[i] = students[i];
            delete[] students;
            students = newArr;
        }
        students[studentCount++] = new Student(name);
    }

    void tapCard(int id) {
        for(int i = 0; i < studentCount; i++) {
            if(students[i]->getID() == id && students[i]->checkActive()) {
                students[i]->addAttendance();
                return;
            }
        }
    }
};

int main() {
    TransportSystem system;
    
    system.registerStudent("Shamveel");
    system.registerStudent("Moiz");

    Student* s1 = system.students[0];
    Student* s2 = system.students[1];

    s1->payFee(2500);
    s2->payFee(1000);

    BusStop stop1("Main Gate");
    stop1.addStudent(s1);
    
    Route r1("Campus Route");
    r1.addStop(&stop1);

    system.tapCard(s1->getID());
    system.tapCard(s2->getID());

    cout << "Shamveel's attendance: " << s1->attendance << endl;
    cout << "Moiz's active status: " << boolalpha << s2->checkActive() << endl;

    return 0;
}