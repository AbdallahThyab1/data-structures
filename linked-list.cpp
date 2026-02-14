#include <iostream>
#include <string>

using namespace std;

template <class T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(T value)
        {
            data = value;
            next = NULL;
        }
    };

    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
        clear();
    }

    bool isEmpty() const
    {
        return head == NULL;
    }

    int size() const
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void insertAtEnd(T value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void deleteNode(T key)
    {
        if (head == NULL)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == key)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted.\n";
            return;
        }

        Node *current = head;

        while (current->next != NULL && !(current->next->data == key))
            current = current->next;

        if (current->next == NULL)
        {
            cout << "Student not found.\n";
            return;
        }

        Node *temp = current->next;
        current->next = temp->next;
        delete temp;

        cout << "Student deleted.\n";
    }

    bool search(T key) const
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->data == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    void clear()
    {
        Node *temp;

        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() const
    {
        if (head == NULL)
        {
            cout << "No students to display.\n";
            return;
        }

        Node *temp = head;

        cout << "\nID\tName\tGPA\n";
        cout << "-----------------------------\n";

        while (temp != NULL)
        {
            cout << temp->data.id << "\t"
                 << temp->data.name << "\t"
                 << temp->data.gpa << endl;

            temp = temp->next;
        }
    }
};

// ===== Student Struct =====
struct Student
{
    int id;
    string name;
    double gpa;

    bool operator==(const Student &other) const
    {
        return id == other.id;
    }
};

// ===================== MAIN =====================
int main()
{
    LinkedList<Student> students;
    int choice = -1;

    while (choice != 0)
    {
        cout << "\n========== Student Management ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student by ID\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Display All Students\n";
        cout << "5. Number of Students\n";
        cout << "6. Clear All Students\n";
        cout << "0. Exit\n";
        cout << "========================================\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Student s;

            cout << "Enter ID: ";
            cin >> s.id;

            cout << "Enter Name: ";
            cin >> s.name;

            cout << "Enter GPA: ";
            cin >> s.gpa;

            students.insertAtEnd(s);
            cout << "Student added successfully.\n";
        }

        else if (choice == 2)
        {
            if (students.isEmpty())
            {
                cout << "No students to delete.\n";
            }
            else
            {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;

                students.deleteNode(Student{id, "", 0});
            }
        }

        else if (choice == 3)
        {
            if (students.isEmpty())
            {
                cout << "No students in system.\n";
            }
            else
            {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;

                if (students.search(Student{id, "", 0}))
                    cout << "Student exists in the list.\n";
                else
                    cout << "Student not found.\n";
            }
        }

        else if (choice == 4)
        {
            students.print();
        }

        else if (choice == 5)
        {
            cout << "Total students: " << students.size() << endl;
        }

        else if (choice == 6)
        {
            students.clear();
            cout << "All students removed.\n";
        }

        else if (choice == 0)
        {
            cout << "Exiting program...\n";
        }

        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
