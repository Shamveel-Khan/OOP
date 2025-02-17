#include <iostream>
using namespace std;

class skill {
    int id;
    string name;
    string description;
}

class sport {
    int name;
    int id;
    string description;
    skills requiredSkills;
}

class Mentor {
    int id;
    string name;
    sport sportsExpertise[30];
    int maxLearners;
    int studentCount;
    Student assignedLearner[30];

}

class Student {
    int id;
    string name;
    int age;
    sport sportInterest[10];
    Mentor mentorAssigned;

    public:
        void registerForMentorship(Mentor m) {
            if(m.studentCount < m.maxLearners) {
                mentorAssigned=m;
                m.studentCount++;
                m.assignedlearners[m.studentCount]=this;
            }
        }

}

int main() {

}