//inorder traversal of a binary tree
#include<iostream>
struct node
{
    int d;
    node* l;
    node* r;
    node(int v):d(v),l(nullptr),r(nullptr){}
};
void inordertraversal(node* r)
{
    if(!r) return;
    inordertraversal(r->l);
    std::cout<<r->d<<" ";
    inordertraversal(r->r);
}
int main()
{
  node* r = new node(1);
  r->l = new node(2);
  r->l->l = new node(4);
  r->l->r = new node(5);
  r->r = new node(3);
  inordertraversal(r);
}