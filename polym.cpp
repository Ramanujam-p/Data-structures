#include <iostream>
using namespace std;
class node
{
public:
    int coeff, exp;
    node *n;
    node(int c, int e) : coeff(c), exp(e), n(nullptr) {}
};
void insert(node *&h, int coeff, int exp)
{
    node *a = new node(coeff, exp);
    if (!h)
    {
        h = a;
        return;
    }
    node *t = h;
    while (t->n)
        t = t->n;
    t->n = a;
}
void display(node *h)
{
    if (!h)
    {
        cout << "empty polynomials cannot be printed";
        return;
    }
    node *t = h;
    while (t)
    {
        cout << t->coeff << "x^" << t->exp;
        if (t->n)
            cout << " + ";
        t = t->n;
    }
}
node *mul(node *p1, node *p2)
{
    node *res = nullptr;
    for (node *i = p1; i; i = i->n)
        for (node *j = p2; j; j = j->n)
            insert(res, i->coeff * j->coeff, i->exp + j->exp);
    return res;
}
void simplify(node *&h)
{
    for (node *i = h; i; i = i->n)
    {
        node *j = i;
        while (j->n)
        {
            if (i->exp == j->n->exp)
            {
                i->coeff += j->n->coeff;
                node *t = j->n;
                j->n = t->n;
                delete t;
            }
            else
                j = j->n;
        }
    }
}
int main()
{
    node *poly1 = nullptr, *poly2 = nullptr, *result = nullptr;
    int choice, coeff, exp;

    do
    {
        cout << "\n--- Polynomial Menu ---\n";
        cout << "1. Insert term in Polynomial 1\n";
        cout << "2. Insert term in Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Multiply Polynomials\n";
        cout << "6. Display Result\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter coefficient and exponent: ";
            cin >> coeff >> exp;
            insert(poly1, coeff, exp);
            break;
        case 2:
            cout << "Enter coefficient and exponent: ";
            cin >> coeff >> exp;
            insert(poly2, coeff, exp);
            break;
        case 3:
            cout << "Polynomial 1: ";
            display(poly1);
            break;
        case 4:
            cout << "Polynomial 2: ";
            display(poly2);
            break;
        case 5:
            result = mul(poly1, poly2);
            simplify(result);
            cout << "Polynomials multiplied successfully.\n";
            break;
        case 6:
            cout << "Result Polynomial: ";
            display(result);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}