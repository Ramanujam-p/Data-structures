#include<iostream>
#include<stack>
using namespace std;
struct node
{
    char d;
    node* r;
    node* l;
    node(char v):d(v),r(nullptr),l(nullptr){}
};
void preorder(node* root)
{
    if(!root) return;
    stack<node*> s;
    s.push(root);
    while(!s.empty())
    {
      node* a = s.top();
      s.pop();
      cout<<a->d<<" ";
      if(a->r) s.push(a->r);
      if(a->l) s.push(a->l); 
    }
}
int main()
{
    /*  A
      /   \
     B     C
   /   \
  D     E
     */
    node* a = new node('A');
    a->l    = new node('B');
    a->l->l = new node('D');
    a->r    = new node('C');
    a->l->r = new node('E');
    preorder(a);
    return 0;
}