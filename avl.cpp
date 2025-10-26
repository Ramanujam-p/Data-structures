#include <iostream>
using namespace std;
class node
{
public:
    int key, height;
    node *left, *right;
    node(int v) : key(v), left(nullptr), right(nullptr), height(1) {};
};
class avl
{
private:
    node *root;
    int height(node *n)
    {
        return n ? n->height : 0;
    }
    int getbalance(node *n)
    {
        return n ? (height(n->left) - height(n->right)) : 0;
    }
    node *minnode(node *n)
    {
        node *t = n;
        while (t->left)
            t = t->left;
        return t;
    }
    node *rightrotate(node *y)
    {
        node *x = y->left;
        node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
    }
    node *leftrotate(node *x)
    {
        node *y = x->right;
        node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
    }
    node *insertrec(node *n, int key)
    {
        if (!n)
            return new node(key);
        if (key < n->key)
            n->left = insertrec(n->left, key);
        else if (key > n->key)
            n->right = insertrec(n->right, key);
        else
            return n;
        n->height = max(height(n->left), height(n->right)) + 1;
        int balance = getbalance(n);
        if (balance > 1 && key < n->left->key)
            return rightrotate(n);
        if (balance > 1 && key > n->left->key)
        {
            n->left = leftrotate(n->left);
            return rightrotate(n);
        }
        if (balance < -1 && key > n->right->key)
            return leftrotate(n);
        if (balance < -1 && key < n->right->key)
        {
            n->right = rightrotate(n->right);
            return rightrotate(n);
        }
        return n;
    }
};