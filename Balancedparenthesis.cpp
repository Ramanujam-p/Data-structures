#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isvalid(const string& a)
{
    stack<char> st;
    for(char c : a)
    {
        if( c == '(' || c == '{' || c == '[') st.push(c);
        else if( c == ')' || c == '}' || c == ']')
        {
            if(st.empty()) return false;
                char top = st.top();
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