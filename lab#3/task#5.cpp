#include <iostream>
using namespace std;

class Playlist {
    string songList[100];
    int totalSongs=0;
    string CurrentSong;
    public:
        void addSongs(string name) {
            songList[totalSongs]=name;
            totalSongs++;
        }
        void playSong(string name) {
            int found=0;
            for(int i=0;i<totalSongs;i++) {
                if(name==songList[i]) {
                    found=1;
                }
            }
            if(found) {
                CurrentSong=name;
            }
            else {
                cout<<"Song not in list, First add!"<<endl;
            }
        }
        void displayPlaylist() {
            cout<<"\n---Song List---\n";
            for(int i=0;i<totalSongs;i++) {
                cout<<i+1<<": "<<songList[i]<<endl;
            }
            cout<<"\n";
        }
        void removeSong(string name) {
            int found=0;
            int index;
            for(int i=0;i<totalSongs;i++) {
                if(name==songList[i]) {
                    found=1;
                    index=i;
                }
            }
            if(found) {
                for(int i=index+1;i<totalSongs;i++) {
                    songList[i-1]=songList[i];
                }
                cout<<"Song removed Sucessfully"<<endl;
                totalSongs--;
            }
            else {
                cout<<"Song not found!!"<<endl;
            }
        }
};

int main() {
    int start=1;
    int choice;
    string tmp;
    Playlist sk;
    while(start) {
        cout<<"---Music Player---";
        cout<<"\n1.Add songs\n2.Remove Songs\n3.Play a Song\n4.Display List\n5.Exit\n";
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"enter song to add: ";
                cin>>tmp;
                sk.addSongs(tmp);
                break;
            case 2:
                cout<<"enter song to remove: ";
                cin>>tmp;
                sk.removeSong(tmp);
                break;
            case 3:
                cout<<"enter song to Play: ";
                cin>>tmp;
                sk.playSong(tmp);
                break;
            case 4:
                sk.displayPlaylist();
                break;
            case 5:
                start=0;
                break;
            default:
                cout<<"wrong choice try again!\n";
        }
    }
}