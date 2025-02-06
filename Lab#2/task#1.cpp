#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

int main() {
    int n, filterYear;
    cout << "Enter the number of books: ";
    cin >> n;
    Book* books = new Book[n];

    for (int i= 0; i< n; i++) {
        cin.ignore();
        cout << "Enter details for book " << i + 1 << ":\n";
        cout << "Title: ";
        getline(cin, books[i].title);
        cout << "Author: ";
        getline(cin, books[i].author);
        cout << "Year: ";
        cin >> books[i].year;
    }

    cout << "Enter a year to filter books published after it: ";
    cin >> filterYear;

    cout << "Books published after " << filterYear << ":\n";
    for (int i= 0; i< n; i++) {
        if (books[i].year > filterYear) {
            cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
        }
    }

    delete[] books;
    return 0;
}
