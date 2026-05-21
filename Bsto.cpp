#include <iostream>
using namespace std;
class node
{
public:
    int d;
    node *l, *r;
    node(int v) : d(v), l(nullptr), r(nullptr) {}
};
class tree
{
public:
    node *root;
    tree() : root(nullptr) {}
    node *insert(node *a, int v)
    {
        if (!a)
            return new node(v);
        if (v < a->d)
            a->l = insert(a->l, v);
        if (v > a->d)
            a->r = insert(a->r, v);
        return a;
    }
    node *Inorder_successor(node *a)
    {
        while (a && a->l)
            a = a->l;
        return a;
    }
    node *del(node *a, int v)
    {
        if (!a)
            return a;
        if (v < a->d)
            a->l = del(a->l, v);
        else if (v > a->d)
            a->r = del(a->r, v);
        else
        {
            if (!a->l)
            {
                node *t = a->r;
                delete a;
                return t;
            }
            else if (!a->r)
            {
                node *t = a->l;
                delete a;
                return t;
            }
            else
            {
                node *t = Inorder_successor(a->r);
                a->d = t->d;
                a->r = del(a->r, t->d);
            }
        }
        return a;
    }
    bool search(node *a, int v)
    {
        if (!a)
            return false;
        if (a->d == v)
            return true;
        else if (v < a->d)
            return search(a->l, v);
        else
            return search(a->r, v);
    }
    void inorder(node *a)
    {
        if (!a)
            return;
        inorder(a->l);
        cout << a->d << " ";
        inorder(a->r);
    }
    void preorder(node *a)
    {
        if (!a)
            return;
        cout << a->d << " ";
        preorder(a->l);
        preorder(a->r);
    }
    void postorder(node *a)
    {
        if (!a)
            return;
        postorder(a->l);
        postorder(a->r);
        cout << a->d << " ";
    }
};
int main()
{
    tree t;
    int c, v;
    do
    {
        cout << "\n___BST menu___\n1.insertion\n2.deletion\n3.inorder\n4.preorder\n5.postorder\n6.search\n0.exit\nenter your choice:";
        cin >> c;
        if (c == 1)
        {
            cout << "enter the value to insert:";
            cin >> v;
            t.root = t.insert(t.root, v);
            cout << v << " is inserted";
        }
        else if (c == 2)
        {
            cout << "enter the value to delete:";
            cin >> v;
            t.root = t.del(t.root, v);
            cout << v << "is deleted";
        }
        else if (c == 3)
        {
            t.inorder(t.root);
        }
        else if (c == 4)
        {
            t.preorder(t.root);
        }
        else if (c == 5)
        {
            t.postorder(t.root);
        }
        else if (c == 6)
        {
            cout << "enter the value to search:";
            cin >> v;
            if (t.search(t.root, v))
                cout << v << " found in the bst";
            else
                cout << v << " not found";
        }
        else if (c == 0)
        {
            cout << "exited successfully";
            break;
        }
        else
            cout << "invalid choice try again";

    } while (c != 0);
}