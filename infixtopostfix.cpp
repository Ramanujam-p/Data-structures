#include<bits/stdc++.h>
using namespace std;
int pre(char o)
{
  if(o=='+'||o=='-') return 1;
  if(o=='*'||o=='/') return 2;
  if(o=='^') return 3;
  return 0;
}
string itopc(string i)
{
    stack<char> st;//create the stack for storing the operators
    string r ="";//create the empty string to store the converted postfix expression
    for(char c:i) //take character by character from infix expression
    {
        if(isalnum(c))//if the character is alphabet , concat to resulted string
            r += c;
        else if(c=='(') // if the character is '(' , push to the stack
            st.push(c);
        else if(c==')') // if the character is ')' , check stack is empty or not and if the stack's top is not equal to ')' and push all the characters to the string and pop each character from the stack and finally pop '(' from the stack 
        {
            while(!st.empty()&&st.top()!='(')
            {
                r += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();//'(' pop the remaining character
        }
        else
        {
            while(!st.empty() && pre(st.top()) >= pre(c))
            {
                r += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        r += st.top();
        st.pop();
    }
    return r;
}
int main()
{
    string i,r;
    cout<<"enter the infix expression:";
    cin>> i ;
    r = itopc(i);
    cout<<"postfix expression:"<<r;
    return 0;
}