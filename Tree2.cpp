#include<iostream>
using namespace std;
struct node
{
  char c;
  node* l;
  node* r;
  node(char v):c(v),l(nullptr),r(nullptr){}
};
void inorder(node* root)
{
    if(!root) return;
    inorder(root->l);
    cout<<root->c<<"->";
    inorder(root->r);
}
void preorder(node* root)
{
    if(!root) return;
    cout<<root->c<<"->";
    preorder(root->l);  
    preorder(root->r);
}
void postorder(node* root)
{
    if(!root) return;
    postorder(root->l);
    postorder(root->r);
    cout<<root->c<<"->";
}
int main()
{
    node* H = new node('H');
    node* A = new node('A');
    node* B = new node('B');
    node* C = new node('C');
    node* D = new node('D');
    node* E = new node('E');
    node* F = new node('F');
    node* G = new node('G');
    H->l = A;
    A->r = F;
    F->l = B;
    F->r = G;
    B->r = D;
    D->l = C;
    D->r = E;
    cout<<"Inorder";
    inorder(H);
    cout<<"preorder";
    preorder(H);
    cout<<"postorder";
    postorder(H);
    return 0;
}