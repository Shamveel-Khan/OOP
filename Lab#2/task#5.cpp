#include <iostream>
using namespace std;

int main() {
    cout<<"enter number of integers: "<<endl;
    int n;
    cin>>n;
    int* arr= new int[n];
    for(int i=0;i<n;i++) {
        cout<<"enter value# "<<i+1<<": ";
        cin>>arr[i];
    }
    int sum=0;
    cout<<"the values are:"<<endl;
    for(int i=0;i<n;i++) {
        cout<<*(arr+i)<<" ";
        sum+=*(arr+i);
    }
    cout<<"\nthe sum is: "<<sum;
}