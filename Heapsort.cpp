#include <iostream>
using namespace std;
void heapify(int a[], int n, int i)
{
    int la = i;
    int l = (i * 2) + 1;
    int r = (i * 2) + 2;
    if (l < n && a[l] > a[la])
        la = l;
    if (r < n && a[r] > a[la])
        la = r;
    if (la != i)
    {
        swap(a[i], a[la]);
        heapify(a, n, la);
    }
}
void heap(int a[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int n;
    cout << "enter the size of the array:";
    cin >> n;
    int a[n];
    cout << "enter the array elements:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "before sorting:";
    print(a, n);
    cout << endl;
    heap(a, n);
    cout << "after sorting:";
    print(a, n);
    return 0;
}