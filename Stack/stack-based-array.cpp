#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T* arr;
    int capacity;
    int topIndex;

    void resize()
    {
        capacity *= 2;
        T* newArr = new T[capacity];

        for (int i = 0; i <= topIndex; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
    }

public:
    Stack(int cap = 10)
    {
        capacity = cap;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    int size() const
    {
        return topIndex + 1;
    }

    void push(T value)
    {
        if (topIndex + 1 == capacity)
            resize();

        arr[++topIndex] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        topIndex--;
    }

    T top() const
    {
        if (isEmpty())
            throw runtime_error("Stack empty");

        return arr[topIndex];
    }
};

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

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
