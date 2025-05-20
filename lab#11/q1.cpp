#include <iostream>
#include <exception>
#include <string>
using namespace std;

template <typename T>
class DimensionMismatchException : public exception
{
    string message;

public:
    DimensionMismatchException(T r1, T c1, T r2, T c2)
    {
        message = "DimensionMismatchException - Matrices must have same dimensions (" +
                  to_string(r1) + "x" + to_string(c1) + " vs " +
                  to_string(r2) + "x" + to_string(c2) + ")!";
    }

    const char* what() const throw()
    {
        return message.c_str();
    }
};

template <class T>
class Matrix
{
    int rows, cols;
    T data[10][10];

public:
    Matrix(int r = 0, int c = 0)
    {
        if (r > 10 || c > 10)
            throw invalid_argument("Matrix size exceeds limit (10x10)");
        rows = r;
        cols = c;
    }

    void input()
    {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    Matrix<T> add(Matrix<T>& other)
    {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException<int>(rows, cols, other.rows, other.cols);

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    void display()
    {
        cout << "Matrix result:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    try
    {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A.input();
        B.input();

        Matrix<int> C = A.add(B);
        C.display();
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

