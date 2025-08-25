#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    cout<<q.empty()<<endl;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.empty()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<endl;
}