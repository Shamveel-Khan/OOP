#include <iostream>
#include <string>
using namespace std;

class Mentor;

class Skill {
private:
    int skillID;
    string skillName;
    string description;
public:
    Skill(int id, string name, string desc) : skillID(id), skillName(name), description(desc) {}
    void showSkillDetails() {
        cout << "Skill ID: " << skillID << ", Name: " << skillName << ", Desc: " << description << endl;
    }
    void updateSkillDescription(string newDescription) {
        description = newDescription;
    }
    int getSkillID() { return skillID; }
    string getSkillName() { return skillName; }
};

class Sport {
private:
    int sportID;
    string name;
    string description;
    Skill* requiredSkills[10];
    int skillCount;
public:
    Sport(int id, string n, string desc) : sportID(id), name(n), description(desc), skillCount(0) {}
    void addSkill(Skill* s) {
        if (skillCount < 10) {
            requiredSkills[skillCount++] = s;
            cout << "Skill " << s->getSkillName() << " added to " << name << endl;
        }
    }
    void removeSkill(Skill* s) {
        for (int i = 0; i < skillCount; i++) {
            if (requiredSkills[i]->getSkillID() == s->getSkillID()) {
                for (int j = i; j < skillCount - 1; j++)
                    requiredSkills[j] = requiredSkills[j + 1];
                skillCount--;
                break;
            }
        }
    }
    int getSportID() { return sportID; }
    string getName() { return name; }
};

class Student {
private:
    int studentID;
    string name;
    int age;
    Sport* sportsInterests[5];
    int sportsCount;
    Mentor* mentorAssigned;
public:
    Student(int id, string n, int a) : studentID(id), name(n), age(a), sportsCount(0), mentorAssigned(nullptr) {}
    void registerForMentorship(Mentor* m);
    void viewMentorDetails();
    void updateSportsInterest(Sport* s) {
        if (sportsCount < 5) {
            sportsInterests[sportsCount++] = s;
            cout << s->getName() << " added to " << name << "'s interests" << endl;
        }
    }
    int getStudentID() { return studentID; }
    string getName() { return name; }
    void setMentorAssigned(Mentor* m) { mentorAssigned = m; }
    Mentor* getMentorAssigned() { return mentorAssigned; }
};

class Mentor {
private:
    int mentorID;
    string name;
    Sport* sportsExpertise[5];
    int expertiseCount;
    int maxLearners;
    Student* assignedLearners[10];
    int learnerCount;
public:
    Mentor(int id, string n, int max) : mentorID(id), name(n), expertiseCount(0), maxLearners(max), learnerCount(0) {}
    void addSportExpertise(Sport* s) {
        if (expertiseCount < 5) {
            sportsExpertise[expertiseCount++] = s;
            cout << s->getName() << " added to " << name << "'s expertise" << endl;
        }
    }
    void assignLearner(Student* s) {
        if (learnerCount >= maxLearners) {
            cout << "Cannot assign more learners. Maximum capacity reached." << endl;
            return;
        }
        for (int i = 0; i < learnerCount; i++) {
            if (assignedLearners[i]->getStudentID() == s->getStudentID()) {
                cout << s->getName() << " is already assigned to this mentor." << endl;
                return;
            }
        }
        assignedLearners[learnerCount++] = s;
        s->setMentorAssigned(this);
        cout << s->getName() << " has been assigned to mentor " << name << endl;
    }
    void removeLearner(Student* s) {
        for (int i = 0; i < learnerCount; i++) {
            if (assignedLearners[i]->getStudentID() == s->getStudentID()) {
                assignedLearners[i]->setMentorAssigned(nullptr);
                for (int j = i; j < learnerCount - 1; j++)
                    assignedLearners[j] = assignedLearners[j + 1];
                learnerCount--;
                cout << s->getName() << " has been removed from mentor " << name << endl;
                return;
            }
        }
        cout << "Student not found in assigned learners." << endl;
    }
    void viewLearners() {
        if (learnerCount == 0) {
            cout << name << " has no assigned learners." << endl;
            return;
        }
        cout << name << "'s assigned learners:" << endl;
        for (int i = 0; i < learnerCount; i++) {
            cout << (i+1) << ". " << assignedLearners[i]->getName() << endl;
        }
    }
    void provideGuidance() {
        cout << name << " is providing guidance to " << learnerCount << " learners." << endl;
    }
    int getMentorID() { return mentorID; }
    string getName() { return name; }
    Sport** getSportsExpertise() { return sportsExpertise; }
    int getExpertiseCount() { return expertiseCount; }
};

void Student::registerForMentorship(Mentor* m) {
    if (mentorAssigned != nullptr) {
        cout << name << " is already assigned to a mentor. Please unregister first." << endl;
        return;
    }
    m->assignLearner(this);
}

void Student::viewMentorDetails() {
    if (mentorAssigned == nullptr) {
        cout << name << " is not assigned to any mentor yet." << endl;
        return;
    }
    cout << "Mentor Details: ID: " << mentorAssigned->getMentorID() << ", Name: " << mentorAssigned->getName() << endl;
    cout << "Expertise in:" << endl;
    
    Sport** expertise = mentorAssigned->getSportsExpertise();
    int expertiseCount = mentorAssigned->getExpertiseCount();
    
    for (int i = 0; i < expertiseCount; i++) {
        cout << "- " << expertise[i]->getName() << endl;
    }
}

int main() {
    cout<<"\nSHAMVEEL KHAN\n24K-0962\n";
    Skill s1(1, "Forehand", "Tennis forehand");
    Skill s2(2, "Backhand", "Tennis backhand");
    
    Sport tennis(1, "Tennis", "Racket sport");
    tennis.addSkill(&s1);
    tennis.addSkill(&s2);
    
    Sport soccer(2, "Soccer", "Team sport");
    
    Mentor ali(1, "Ali", 3);
    ali.addSportExpertise(&tennis);
    
    Student saad(1, "Saad", 20);
    saad.updateSportsInterest(&tennis);
    
    Student khalid(2, "Khalid", 22);
    khalid.updateSportsInterest(&tennis);
    
    Student fatima(3, "Fatima", 19);
    fatima.updateSportsInterest(&tennis);
    
    Student omar(4, "Omar", 21);
    omar.updateSportsInterest(&tennis);
    
    saad.registerForMentorship(&ali);
    khalid.registerForMentorship(&ali);
    fatima.registerForMentorship(&ali);
    
    ali.viewLearners();
    
    omar.registerForMentorship(&ali);
    
    ali.removeLearner(&khalid);
    
    omar.registerForMentorship(&ali);
    
    ali.viewLearners();
    
    saad.viewMentorDetails();
    
    ali.provideGuidance();
    
    return 0;
}