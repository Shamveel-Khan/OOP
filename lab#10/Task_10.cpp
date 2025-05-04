#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ifstream file("record.txt", ios::in);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    string s;
    getline(file, s);
    cout << file.tellg()<<endl;
    cout << s << endl;
    int r = file.tellg();
    file.seekg(ios :: beg);
    file.seekg(22 , ios :: beg);

    string record;
    getline(file, record);

    cout << "Third record:" << record << endl;
    file.close();
    return 0;
}