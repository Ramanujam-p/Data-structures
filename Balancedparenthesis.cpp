#include<iostream>
#include<string>
using namespace std;
#define M 100
class stack
{
    char a[M];
    int t;
    public:
    stack(){ t=-1;}
    void push(char x)
    {
        if(t<M-1) a[++t] = x;
        else cout<<"stack overflow";
    }
    void pop()
    {
        if(t>=0) t--;
        else cout<<"stack underflow";
    }
    char peek()
    {
        if(t>=0) return a[t];
        return '\0';
    }
    bool empty()
    { 
        return t == -1;
    }
};
bool isvalid(const string& a)
{
    stack st;
    for(char c : a)
    {
        if( c == '(' || c == '{' || c == '[') st.push(c);
        else if( c == ')' || c == '}' || c == ']')
        {
            if(st.empty()) return false;
                char top = st.peek();
                st.pop();
                if((c == ')' && top!='(') || ( c == '}' && top!='{') || (c == ']' && top!='[')) 
                return false;
        }
    }
    return st.empty();
}
int main()
{
    string s;
    cout<<"enter the expression:";
    getline(cin,s);
    if(isvalid(s)) cout<<"the entered expression is valid";
    else cout<<"The entered expression is not valid";
    return 0;
}