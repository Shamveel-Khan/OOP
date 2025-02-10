#include <iostream>
using namespace std;

class fitnessTracker {
    string ownerName;
    int dailyGoal=100;
    int stepsTaken;
    public:
        void setDailyGoal(int num) {
            dailyGoal=num;
        } 
        void setOwnerName(string name) {
            ownerName=name;
        }
        int checkGoal() {
            if(stepsTaken >=dailyGoal) {
                return 1;
            }
            else {
                return 0;
            }
        }
        int caloriesBurned() {
            return 10 * stepsTaken;//10 is dummy value
        }
        void addSteps(int num) {
            stepsTaken += num;
        }
        void displayProgress() {
            cout<<"total steps taken are: "<<stepsTaken<<endl;
        }
};

int main() {
    int start=1;
    int choice;
    fitnessTracker tr1;
    tr1.setOwnerName("Shamveel Khan");
    while(start){
        cout<<"enter your choice:\n1.add steps\n2.calculate calories\n3.check goal\n4.set goal(default is 100)\n5.display steps taken\n6.Exit\n";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"steps to add: ";
                int steps;
                cin>>steps;
                tr1.addSteps(steps);
                break;
            case 2:
                cout<<"calories burned are: "<<tr1.caloriesBurned();
                cout<<endl;
                break;
            case 3:
                if(tr1.checkGoal()) {
                    cout<<"you have reached your daily goal!!";
                    cout<<endl;
                }
                else {
                    cout<<"you have not reached your daily goal"<<endl;
                }
                break;
            case 4:
                cout<<"enter daily goal: ";
                int goal;
                cin>>goal;
                tr1.setDailyGoal(goal);
                break;
            case 5:
                tr1.displayProgress();
                break;
            case 6:
                start=0;
                break;
            default:
                cout<<"invalid choice try again!!"<<endl;
        }
    }
}