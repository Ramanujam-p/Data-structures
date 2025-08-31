#include<iostream>
#include<stack>
using namespace std;
struct node
{
    int d;
    node* n;
    node(int v):d(v),n(nullptr){}
};
class link
{
   public:
   node* h;
   link():h(nullptr){}
   void insert(int v)
   {
      node* a =new node(v);
      if(!h)
      {
        h = a;
        return;
      }
      node* t = h;
      while(t->n)
      {
        t = t->n;
      }
      t->n = a;
   }
   void display()
   {
    node* t = h;
    while(t)
    {
        cout<<t->d<<"->";
        t = t->n;
    }
    cout<<"NULL";
   }
   node* rlist(node* h)
   {
      if(!h) return nullptr;
      stack<node*> s;
      node* a = h;
      while(a)
      {
        s.push(a);
        a = a->n;
      }
      node* b = s.top();
      s.pop();
      node* c = b;
      while(!s.empty())
      {
        node* d = s.top();
        s.pop();
        c->n = d;
        c = d;
      }
      c->n = nullptr;
      return b;
   }
};
int main()
{
    link l;
    node* a = new node(10);
    node* b = new node(20);
    node* c = new node(30);
    node* d = new node(40);
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.display();
    cout<<endl;
    l.h = l.rlist(l.h);
    l.display();
}
