#include <iostream>
#include <cstring>
using namespace std;

class Appartment {
    int id;
    string address;
    string* username;
public:
    Appartment(int id, string address) : id(id), address(address) {
        string name;
        cout << "Enter your name: ";
        getline(cin, name);
        username = new string(name);
    }

    Appartment(const Appartment& other) {
        id = other.id;
        address = other.address;
        username = other.username;
    }

    ~Appartment() {
        delete username;
    }

    void setUsername(string name) {
        *username = name;
    }

    void display() {
        cout << "\n....................\n";
        cout << "User ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "User Name: " << *username << endl;
        cout << ".......................\n";
    }
};

int main() {
    cout << "\nEnter ID for Apartment #1: ";
    int n1;
    cin >> n1;
    cin.ignore();

    cout << "Enter address for Apartment #1: ";
    string address;
    getline(cin, address);

    Appartment A1(n1, address);
    A1.display();

    Appartment A2 = A1;
    A2.display();

    return 0;
}
