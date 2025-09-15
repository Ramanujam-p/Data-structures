#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    string s;
    cout<<"enter a string to split into words"<<endl;
    getline(cin,s);
    stringstream a(s);
    string s1;
    vector<string> v;
    while(a>>s1)
    {
        v.push_back(s1);
    }
    for(string x:v) cout<<x<<endl;
    return 0;
}