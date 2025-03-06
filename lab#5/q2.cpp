#include <iostream>
using namespace std;

class student
{
    int id;
    string name;
    int *scores;
    int numberOfScores;

    public : 
    student(int i, string n)
    {
        id = i;
        name = n;
        int num;
        cout << "\nenter number of scores: ";
        cin >> num;
        scores = new int[num];
        numberOfScores = num;
        for (int i = 0; i < num; i++)
        {
            cout<<"enter score#"<<i+1<<" : ";
            cin >> scores[i];
        }
    }
    student(const student &std)
    {
        id = std.id;
        name = std.name;
        numberOfScores=std.numberOfScores;
        scores=new int [std.numberOfScores];
        for (int i = 0; i < std.numberOfScores; i++)
        {
            scores[i] = std.scores[i];
        }
    }
    void display()
    {
        cout << "..............................\n";
        cout << "ID: " << id << "\n";
        cout << "Name: " << name << endl;
        cout << "...Scores...\n";
        for (int i = 0; i < numberOfScores; i++)
        {
            cout << "Score # " << i + 1 << " : " << scores[i] << endl;
        }
        cout << "..............................\n";
    }
    ~student {
        delete [] scores;
    }
};

int main()
{
    student shamveel(962, "Shamveel");
    student shamveel2(shamveel);
    shamveel.display();
    shamveel2.display();
}