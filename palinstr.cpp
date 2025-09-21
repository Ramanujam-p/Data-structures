#include<iostream>
#include<string>
using namespace std;
string rev(string s)
{
    int i = 0;
    int j = s.size() - 1;
    while(i<j)
    {
     char t = s[i];
     s[i] = s[j];
     s[j] = t;   
     i++;
     j--;
    }
    return s;
}
bool palin(string s)
{
    string b = rev(s);
    return b == s;
}
int main()
{
    string a;
    cout<<"enter the string:";
    getline(cin,a);
    string b = rev(a);
    cout<<"reversed string:"<<b<<"\n";
    if(palin(a)) cout<<"it is a palindromic string";
    else cout<<"it is not a palindromic string";
    return 0;
}