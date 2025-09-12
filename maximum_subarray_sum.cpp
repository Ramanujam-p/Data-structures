#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    vector<int> p = {2,-3,4,-1,2,1,-5,4};
    int n = p.size();
    int a = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=i;j<n;j++)
        {
            s+=p[j];
            a = max(a,s);
        }
    }
    cout<<"maximum subarray sum:"<<a<<endl;
}