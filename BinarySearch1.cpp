#include <iostream>
using namespace std;
int bs(int a[], int l, int h, int k)
{
    if (l > h)
        return -1;
    int m = l + (h - l) / 2;
    if (a[m] == k)
        return m;
    else if (a[m] < k)
        return bs(a, m + 1, h, k);
    else
        return bs(a, l, m - 1, k);
}
int main()
{
    int n, k;
    cout << "enter the size of the array:";
    cin >> n;
    int a[n];
    cout << "enter the elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "enter the element to search:";
    cin >> k;
    int l = 0, h = n - 1;
    bs(a, l, h, k);
    int r = bs(a, l, h, k);
    if (r != -1)
        cout << "element found at index :" << r;
    else
        cout << "element not found";
}