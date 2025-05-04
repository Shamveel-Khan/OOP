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
        cout << str << endl;
    }
    in.close();
    return 0;
}