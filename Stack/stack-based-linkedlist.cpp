#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(T value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node *topNode;
    int count;

public:
    Stack()
    {
        topNode = nullptr;
        count = 0;
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    int size() const
    {
        return count;
    }

    void push(T value)
    {
        Node *newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    T top() const
    {
        if (isEmpty())
            throw runtime_error("Stack empty");

        return topNode->data;
    }
};

int main()
{
    Stack<int> s;

    s.push(5);
    s.push(10);
    s.push(20);

    cout << "Top = " << s.top() << endl;
    cout << "Size = " << s.size() << endl;

    s.pop();
    cout << "Top after pop = " << s.top() << endl;

    while (!s.isEmpty())
    {
        cout << "Removing " << s.top() << endl;
        s.pop();
    }

    return 0;
}
