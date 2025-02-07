#include <iostream>
using namespace std;

int main() {
    int r,c;
    cout<<"input number of pointers inside array: ";
    cin>>r;
    cout<<"input number of elements for each pointer: ";
    cin>>c;
    int** arr= new int*[r];
    for(int i=0;i<r;i++) {
        arr[i]=new int[c];
    }
    cout<<"input the array: "<<endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<endl<<"the input was: "<<endl;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cout<<arr[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<r;i++) {
        delete [] arr[i];
    }
    delete [] arr;
}