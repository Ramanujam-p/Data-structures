#include<iostream>
using namespace std;
int length(const string &a)
{
    int i = a.size() - 1 , l = 0;
    while(i>=0 && a[i] == ' ')
    {
        i--;
    } 
    while(i>=0 && a[i] != ' ')
    {
        l++;
        i--;
    }
    return l;
}
int main()
{
    string s;
    cout<<"enter the string:";
    getline(cin,s);
    cout<<"The length of the last word in the string is:"<<length(s);
    return 0;
}