#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file;
    file.open("vechicles.txt",ios::in);
    if(!file) {
        cerr<<"file not open!!";
        exit(1);
    }
    string line;
    while(getline(file,line)) {
        if(line[0]=='#' || line.empty()) {
            continue;
        }
        cout<<line<<endl;
    }
    file.close();
}