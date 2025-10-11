#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int d;
    Node *n;
    Node(int v) : d(v), n(nullptr) {}
};

class LL
{
public:
    Node *h;
    LL() : h(nullptr) {}

    void insF(int v)
    {
        Node *a = new Node(v);
        a->n = h;
        h = a;
        cout << v << " inserted at front\n";
    }

    void insL(int v)
    {
        Node *a = new Node(v);
        if (!h)
        {
            h = a;
            cout << v << " inserted at last\n";
            return;
        }
        Node *t = h;
        while (t->n)
            t = t->n;
        t->n = a;
        cout << v << " inserted at last\n";
    }

    void insP(int p, int v)
    {
        if (p < 1)
        {
            cout << "Invalid position\n";
            return;
        }
        if (p == 1)
        {
            insF(v);
            return;
        }
        Node *a = new Node(v), *t = h;
        int c = 1;
        while (t && c < p - 1)
        {
            t = t->n;
            c++;
        }
        if (!t)
        {
            cout << "Position out of bounds\n";
            delete a;
            return;
        }
        a->n = t->n;
        t->n = a;
        cout << v << " inserted at position " << p << "\n";
    }

    void insB(int tar, int v)
    {
        if (!h)
            return;
        if (h->d == tar)
        {
            insF(v);
            return;
        }
        Node *a = new Node(v), *p = nullptr, *t = h;
        while (t && t->d != tar)
        {
            p = t;
            t = t->n;
        }
        if (!t)
        {
            cout << "Target not found\n";
            delete a;
            return;
        }
        p->n = a;
        a->n = t;
        cout << v << " inserted before " << tar << "\n";
    }

    void insA(int tar, int v)
    {
        Node *a = new Node(v), *t = h;
        while (t && t->d != tar)
            t = t->n;
        if (!t)
        {
            cout << "Target not found\n";
            delete a;
            return;
        }
        a->n = t->n;
        t->n = a;
        cout << v << " inserted after " << tar << "\n";
    }

    void delF()
    {
        if (!h)
            return;
        Node *t = h;
        h = h->n;
        delete t;
        cout << "First node deleted\n";
    }

    void delL()
    {
        if (!h)
            return;
        if (!h->n)
        {
            delete h;
            h = nullptr;
            cout << "Last node deleted\n";
            return;
        }
        Node *t = h;
        while (t->n->n)
            t = t->n;
        delete t->n;
        t->n = nullptr;
        cout << "Last node deleted\n";
    }

    void delV(int v)
    {
        if (!h)
            return;
        if (h->d == v)
        {
            delF();
            return;
        }
        Node *t = h;
        while (t->n && t->n->d != v)
            t = t->n;
        if (!t->n)
        {
            cout << "Value not found\n";
            return;
        }
        Node *tmp = t->n;
        t->n = tmp->n;
        delete tmp;
        cout << v << " deleted\n";
    }

    void delP(int p)
    {
        if (p < 1 || !h)
            return;
        if (p == 1)
        {
            delF();
            return;
        }
        Node *t = h;
        int c = 1;
        while (t->n && c < p - 1)
        {
            t = t->n;
            c++;
        }
        if (!t->n)
        {
            cout << "Position out of bounds\n";
            return;
        }
        Node *tmp = t->n;
        t->n = tmp->n;
        delete tmp;
        cout << "Node at position " << p << " deleted\n";
    }

    void delA(int tar)
    {
        Node *t = h;
        while (t && t->d != tar)
            t = t->n;
        if (!t || !t->n)
        {
            cout << "Target not found or no node after\n";
            return;
        }
        Node *tmp = t->n;
        t->n = tmp->n;
        delete tmp;
        cout << "Node after " << tar << " deleted\n";
    }

    void delB(int tar)
    {
        if (!h || h->d == tar || !h->n)
        {
            cout << "No node before target\n";
            return;
        }
        if (h->n->d == tar)
        {
            delF();
            return;
        }
        Node *t = h;
        while (t->n && t->n->n && t->n->n->d != tar)
            t = t->n;
        if (!t->n || !t->n->n)
        {
            cout << "Target not found\n";
            return;
        }
        Node *tmp = t->n;
        t->n = tmp->n;
        delete tmp;
        cout << "Node before " << tar << " deleted\n";
    }

