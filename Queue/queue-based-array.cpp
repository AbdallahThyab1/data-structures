#include <iostream>
using namespace std;

template <class T>
class CircularQueue
{
private:
    T* arr;
    int capacity;
    int frontIndex;
    int rearIndex;
    int count;

public:
    CircularQueue(int cap = 5)
    {
        capacity = cap;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    bool isFull() const
    {
        return count == capacity;
    }

    int size() const
    {
        return count;
    }

    void enqueue(T value)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    T front() const
    {
        if (isEmpty())
            throw runtime_error("Queue empty");

        return arr[frontIndex];
    }

    void print() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "[ ";
        for (int i = 0; i < count; i++)
        {
            int idx = (frontIndex + i) % capacity;
            cout << arr[idx] << " ";
        }
        cout << "]\n";
    }
};

int main()
{
    CircularQueue<int> q(4);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print();
    cout << "Front = " << q.front() << endl;

    q.dequeue();
    q.print();

    q.enqueue(40);
    q.enqueue(50);

    q.print();
    cout << "Is Full? " << q.isFull() << endl;

    return 0;
}
