#include <iostream>
using namespace std;

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for(int i=0;i<rows;i++) {
        matrix[i]=new int[cols];
    }
    return matrix;
}

void inputMatrix(int** matrix, int rows, int cols){
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cin>>matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void deallocateMatrix(int** matrix, int rows) {
    for(int i=0;i<rows;i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int choice;
    cout<<"enter rows of matrix 1"<<endl;
    int rows1;
    cin>>rows1;
    cout<<"enter columns of matrix 1"<<endl;
    int cols1;
    cin>>cols1;
    cout<<"enter rows of matrix 2"<<endl;
    int rows2;
    cin>>rows2;
    cout<<"enter columns of matrix 2"<<endl;
    int cols2;
    cin>>cols2;

    int** matrix1 = allocateMatrix(rows1, cols1);
    int** matrix2 = allocateMatrix(rows2, cols2);
    cout<<"enter matrix 1"<<endl;
    inputMatrix(matrix1, rows1, cols1);
    cout<<"enter matrix 2"<<endl;
    inputMatrix(matrix2, rows2, cols2);
    if(rows1==rows2 && cols1==cols2) {
        int** add = allocateMatrix(rows1,cols1);
        for(int i=0;i<rows1;i++) {
            for(int j=0;j<cols1;j++) {
                add[i][j]=matrix1[i][j]+matrix2[i][j];
            }
        }
        cout<<"the additon is:"<<endl;
        displayMatrix(add,rows1,cols1);
        int** subtract = allocateMatrix(rows1,cols1);
        for(int i=0;i<rows1;i++) {
             for(int j=0;j<cols1;j++) {
                subtract[i][j]=matrix1[i][j]-matrix2[i][j];
            }
        }
        cout<<"\n subtraction is:\n";
        displayMatrix(subtract,rows1,cols1);
        deallocateMatrix(add, rows1);
        deallocateMatrix(subtract, rows1);
    }
    deallocateMatrix(matrix1, rows1);
    deallocateMatrix(matrix2, rows2);
}
