#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// ===================== Array Class =====================

template <class T>
class Array
{
private:
    T *data;
    int capacity;
    int length;

public:
    Array(int size)
    {
        if (size <= 0)
            throw invalid_argument("Size must be positive");

        capacity = size;
        length = 0;
        data = new T[capacity];
    }

    ~Array()
    {
        delete[] data;
    }

    bool IsEmpty() const
    {
        return length == 0;
    }

    int Size() const
    {
        return length;
    }
    bool IsFull() const
    {
        return length == capacity;
    }

    void insert(int pos, T item)
    {
        if (length >= capacity)
            throw overflow_error("Array is full");

        if (pos < 0 || pos > length)
            throw out_of_range("Invalid position");

        for (int i = length; i > pos; i--)
        {
            data[i] = data[i - 1];
        }

        data[pos] = item;
        length++;
    }

    void push(T item)
    {
        if (length >= capacity)
            throw overflow_error("Array is full");

        data[length] = item;
        length++;
    }

    void Delete(int pos, T &item)
    {
        if (IsEmpty())
            throw underflow_error("Array is empty");

        if (pos < 0 || pos >= length)
            throw out_of_range("Invalid position");

        item = data[pos];

        for (int i = pos; i < length - 1; i++)
        {
            data[i] = data[i + 1];
        }

        length--;
    }

    void pop(T &item)
    {
        if (IsEmpty())
            throw underflow_error("Array is empty");

        item = data[length - 1];
        length--;
    }

    void retrieve(int pos, T &item) const
    {
        if (pos < 0 || pos >= length)
            throw out_of_range("Invalid position");

        item = data[pos];
    }

    void MakeArrayEmpty()
    {
        length = 0;
    }
};

// ===================== Employee Struct =====================

struct Employee
{
    int id;
    string name;
    double salary;
};

// طباعة كل الموظفين
void displayEmployees(Array<Employee> &arr)
{

    if (arr.IsEmpty())
    {
        cout << "No employees to display.\n";
        return;
    }

    cout << "\nID\tName\tSalary\n";
    cout << "---------------------------------\n";

    for (int i = 0; i < arr.Size(); i++)
    {
        Employee temp;
        arr.retrieve(i, temp);
        cout << temp.id << "\t"
             << temp.name << "\t"
             << temp.salary << endl;
    }
}

// ===================== Main =====================

int main()
{

    int capacity;
    cout << "Enter maximum number of employees: ";
    cin >> capacity;

    Array<Employee> employees(capacity);

    int choice = -1;

    while (choice != 0)
    {

        cout << "\n===== Employee Management =====\n";
        cout << "1. Add Employee\n";
        cout << "2. Insert Employee at Position\n";
        cout << "3. Delete Employee\n";
        cout << "4. Display Employees\n";
        cout << "5. Clear All\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        try
        {

            if (choice == 1)
            {
                if (employees.IsFull())
                {
                    cout << "Cannot add employee. Array is full.\n";
                }
                else
                {
                    Employee emp;

                    cout << "Enter ID: ";
                    cin >> emp.id;

                    cout << "Enter Name: ";
                    cin >> emp.name;

                    cout << "Enter Salary: ";
                    cin >> emp.salary;

                    employees.push(emp);
                    cout << "Employee added.\n";
                }
            }
            else if (choice == 2)
            {

                if (employees.IsFull())
                {
                    cout << "Cannot insert. Array is full.\n";
                }
                else
                {
                    Employee emp;
                    int pos;

                    cout << "Enter position: ";
                    cin >> pos;

                    cout << "Enter ID: ";
                    cin >> emp.id;

                    cout << "Enter Name: ";
                    cin >> emp.name;

                    cout << "Enter Salary: ";
                    cin >> emp.salary;

                    employees.insert(pos, emp);
                    cout << "Employee inserted.\n";
                }
            }

            else if (choice == 3)
            {
                int pos;
                Employee removed;

                cout << "Enter position to delete: ";
                cin >> pos;

                employees.Delete(pos, removed);
                cout << "Deleted employee: " << removed.name << endl;
            }

            else if (choice == 4)
            {
                displayEmployees(employees);
            }

            else if (choice == 5)
            {
                employees.MakeArrayEmpty();
                cout << "All employees removed.\n";
            }
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    cout << "Program ended.\n";
    return 0;
}
