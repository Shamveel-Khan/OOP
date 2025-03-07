#include <iostream>
using namespace std;

class account
{
protected:
    int accountNumber;
    float balance;

public:
    account(int accNum, float bal) : accountNumber(accNum), balance(bal) {}

    void display()
    {
        cout << "....................\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "....................\n";
    }
};

class savingsAccount : protected account
{
    float interestRate;

public:
    savingsAccount(int accNum, float bal, float rate) : account(accNum, bal), interestRate(rate) {}

    void display()
    {
        cout << "....................\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Interest Rate: " << interestRate << endl;
        cout << "....................\n";
    }
};

class checkingAccount : protected account
{
    float overdraftLimit;

public:
    checkingAccount(int accNum, float bal, float limit) : account(accNum, bal), overdraftLimit(limit) {}

    void display()
    {
        cout << "....................\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Overdraft Limit: " << overdraftLimit << endl;
        cout << "....................\n";
    }
};

int main()
{
    savingsAccount s(101, 5000, 2.5);
    checkingAccount c(102, 3000, 1000);
    s.display();
    c.display();
    return 0;
}
