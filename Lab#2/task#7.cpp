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

    if(cols1 == rows2) {
        int** product= allocateMatrix(rows1,cols2);
        for (int i = 0; i < rows1; i++) {     
            for (int j = 0; j < cols2; j++) { 
                product[i][j]=0;
                for (int k = 0; k < rows2; k++) { 
                    product[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        cout<<"\nthe product is:\n";
        displayMatrix(product,rows1,cols2);
        deallocateMatrix(matrix1,rows1);
        deallocateMatrix(matrix2,rows2);
        deallocateMatrix(product,rows1);
    }
    else {
        cout<<"multiplication is not possible";
    }
}