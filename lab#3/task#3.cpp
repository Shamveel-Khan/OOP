#include <iostream>
using namespace std;

class library {
    string bookList[20];
    string borrowedBooks[20];
    string avaliableBook[20];
    int bookCount=0;
    int borrowedBooksCount=0;
    int avaliableBooksCount=0;
    public:
        void addBook(string name) {
            bookList[bookCount]=name;
            avaliableBook[avaliableBooksCount]=name;
            bookCount++;
            avaliableBooksCount++;
        }
        void borrowBook(string name) {
            int found=0;
            int found2=0;
            for(int i=0;i<bookCount;i++) {
                if(bookList[i]==name) {
                    for(int j=0;j<avaliableBooksCount;j++) {
                        if(avaliableBook[j]==name) {
                            avaliableBook[j]="";
                            borrowedBooks[borrowedBooksCount]=name;
                            borrowedBooksCount++;
                            avaliableBooksCount--;
                            found=1;
                        }
                    }
                    found2=1;
                }
            }
            if(found2 && found) {
                return;
            }
            else if(!found2) {
                cout<<"book not found!!"<<endl;
            }
            else {
                cout<<"book already borrowed!!";
            }
        }
        void returnBook(string name) {
            avaliableBooksCount++;
            avaliableBook[avaliableBooksCount]=name;
            borrowedBooksCount--;
        }
        void displayBookList() {
            cout<<"\n---list---\n";
            for(int i=0;i<bookCount;i++) {
                cout<<i+1<<": "<<bookList[i]<<endl;
            }
            cout<<endl;
        }
};

int main() {
    int start=1;
    int choice;
    library sk;
    string name;
    string name1;
    string name2;
    while(start) {
        cout<<"library management system!!"<<endl;
        cout<<"1.add book\n2.borrow book\n3.return book\n4.display all books\n5.Exit\n";
        cout<<"enter your choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"enter name of book: ";
                cin>>name;
                sk.addBook(name);
                break;
            case 2:
                cout<<"enter book to borrow: ";
                cin>>name1;
                sk.borrowBook(name1);
                break;
            case 3:
                cout<<"enter book to return: ";
                cin>>name2;
                sk.returnBook(name2);
                break;
            case 4:
                sk.displayBookList();
                break;
            case 5:
                start=0;
                break;
            default:
                cout<<"invalid choice enter again"<<endl;
                break;
        }
    }
}