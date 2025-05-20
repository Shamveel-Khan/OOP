#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "A database error occurred.";
    }
};
class ConnectionFailedException : public DatabaseException
{
};

class QueryTimeoutException : public DatabaseException
{
};
template <typename T>
class DatabaseConnector
{
private:
    T databaseName;

public:
    DatabaseConnector(T dbName) : databaseName(dbName) {}

    void connect()
    {
        if (databaseName == "invalid_db")
            throw ConnectionFailedException();
        else if (databaseName == "slow_db")
            throw QueryTimeoutException();
        else
            cout << "Connected to " << databaseName << " successfully." << endl;
    }
};
int main()
{
    try
    {
        cout << "Attempting to connect to invalid" << endl;
        DatabaseConnector<string> connector1("invalid_db");
        connector1.connect();
    }
    catch (const ConnectionFailedException &e)
    {
        cout << "Caught ConnectionFailedException: " << e.what() << endl;
    }

    try
    {
        cout << "Attempting to connect to slow" << endl;
        DatabaseConnector<string> connector2("slow_db");
        connector2.connect();
    }
    catch (const DatabaseException &e)
    {
        cout << "Caught a general DatabaseException: " << e.what() << endl;
    }

    return 0;
}
