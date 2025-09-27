#include<iostream>
using namespace std;
void is(int a[],int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        int k = a[i] ;
        int j = i - 1 ;
        while(j>=0 && a[j]>k)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=k;
    }
}
void pa(int a[],int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
int main()
{
    int n;
    cout<<"enter the size of the array:";
    cin>>n;
    int a[n];
    cout<<"enter the array elements:";
    for(int i = 0 ; i < n ; i++) cin>>a[i];
    cout<<"Before sorting:";
    pa(a,n);
    cout<<endl;
    is(a,n);
    cout<<"after sorting:";
    pa(a,n);
    return 0;
}