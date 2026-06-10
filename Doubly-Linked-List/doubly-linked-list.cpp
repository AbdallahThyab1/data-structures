#include <iostream>
using namespace std;

template <class T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;

        Node(T value)
        {
            data = value;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int count;

public:
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~DoubleLinkedList()
    {
        clear();
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
        Node* newNode = new Node(value);

        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        count++;
    }

    void pop()
    {
        if (isEmpty())
            return;

        Node* temp = tail;

        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        count--;
    }

    void insert(T value, int pos)
    {
        if (pos < 0 || pos > count)
        {
            cout << "Invalid position\n";
            return;
        }

        if (pos == count)
        {
            push(value);
            return;
        }

        Node* newNode = new Node(value);

        if (pos == 0)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            count++;
            return;
        }

        Node* cur = head;
        for (int i = 0; i < pos - 1; i++)
            cur = cur->next;

        newNode->next = cur->next;
        newNode->prev = cur;

        cur->next->prev = newNode;
        cur->next = newNode;

        count++;
    }

    void remove(int pos)
    {
        if (pos < 0 || pos >= count || isEmpty())
        {
            cout << "Invalid position\n";
            return;
        }

        if (pos == count - 1)
        {
            pop();
            return;
        }

        Node* cur = head;

        if (pos == 0)
        {
            head = head->next;
            head->prev = nullptr;
            delete cur;
            count--;
            return;
        }

        for (int i = 0; i < pos; i++)
            cur = cur->next;

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        delete cur;
        count--;
    }

    bool search(T key) const
    {
        Node* cur = head;

        while (cur)
        {
            if (cur->data == key)
                return true;
            cur = cur->next;
        }

        return false;
    }

    void clear()
    {
        Node* cur = head;

        while (cur)
        {
            Node* nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        count = 0;
    }
};
