#include <iostream>
using namespace std;

struct student {
    string name;
    int roll;
    int marks[3];
};

int main() {
    int n;
    cout<<"enter number of students: ";
    cin>>n;
    
    student* std= new student[n];
    for(int i=0;i<n;i++) {
        cout<<"enter details of student# "<<i+1<<endl;
        cout<<"enter name: ";
        cin.ignore();
        getline(cin,std[i].name);
        cout<<"enter roll number: ";
        cin>>std[i].roll;
        cout<<"enter marks:"<<endl;
        for(int j=0;j<3;j++) {
            cin.ignore();
            cout<<"enter marks# "<<j+1<<": ";
            cin>>std[i].marks[j];
        }
    }
    double sum=0;
    cout<<"\ndisplaying averages: "<<endl;
    for(int i=0;i<n;i++) {
        sum=0;
        for(int j=0;j<3;j++) {
            sum+=std[i].marks[j];
        }
        cout<<"name: "<<std[i].name;
        cout<<", average: "<<sum/3.0<<endl;
    }  
    delete [] std;
}