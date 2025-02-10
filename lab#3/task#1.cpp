#include <iostream>
using namespace std;

class Wallet {
    string ownerName;
    int accountBalance;
    string transactionHistory=" ";
    public: 
        void setOwnerName(string name) {
            ownerName=name;
        }
        void addMoney(int num) {
            accountBalance+= num;
            transactionHistory += "\nadded pkr: " + std::to_string(num) + ".\n";
        } 
        void spendMoney(int num) {
            accountBalance-=num;
            transactionHistory += "\nsubtracted pkr: " + std::to_string(num) + ".\n";
        }
        void displayHistory() {
            cout<<transactionHistory;
        }
};

int main() {
    Wallet shamveel;
    shamveel.setOwnerName("Shamveel Khan");
    int choice;
    int start=1;
    while(start) {
        cout<<"-----Wallet management system-----\n";
        cout<<"choose your option\n1.add money\n2.spend money\n3.display transaction history\n4.Exit\n";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"enter money to be added: ";
                int num;
                cin>>num;
                shamveel.addMoney(num);
                break;
            case 2:
                cout<<"enter money to spend: ";
                int num2;
                cin>>num2;
                shamveel.spendMoney(num2);
                break;
            case 3:
                shamveel.displayHistory();
                cout<<"\n";
                break;
            case 4:
                start=0;
                break;
            default:
                cout<<"invalid choice  try again!!\n";
                break;
        }
    }
}