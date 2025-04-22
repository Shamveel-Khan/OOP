#include <iostream>
#include <string>

using namespace std;

class Course
{
protected:
    string courseCode;
    int credits;

public:
    Course(string courseCode, int credits) : courseCode(courseCode), credits(credits) {}

    virtual double calculateGrade() = 0;
    virtual void displayInfo() = 0;

    string getCourseCode() const { return courseCode; }
    int getCredits() const { return credits; }
};

class LectureCourse : public Course
{
private:
    int midtermWeight;
    int finalWeight;
    int assignmentWeight;
    double midtermScore;
    double finalScore;
    double assignmentScore;

public:
    LectureCourse(string courseCode, int credits, int midtermWeight, int finalWeight, int assignmentWeight)
        : Course(courseCode, credits), midtermWeight(midtermWeight), finalWeight(finalWeight),
          assignmentWeight(assignmentWeight), midtermScore(0), finalScore(0), assignmentScore(0) {}

    void setScores(double midterm, double final, double assignment)
    {
        midtermScore = midterm;
        finalScore = final;
        assignmentScore = assignment;
    }

    double calculateGrade() override
    {
        return (midtermScore * midtermWeight / 100) +
               (finalScore * finalWeight / 100) +
               (assignmentScore * assignmentWeight / 100);
    }

    void displayInfo() override
    {
        cout << "Lecture Course: " << courseCode << " (" << credits << " credits)" << endl;
        cout << "- Grading policy: Midterm " << midtermWeight << "%, Final "
             << finalWeight << "%, Assignments " << assignmentWeight << "%" << endl;
        cout << "- Type: Theory-based learning with lectures" << endl;
        cout << "- Assessment: Written exams and assignments" << endl;

        if (midtermScore > 0 || finalScore > 0 || assignmentScore > 0)
        {
            cout << "- Grade: " << calculateGrade() << "/100" << endl;
        }
    }
};

class LabCourse : public Course
{
private:
    int labWorkWeight;
    int projectWeight;
    int attendanceWeight;
    double labWorkScore;
    double projectScore;
    double attendanceScore;

public:
    LabCourse(string courseCode, int credits, int labWorkWeight, int projectWeight, int attendanceWeight)
        : Course(courseCode, credits), labWorkWeight(labWorkWeight), projectWeight(projectWeight),
          attendanceWeight(attendanceWeight), labWorkScore(0), projectScore(0), attendanceScore(0) {}

    void setScores(double labWork, double project, double attendance)
    {
        labWorkScore = labWork;
        projectScore = project;
        attendanceScore = attendance;
    }

    double calculateGrade() override
    {
        return (labWorkScore * labWorkWeight / 100) +
               (projectScore * projectWeight / 100) +
               (attendanceScore * attendanceWeight / 100);
    }

    void displayInfo() override
    {
        cout << "Lab Course: " << courseCode << " (" << credits << " credits)" << endl;
        cout << "- Grading policy: Lab Work " << labWorkWeight << "%, Project "
             << projectWeight << "%, Attendance " << attendanceWeight << "%" << endl;
        cout << "- Type: Practical hands-on learning" << endl;
        cout << "- Assessment: Lab performance and project completion" << endl;

        if (labWorkScore > 0 || projectScore > 0 || attendanceScore > 0)
        {
            cout << "- Grade: " << calculateGrade() << "/100" << endl;
        }
    }
};

int main()
{
    Course *courses[4];

    courses[0] = new LectureCourse("CS101-Shamveel", 3, 30, 50, 20);
    courses[1] = new LectureCourse("MATH202-Usman", 4, 25, 60, 15);
    courses[2] = new LabCourse("PHYS103-Moiz", 2, 50, 40, 10);
    courses[3] = new LabCourse("BIO205-Abdullah", 3, 45, 45, 10);

    ((LectureCourse *)courses[0])->setScores(85.5, 92.0, 78.5);
    ((LectureCourse *)courses[1])->setScores(75.0, 88.0, 90.0);
    ((LabCourse *)courses[2])->setScores(88.5, 92.0, 100.0);
    ((LabCourse *)courses[3])->setScores(79.0, 85.5, 95.0);

    for (int i = 0; i < 4; i++)
    {
        cout << "\n===================================" << endl;
        courses[i]->displayInfo();
        cout << "Final calculated grade: " << courses[i]->calculateGrade() << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete courses[i];
    }

    return 0;
}