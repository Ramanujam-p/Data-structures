#include<bits/stdc++.h>
using namespace std;
vector<int> arrange(vector<int> &a)
{
stable_partition(a.begin(),a.end(),[](int x){return x%2==0;});
return a;
}
int main()
{
   vector<int> a = {1,2,3,4,5,6,7,8,9};
    arrange(a);
    for(int i:a)cout<<i<<" ";
    return 0;
}