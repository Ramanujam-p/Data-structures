// iterative approach of binary search
#include <iostream>
using namespace std;
int Binary_Search(int a[], int n, int k)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int n, k;
    cout << "enter the size of the array:";
    cin >> n;
    // create the array with the size of n
    int a[n];
    // array should be in sorted order for binary search
    cout << "enter the elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "enter the element to search in the array:";
    cin >> k;
    int r = Binary_Search(a, n, k);
    if (r != -1)
        cout << "element found at index :" << r;
    else
        cout << "element not found";
    return 0;
}