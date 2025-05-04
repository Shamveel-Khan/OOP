#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main (){
    ifstream in("vechicles.txt");
    if (!in){
        return 1;
    }
    string str ;
    while(getline(in, str)){
        if (str.empty() || str[0] == '#') {
            continue;
        }
        istringstream ss (str);
        char type;
        string name;
        int id;
        int year;
        ss >> type >> name >> id >> year;
        cout << id<<" " << name<<" "  << type << year << endl;
    }
    in.close(); 
    return 0;
}