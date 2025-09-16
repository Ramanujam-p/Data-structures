#include<iostream>
using namespace std;
class node
{
    public:
    int d;
    node* n;
    node():n(nullptr){}
    node(int v):d(v),n(nullptr){}
    static node* reverse(node* h)
    {
        node* p = nullptr;
        node* n = nullptr;
        node* c = h;
        while(c)
        {
            node* n = c->n;
            c->n = p;
            p = c;
            c = n;
        }
        return p;
    }
    static void print(node* h)
    {
        while(h)
        {
            cout<<h->d<<" ";
            h = h->n;
        }
    }
};
int main()
{
    node* a = new node(10);
    a->n = new node(20);
    a->n->n = new node(30);
    a->n->n->n = new node(40);
    cout<<"Original List: ";
    node::print(a);
    cout<<endl;
    a = node::reverse(a);
    cout<<"Reversed List: ";
    node::print(a);
    return 0;
}
