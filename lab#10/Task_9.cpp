#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("log.txt", ios::in);

    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    char buffer[11];
    file.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Read (10 chars): " << buffer << endl;
    cout << "Current position after read(): " << file.tellg() << endl;

    string s;
    getline(file, s);
    cout << "Next line: " << s << endl;
    cout << "Position after getline(): " << file.tellg() << endl;

    getline(file, s);
    cout << "Another line: " << s << endl;
    cout << "Position after second getline(): " << file.tellg() << endl;

    file.close();
    return 0;
}