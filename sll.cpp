#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int d;
    node* n;
    node(int v):d(v),n(nullptr){}
};
class linkedlist
{
    public:
    node* h;
    linkedlist():h(nullptr){}
    void insert(int v)
    {
        node* a = new node(v);
        if(!h)
        {
            h = a;
            return;
        }
        node* t = h;
        while(t->n) t = t->n;
        t->n = a;
    }
    void display()
    {
        stack<node*> s;
        node* t = h;
        while(t)
        {
            s.push(t);
            t = t->n;
        }
        while(!s.empty())
        {
            cout<<s.top()->d<<"->";
            s.pop();
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    linkedlist l;
    node* a = new node(10);
    node* b = new node(20);
    node* c = new node(30);
    l.insert(10);
    l.insert(20);
    l.insert(30);
    cout<<"The elements are:";
    l.display();
    return 0;
}