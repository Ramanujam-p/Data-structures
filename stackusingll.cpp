#include <iostream>
using namespace std;

class node
{
public:
    int d;
    node *n;
    node(int v) : d(v), n(nullptr) {}
};

class stack
{
public:
    node *top;
    stack() : top(nullptr) {}

    bool isempty()
    {
        return top == nullptr;
    }

    void push(int v)
    {
        node *a = new node(v);
        a->n = top;
        top = a;
        cout << v << " pushed into the stack\n";
    }

    void pop()
    {
        if (isempty())
        {
            cout << "stack underflow, cannot pop from empty stack\n";
            return;
        }
        cout << top->d << " popped from the stack\n";
        node *t = top;
        top = top->n;
        delete t;
    }

    void display()
    {
        if (isempty())
        {
            cout << "stack is empty\n";
            return;
        }
        node *t = top;
        cout << "Stack elements (top to bottom): ";
        while (t)
        {
            cout << t->d << " ";
            t = t->n;
        }
        cout << "\n";
    }

    void peek()
    {
        if (isempty())
        {
            cout << "stack is empty\n";
            return;
        }
        cout << "Top element is: " << top->d << "\n";
    }
};

int main()
{
    stack s;
    int choice, value;

    do
    {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