    void revS()
    {
        stack<Node *> s;
        Node *t = h;
        while (t)
        {
            s.push(t);
            t = t->n;
        }
        h = s.top();
        s.pop();
        t = h;
        while (!s.empty())
        {
            t->n = s.top();
            s.pop();
            t = t->n;
        }
        t->n = nullptr;
        cout << "Reversed using stack\n";
    }

    void revP()
    {
        Node *p = nullptr, *c = h, *nxt;
        while (c)
        {
            nxt = c->n;
            c->n = p;
            p = c;
            c = nxt;
        }
        h = p;
        cout << "Reversed using pointers\n";
    }

    void sortI()
    {
        for (Node *i = h; i; i = i->n)
            for (Node *j = i->n; j; j = j->n)
                if (i->d > j->d)
                    swap(i->d, j->d);
        cout << "Sorted iteratively\n";
    }

    void sortR(Node *s)
    {
        if (!s || !s->n)
            return;
        Node *m = s;
        for (Node *t = s->n; t; t = t->n)
            if (t->d < m->d)
                m = t;
        swap(s->d, m->d);
        sortR(s->n);
    }

    void sortRWrap()
    {
        sortR(h);
        cout << "Sorted recursively\n";
    }

    void cnt()
    {
        int c = 0;
        Node *t = h;
        while (t)
        {
            c++;
            t = t->n;
        }
        cout << "Total nodes: " << c << "\n";
    }

    void merge(LL &l2)
    {
        if (!h)
        {
            h = l2.h;
            return;
        }
        Node *t = h;
        while (t->n)
            t = t->n;
        t->n = l2.h;
        cout << "Lists merged\n";
    }

    void disp()
    {
        if (!h)
        {
            cout << "List is empty\n";
            return;
        }
        Node *t = h;
        while (t)
        {
            cout << t->d;
            if (t->n)
                cout << "->";
            t = t->n;
        }
        cout << "\n";
    }
};

int main()
{
    LL l1, l2;
    int ch, v, p, tar;
    do
    {
        cout << "\n__MENU__\n1.insF 2.insL 3.insP 4.insB 5.insA\n6.delF 7.delL 8.delV 9.delP 10.delA 11.delB\n12.revS 13.revP 14.sortI 15.sortR 16.cnt\n17.merge 18.search 19.display 0.exit\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Val: ";
            cin >> v;
            l1.insF(v);
            break;
        case 2:
            cout << "Val: ";
            cin >> v;
            l1.insL(v);
            break;
        case 3:
            cout << "Val Pos: ";
            cin >> v >> p;
            l1.insP(p, v);
            break;
        case 4:
            cout << "Target Val: ";
            cin >> tar;
            cout << "Val to insert before: ";
            cin >> v;
            l1.insB(tar, v);
            break;
        case 5:
            cout << "Target Val: ";
            cin >> tar;
            cout << "Val to insert after: ";
            cin >> v;
            l1.insA(tar, v);
            break;
        case 6:
            l1.delF();
            break;
        case 7:
            l1.delL();
            break;
        case 8:
            cout << "Val to delete: ";
            cin >> v;
            l1.delV(v);
            break;
        case 9:
            cout << "Position to delete: ";
            cin >> p;
            l1.delP(p);
            break;
        case 10:
            cout << "Target Val: ";
            cin >> tar;
            l1.delA(tar);
            break;
        case 11:
            cout << "Target Val: ";
            cin >> tar;
            l1.delB(tar);
            break;
        case 12:
            l1.revS();
            break;
        case 13:
            l1.revP();
            break;
        case 14:
            l1.sortI();
            break;
        case 15:
            l1.sortRWrap();
            break;
        case 16:
            l1.cnt();
            break;
        case 17:
            cout << "Enter values for second list (end with -1): ";
            while (true)
            {
                cin >> v;
                if (v == -1)
                    break;
                l2.insL(v);
            }
            l1.merge(l2);
            break;
        case 18:
            cout << "Enter value to search: ";
            cin >> v;
            {
                Node *t = l1.h;
                int pos = 1;
                bool found = false;
                while (t)
                {
                    if (t->d == v)
                    {
                        cout << v << " found at position " << pos << "\n";
                        found = true;
                        break;
                    }
                    t = t->n;
                    pos++;
                }
                if (!found)
                    cout << v << " not found\n";
            }
            break;
        case 19:
            l1.disp();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (ch != 0);
    return 0;
}
