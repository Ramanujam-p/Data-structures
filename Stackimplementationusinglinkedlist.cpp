#include<iostream>
using namespace std;
class node
{
    public:
    int d;
    node* n;
    node(int v):d(v),n(nullptr){}
};
class Stack
{
    private:
    node* t;
    public:
    Stack():t(nullptr){}
    void push(int v)
    {
      node* a = new node(v);
      a->n = t;
      t = a;
      cout<<v<<" pushed into the stack";
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"stack underflow cannot pop!";
            return;
        }
        node* temp = t;
        cout<<t->d<<" popped from the stack";
        t = t->n;
        delete temp;
    }
    void display()
    {
        if(isempty())
        {
            cout<<"stack is empty!";
            return;
        }
        node* temp = t;
        while(temp!=nullptr)
        {
            cout<<temp->d<<" ";
            temp = temp->n;
        }
    }
    void peek()
    {
        if(isempty())
        {
            cout<<"stack is empty!";
            return;
        }
        cout<<"t element is:"<<t->d;
    }
    bool isempty()
    {
        return t==nullptr;
    }
};
int main()
{
    Stack s;
    int c,v;
    do
    {
        cout<<"\n1.push\n2.pop\n3.peek\n4.display\n5.exit\nenter the choice:";
        cin>>c;
        if(c==1)
        {
            cout<<"enter the value to push:";
            cin>>v;
            s.push(v);
        }
        else if(c==2)
        {
            s.pop();
        }
        else if(c==3)
        {
            s.peek();
        }
        else if(c==4)
        {
            s.display();
        }
        else if(c==5)
        {
            cout<<"exited successfully";
            break;
        }
        else
            cout<<"invalid choice";
    }while(c!=5);
}
