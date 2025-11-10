#include <iostream>
using namespace std;
int Linear_Search(int a[], int n, int b)
{
    for (int i = 0; i < n; i++)
        if (a[i] == b)
            return i;
    return -1;
}
int main()
{
    int n;
    cout << "enter the size of the array:";
    cin >> n;
    int a[n];
    cout << "enter the elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b;
    cout << "enter the element to be searched:";
    cin >> b;
    int r = Linear_Search(a, n, b);
    if (r != -1)
        cout << "element found at index " << r;
    else
        cout << "element not found";
}