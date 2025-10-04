#include <iostream>
#include <vector>
using namespace std;
void counting_sort(vector<int> &a, int n)
{
    int m = a[0]; // find the maximum element
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];
    vector<int> b(m + 1, 0); // create count array and initialize with 0
    for (int i = 0; i < n; i++)
        b[a[i]]++; // increment the count of each element
    for (int i = 1; i <= m; i++)
        b[i] += b[i - 1]; // update the count array
    vector<int> c(n);     // create output array
    for (int i = n - 1; i >= 0; i--)
    {
        c[b[a[i]] - 1] = a[i]; // place the elements in output array
        b[a[i]]--;             // decrement the count
    }
    a = c; // copy the output array to original array
}
void input_array(vector<int> &a, int n)
{
    cout << "enter the array elements:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void print_array(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int n;
    cout << "enter the size of the array:";
    cin >> n;
    vector<int> a(n);
    input_array(a, n);
    cout << "before sorting:";
    print_array(a, n);
    counting_sort(a, n);
    cout << "after sorting:";
    print_array(a, n);
    return 0;
}