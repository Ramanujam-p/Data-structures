#include<iostream>
using namespace std;
int longest_common_prefix_length(string a,string b)
{
    int n = min(a.size(),b.size());
    int c = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) c++;
        else break;
    }
    return c;
}
int main(){
    string a,b;
    cout<<"enter the first string:";
    cin>>a;
    cout<<"enter the second string:";
    cin>>b;
    int l = longest_common_prefix_length(a,b);
    cout<<"Length of the longest common prefix:"<<l;
    return 0;
}