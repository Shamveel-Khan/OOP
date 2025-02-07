#include <iostream>
using namespace std;

int main() {
    int x,y,z;
    cout << "Enter the dimensions (x y z): ";
    cin >> x >> y >> z;

    int ***arr = new int**[x];
    for (int i=0; i<x; i++) {
        arr[i] = new int*[y];
        for (int j=0; j<y; j++) {
            arr[i][j] = new int[z];
        }
    }

    cout << "Enter the elements:\n";
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            for (int k=0; k<z; k++) {
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "3D Array:\n";
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            for (int k=0; k<z; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}