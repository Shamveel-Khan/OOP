#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int numStrings;
    cout << "Enter the number of strings: ";
    cin >> numStrings;
    string* strArray = new string[numStrings];
    cin.ignore(); 
    for (int i = 0; i < numStrings; i++) {
        cout << "Enter string #" << i + 1 << ": ";
        getline(cin, strArray[i]);
    }
    sort(strArray, strArray + numStrings);
    cout << "\nSorted Strings:\n";
    for (int i = 0; i < numStrings; i++) {
        cout << "String " << i + 1 << ": " << strArray[i] << endl;
    }
    delete[] strArray;
    return 0;
}
