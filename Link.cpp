#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  node* next;
  node(int v):data(v),next(nullptr){}
};
class linkedlist
{
    private:
    node* head;
    public:
    linkedlist():head(nullptr){}
    void insertfirst(int v)
    {
        node* a = new node(v);
        a->next = head;
        head = a;
    }
    void insertlast(int v)
    {
     node* a = new node(v);
     if(head == nullptr)
     {
        head = a;
        return;
     }
     node *temp = head;
     while(temp->next!=nullptr)
        temp = temp->next;
     temp->next = a;
    }
    void insertatposition(int p , int v)
    {
        if(p<=0)
        {
            cout<<"out of bounds";
            return;
        }
        if(p==1) 
        {
            insertfirst(v);
            return;
        }
        node* temp = head;
        for(int i=1;i<p-1&&temp->next!=nullptr;i++)
            temp = temp->next;
        if(temp == nullptr)
        {
            cout<<"position out of bounds";
            return;
        }
        node* a = new node(v);
        a->next = temp->next;
        temp->next = a;
    }
    void insertbeforevalue(int t,int v)
    {
        if(head == nullptr)
        {
            cout<<"list is empty\n";
            return;
        }
        if(head->data==t)
        {
            insertfirst(v);
            return;
        }
        node* temp = head;
        while(temp->next!=nullptr && temp->next->data!=t)
         temp=temp->next;
        if(temp->next==nullptr)
        {
            cout<<"value not found\n";
            return;
        }
        node* a = new node(v);
        a->next = temp->next;
        temp->next = a;
    }
    void insertaftervalue(int t,int v)
    {
        node* temp = head;
        while(temp!=nullptr && temp->data!=t)
            temp = temp->next;
        if(temp==nullptr)
        {
            cout<<"value not found\n";
            return;
        }
        node* a = new node(v);
        a->next = temp->next;
        temp->next = a;
    }
    void delatfirst()
    {
        if(head == nullptr) return;
        node* temp = head;
        head = head->next;
        delete temp;
    }
    void delatlast()
    {
        if(head == nullptr){cout<<"list is empty";return;}
        if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
       node* temp = head;
       while(temp->next->next!=nullptr)
        temp = temp->next;
       delete temp->next;
       temp->next = nullptr; 
    }
    void delbypos(int p)
    {
        if(head == nullptr) 
        {
            cout<<"list is empty";
            return;
        }
        if(p<=0)
        {
            cout<<"position out of bounds";
            return;
        }
        if(p==1)
        {
        delatfirst();
        return;
        }
        node* temp = head;
        for(int i=1;i<p-1&&temp!=nullptr;i++)
         temp = temp->next;
        if(temp->next == nullptr || temp == nullptr) 
        {
            cout<<"position out of bounds";
            return;
        }
        node* a = temp->next;
        temp->next = a->next;
        delete a;
    }
    void delbyvalue(int v)
    {
        if(head == nullptr)
        { 
            cout<<"list is empty";   
            return;
        }
        if(head->data == v)
        {
        delatfirst();
        return;
        }
        node* temp = head;
        while(temp->next!=nullptr && temp->next->data!=v)
            temp = temp->next;
            if(temp->next==nullptr){
                cout<<"value not found";
                return;
            }
        node* a = temp->next;
        temp->next = a->next;
        delete a;
    }
    void delbeforevalue(int t)
    {
        if(head==nullptr || head->data == t)
        {
            cout<<"no node exists before this value\n";
            return;
        }
        if(head->next!=nullptr && head->next->data == t)
        {
            delatfirst();
            return;
        }
        node* temp = head;
        while(temp->next->next !=nullptr && temp->next->next->data!=t)
         temp = temp->next;
         if(temp->next->next == nullptr)
         {
            cout<<"value not found\n";
            return;
         }
         node* a = temp->next;
         temp->next = a->next;
         delete a;
    }
    void delaftervalue(int t)
    {
      node* temp = head;
      while(temp!=nullptr && temp->data!=t)
            temp = temp->next;
      if(temp==nullptr || temp->next == nullptr)
      {
        cout<<"no node exists after this value\n";
        return;
      }
      node* a = temp->next;
      temp->next = a->next;
      delete a;
    }
    void search(int v)
    {
        node* temp = head;
        int p = 1;
        bool a = false;
        while(temp!=nullptr)
        {
            if(temp->data==v)
            {
                cout<<v<<" found at position "<<p<<"\n";
                a = true;
                break; 
            }
           temp = temp->next;
            p++;
        }
        if(a==false)
            cout<<"value not found";  
    }
    void display()
    {
        if(head == nullptr)
        {
            cout<<"list is empty";
            return;
        }
        node* temp = head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};
int main()
    {
        linkedlist l;
        int c,sc,v,p,t;
        do
        {
        cout<<"linked list menu\n1.insertion\n2.deletion\n3.search\n4.display\n5.exit\n";
        cout<<"enter the choice:";
        cin>>c;
        switch(c)
        {
        case 1:
            do{
            cout<<"1.insertion at first\n2.insertion at last \n3.insertion by position\n4.insert before value\n5.insert after value\n6.exit\n";
            cout<<"enter the choice:";
            cin>>sc;
            if(sc==1) 
            {
                cout<<"enter the value to insert:";
                cin>>v;
                l.insertfirst(v);
            }
            else if(sc==2)
            {
                cout<<"enter the value to insert:";
                cin>>v;
                l.insertlast(v);
            }
            else if(sc==3)
            {
                cout<<"enter the position and value to insert:";
                cin>>p>>v;
                l.insertatposition(p,v);
            }
            else if(sc==4)
            {
                cout<<"enter target value and value to insert:";
                cin>>t>>v;
                l.insertbeforevalue(t,v);
            }
            else if(sc==5)
            {
                cout<<"enter target value and value to insert:";
                cin>>t>>v;
                l.insertaftervalue(t,v);
            }
            else if(sc==6)
             break;
            else
                cout<<"invalid choice!";
        }while(sc!=6);
        break;
        case 2:
        do{
            cout<<"1.deletion at first\n2.deletion at last\n3.deletion by position\n4.deletion by value\n5.delete before value\n6.delete after value\n7.exit\n";
            cout<<"enter the choice:";
            cin>>sc;
            if(sc==1)
                l.delatfirst();
            else if(sc==2)
                l.delatlast();
            else if(sc==3)
            {
                cout<<"enter the position to delete:";
                cin>>p;
                l.delbypos(p);
            }
            else if(sc==4)
            {
                cout<<"enter the value to delete:";
                cin>>v;
                l.delbyvalue(v);
            }
            else if(sc==5)
            {
                cout<<"enter target value:";
                cin>>t;
                l.delbeforevalue(t);
            }
            else if(sc==6)
            {
                cout<<"enter target value:";
                cin>>t;
                l.delaftervalue(t);
            }
            else if(sc==7)
                break;
            else
                cout<<"invalid choice!";
        }while(sc!=7);
        break;
        case 3:
            cout<<"enter the element to search:";
            cin>>v;
            l.search(v);
            break;
        case 4:    
            l.display();
            break;
        case 5:
            cout<<"linked list ended successfully";
            break;
        default:
          cout<<"invalid main menu choice!\n";
    }
}  while(c!=5);
        return 0;
 }