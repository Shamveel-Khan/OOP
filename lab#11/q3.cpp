#include <iostream>
#include <exception>
using namespace std;

class InvalidTemperatureException : public exception
{
};

template <typename T>
T convertToFernheight(T temp)
{
    if (temp < -273.15)
    {
        throw InvalidTemperatureException();
    }
    T result1 = (temp * 9.0 / 5.0) + 32;
    return result1;
}

int main()
{
    try
    {
        cout << "Checking for temperature" << endl;
        double result = convertToFernheight(300);
        cout << "Fernheight: " << result << endl;
    }
    catch (const exception &e)
    {
        cout << "Exception Occured: " << e.what() << endl;
    }
}
