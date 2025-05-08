#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("vechicles.txt");
    if (!file)
    {
        cerr << "file error!!\n";
        exit(1);
    }
    string line;
    while (getline(file, line))
    {
        if (line[0] == '#' || line.empty())
        {
            continue;
        }
        istringstream ss(line);
        char type;
        string name;
        int id;
        int year;
        ss >> type >> name >> id >> year;
        cout << type << " " << name << " " << id << " " << year << endl;
    }
}