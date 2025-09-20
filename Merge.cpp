#include<iostream>
using namespace std;
struct node
{
    int d;
    node* n;
    node():d(0),n(nullptr){}
    node(int v):d(v),n(nullptr){}
    node(int v,node* n):d(v),n(n){}
};
class Merge_Two_sorted_lists
{
    public:
    node* merge(node* l1 , node* l2)
    {
        node* a = new node(0);
        node* b = a;
        while(l1 && l2)
        {
            if(l1->d > l2->d)
            {
                b->n = l2;
                l2 = l2->n;
            }
            else
            {
                b->n = l1;
                l1 = l1->n;
            }
            b = b->n;
        }
        b->n = l1?l1:l2;
        node* h = a->n;
        delete a;
        return h;
    }
};
int main()
{
    Merge_Two_sorted_lists m;
    node* l1 = new node(1);
    l1->n = new node(2);
    l1->n->n = new node(4);
    node* l2 = new node(1);
    l2->n = new node(3);
    l2->n->n = new node(4);
    node* r = m.merge(l1,l2);
    while(r)
    {
        cout<<r->d;
        if(r->n) cout<<"->";
        r = r->n;
    }
    return 0;
}