#include <iostream>
using namespace std;
class node
{
public:
    int d;
    node *n;
    node(int v) : d(v), n(nullptr) {}
};
class queue
{
public:
    node *front, *rear;
    queue() : front(nullptr), rear(nullptr) {}
    bool isempty()
    {
        return front == nullptr;
    }
    void enqueue(int v)
    {
        node *a = new node(v);
        if (isempty())
            front = rear = a;
        rear->n = a;
        rear = a;
        cout << v << " enqueued into the queue\n";
    }
    void dequeue()
    {
        if (isempty())
        {
            cout << "queue underflow,cannot dequeue from the empty queue";
            return;
        }
        cout << front->d << " dequeue from the queue ";
        node *t = front;
        front = front->n;
        delete t;
        if (front == nullptr)
            rear = nullptr;
    }
    void peek()
    {
        if (isempty())
        {
            cout << "queue is empty\n";
            return;
        }
        cout << "Front element is: " << front->d << "\n";
    }

    void display()
    {
        if (isempty())
        {
            cout << "queue is empty\n";
            return;
        }
        node *t = front;
        cout << "Queue elements (front to rear): ";
        while (t)
        {
            cout << t->d << " ";
            t = t->n;
        }
        cout << "\n";
    }
};

int main()
{
    queue q;
    int choice, value;

    do
    {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
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