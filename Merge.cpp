#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node():data(0),next(nullptr){}
    node(int v):data(v),next(nullptr){}
    node(int v ,node* next):data(v),next(next){}
};
class merge
{
    public:
    node* mtl(node* l1 , node* l2)
    {
        node* a = new node(0);
        node* b = a;
        while(l1 && l2)
        {
            if(l1->data > l2->data)
            {
                b->next = l2;
                l2 = l2->next;
            }
            else
            {
                b->next = l1;
                l1 = l1->next;
            }
            b = b->next;
        }
        b->next = l1?l1:l2;
        node* h = a->next;
        delete a;
        return h;
    }
};
int main()
{
    merge m;
    node* l1 = new node(1);
    l1->next = new node(3);
    l1->next->next = new node(4);
    node* l2 = new node(1);
    l2->next = new node(2);
    l2->next->next = new node(4);
    node* merged = m.mtl(l1,l2);
    while(merged)
    {
        cout<<merged->data;
        if(merged->next) cout<<"->";
        merged = merged->next;
    }
    return 0;
}