#include <iostream>
using namespace std;

class ArrayList
{
private:
    int *arr;
    int capacity;
    int length;

    void resize()
    {
        capacity *= 2;
        int *newArr = new int[capacity];

        for (int i = 0; i < length; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
    }

public:
    ArrayList(int cap = 5)
    {
        capacity = cap;
        length = 0;
        arr = new int[capacity];
    }

    ~ArrayList()
    {
        delete[] arr;
    }

    void add(int value)
    {
        if (length == capacity)
            resize();

        arr[length] = value;
        length++;
    }

    void insert(int pos, int value)
    {
        if (pos < 0 || pos > length)
            return;

        if (length == capacity)
            resize();

        for (int i = length; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = value;
        length++;
    }

    void remove(int pos)
    {
        if (pos < 0 || pos >= length)
            return;

        for (int i = pos; i < length - 1; i++)
            arr[i] = arr[i + 1];

        length--;
    }

    int get(int pos)
    {
        if (pos < 0 || pos >= length)
            return -1;

        return arr[pos];
    }

    void set(int pos, int value)
    {
        if (pos < 0 || pos >= length)
            return;

        arr[pos] = value;
    }

    int size()
    {
        return length;
    }

    bool isEmpty()
    {
        return length == 0;
    }

    void print()
    {
        cout << "[ ";
        for (int i = 0; i < length; i++)
            cout << arr[i] << " ";
        cout << "]\n";
    }
};

int main()
{
    ArrayList list;

    list.add(10);
    list.add(20);
    list.add(30);

    list.print();

    list.insert(1, 99);
    list.print();

    list.remove(2);
    list.print();

    cout << "Element at 1 = " << list.get(1) << endl;
    cout << "Size = " << list.size() << endl;

    return 0;
}
