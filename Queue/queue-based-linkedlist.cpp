#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T v)
        {
            data = v;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue()
    {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    ~Queue()
    {
        while (!isEmpty())
            dequeue();
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    int size() const
    {
        return count;
    }

    void enqueue(T value)
    {
        Node* newNode = new Node(value);

        if (isEmpty())
            frontNode = rearNode = newNode;
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }

        count++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == nullptr)
            rearNode = nullptr;

        delete temp;
        count--;
    }

    T front() const
    {
        if (isEmpty())
            throw runtime_error("Queue empty");

        return frontNode->data;
    }

    void print() const
    {
        Node* cur = frontNode;

        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "[ ";
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }
};

int main()
{
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.print();

    cout << "Front = " << q.front() << endl;

    q.dequeue();
    q.print();

    q.enqueue(40);
    q.print();

    while (!q.isEmpty())
    {
        cout << "Removing " << q.front() << endl;
        q.dequeue();
    }

    return 0;
}
