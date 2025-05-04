#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream in("vehicle2.txt");
    if (!in) {
        cerr << "Error: Could not open file 'vehicles.txt'" << endl;
        return 1;
    }

    string str;
    while (getline(in, str)) {
        if (str.empty() || str[0] == '#') {
            continue;
        }
        istringstream ss(str);
        string type,rest;

        getline(ss, type, ',');
        getline (ss,rest);

        if (type =="AutonomousCar")
        {
            string sub = rest.substr(rest.find(":")+1, rest.find(",")-1);
            cout << "auto car version:"<<sub << endl;
        }else if (type =="Electric Vehicle")
        {
            string sub = rest.substr(rest.find(":")+1, rest.find(",")-1);
            cout << "electric car battery:"<<sub<<endl;
        }
    }
    in.close();
    return 0;
}