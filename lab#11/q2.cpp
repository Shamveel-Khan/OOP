#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception
{
};

class QueueUnderflowException : public exception
{
};

template <typename T>
class Queue
{
private:
    T *data;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size)
    {
        capacity = size;
        data = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(const T &item)
    {
        if (isFull())
            throw QueueOverflowException();

        rear = (rear + 1) % capacity;
        data[rear] = item;
        count++;
    }

    T dequeue()
    {
        if (isEmpty())
            throw QueueUnderflowException();

        T item = data[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == capacity;
    }

    int size()
    {
        return count;
    }
};
int main()
{
    Queue<int> q(3);

    try
    {
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        cout << "Attempting to enqueue to a full queue" << endl;
        q.enqueue(4);
    }
    catch (const QueueOverflowException &e)
    {
        cout << "Caught QueueOverflowException: " << e.what() << endl;
        cout << "QueueOverflowException" << endl;
    }

    try
    {
        cout << "Dequeueing the items" << endl;
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
        cout << q.dequeue() << endl;
        cout << "Attempting to dequeue from an empty queue " << endl;
        q.dequeue();
    }
    catch (const QueueUnderflowException &e)
    {
        cout << "Caught QueueUnderflowException: " << e.what() << endl;
        cout << "QueueUnderflowException" << endl;
    }

    return 0;
}
