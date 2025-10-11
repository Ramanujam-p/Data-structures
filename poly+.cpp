#include <iostream>
using namespace std;
class node
{
public:
    int coeff, exp;
    node *n;
    node(int c, int p) : coeff(c), exp(p), n(nullptr) {}
};
void insert(node *&h, int coeff, int exp)
{
    node *a = new node(coeff, exp);
    if (!h)
    {
        h = a;
        return;
    }
    else
    {
        node *t = h;
        while (t->n)
            t = t->n;
        t->n = a;
    }
}
void display(node *h)
{
    if (!h)
    {
        cout << "polynomial is empty, cannot display\n";
        return;
    }
    while (h)
    {
        cout << h->coeff << "x^" << h->exp;
        if (h->n)
            cout << " + ";
        h = h->n;
    }
    cout << endl;
}
node *add(node *p1, node *p2)
{
    node *res = nullptr;
    while (p1 && p2)
    {
        if (p1->exp == p2->exp)
        {
            insert(res, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->n;
            p2 = p2->n;
        }
        else if (p1->exp > p2->exp)
        {
            insert(res, p1->coeff, p1->exp);
            p1 = p1->n;
        }
        else
        {
            insert(res, p2->coeff, p2->exp);
            p2 = p2->n;
        }
    }
    while (p1)
    {
        insert(res, p1->coeff, p1->exp);
        p1 = p1->n;
    }
    while (p2)
    {
        insert(res, p2->coeff, p2->exp);
        p2 = p2->n;
    }
    return res;
}
int main()
{
    node *p1 = nullptr, *p2 = nullptr, *res = nullptr;
    int choice, coeff, exp;
    do
    {
        cout << "\n--- Polynomial Addition Menu ---\n";
        cout << "1. Insert term into Polynomial 1\n";
        cout << "2. Insert term into Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Display Result\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter coefficient and exp: ";
            cin >> coeff >> exp;
            insert(p1, coeff, exp);
            break;
        case 2:
            cout << "Enter coefficient and exp: ";
            cin >> coeff >> exp;
            insert(p2, coeff, exp);
            break;
        case 3:
            cout << "Polynomial 1: ";
            display(p1);
            break;
        case 4:
            cout << "Polynomial 2: ";
            display(p2);
            break;
        case 5:
            res = add(p1, p2);
            cout << "Polynomials added successfully.\n";
            break;
        case 6:
            cout << "Resultant Polynomial: ";
            display(res);
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}