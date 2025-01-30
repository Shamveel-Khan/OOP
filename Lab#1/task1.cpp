#include <iostream>
#include <cstring>
using namespace std;

int main()  {
    int choice;
    int start =1;
    cout<<"enter your choice\n1.input names\n2.check attendance\n3.calculate donation\n4.display reverse names\n5.popularity chart\n6.Exit";
    cin>>choice;
    while(start){
        switch(choice) {
            case 1:
                int n=6,n1=6;
                do {
                    cout<<"enter number of names in event 1: [ < or = to 5] ";
                    cin >> n;
                }while(n > 5 && n >0);
                char event1[n][20];
                do {
                    cout<<"enter number of names in event 2: [ < or = to 5] ";
                    cin >> n1;
                }while(n1 > 5 && n1 >0);
                for(int i=0;i < n;i++) {
                    cout<<"name # "<< i+1;
                    cin>>event1[i];
                }
                char event2[n1][20];
                cout<< "enter 5 names for event#2"<<endl;
                for(int i=0;i < n2;i++) {
                    cout<<"name # "<< i+1;
                    cin>>event2[i];
                }
                cout<<"names for event 1 are:"<<endl;
                for(int i=0;i<n;i++) {
                    cout<<"name # "<<i+1<<": ";
                    cout<<event1[i]<<endl;
                }
                cout<<"names for event 2 are:"<<endl;
                for(int i=0;i<n2;i++) {
                    cout<<"name # "<<i+1<<": ";
                    cout<<event2[i]<<endl;
                }
                break;
            case 2:
            char temp[20];
            cout<<"enter name to search for: ";
            cin>> temp;
            for(int i=0;i<n;i++) {
                if(strcmp(temp,event1[i])==0) {
                    cout<<"this name is registered in event 1"<<endl;
                    break;
                }
            }
            for(int i=0;i<n2;i++) {
                if(strcmp(temp,event2[i])==0) {
                    cout<<"this name is registered in event 2"<<endl;
                    break;
                }
            }
            case 3:
                int sum=0;
                int tempo=0;
                cout<<"enter amounts donated for event#1: "<<endl;
                for(int i=0;i<n;i++) {
                    cout<<"enter amount danated by: "<<event1[i]<<endl;
                    cin>>tempo;
                    sum += tempo;
                }
                int sum2=0;
                for(int i=0;i<n2;i++) {
                    int tempo2=0;
                    cout<<"enter amount danated for event#2: "<<event2[i]<<endl;
                    cin>>tempo2;
                    sum2 += tempo2;
                }
                cout<<"total sum for event 1 is: "<<sum<<endl;
                cout<<"total sum for event 2 is: "<<sum2<<endl;
                cout<<"the reverse names for event #1 are: "<<endl;
                break;
            case 4:
                for(int i=0;i<n;i++) {
                    cout<<"the reverse for "<<event1[i]<<" is "<<strrev(event1[i])<<endl;
                }
                cout<<"the reverse names for event #2 are: "<<endl;
                for(int i=0;i<n2;i++) {
                    cout<<"the reverse for "<<event2[i]<<" is "<<strrev(event2[i])<<endl;
                }
                cout<<endl;
                break;
            case 5:
                cout<<"POPULARITY: "<<endl;
                cout<<"event#1: ";
                for(int i=0;i<n;i++) {
                    cout<<"#";
                }
                cout<<endl;
                cout<<"event#2: ";
                for(int i=0;i<n2;i++) {
                    cout<<"#";
                }
                break;
            case 6:
                start=0;
                break;
            default :
                cout<<"enter a right choice"
        }
    }
    return 0;
}