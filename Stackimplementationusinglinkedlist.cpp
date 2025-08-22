#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int v):data(v),next(nullptr){}
};
class Stack
{
    private:
    node* top;
    public:
    Stack():top(nullptr){}
    void push(int v)
    {
      node* a = new node(v);
      a->next = top;
      top = a;
      cout<<v<<" pushed into the stack";
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"stack underflow cannot pop!";
            return;
        }
        node* temp = top;
        cout<<top->data<<" popped from the stack";
        top = top->next;
        delete temp;
    }
    void display()
    {
        if(isempty())
        {
            cout<<"stack is empty!";
            return;
        }
        node* temp = top;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void peek()
    {
        if(isempty())
        {
            cout<<"stack is empty!";
            return;
        }
        cout<<"top element is:"<<top->data;
    }
    bool isempty()
    {
        return top==nullptr;
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
