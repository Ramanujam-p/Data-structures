#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1; // why do we add 1 becuase the array is 0 indexed
    int n2 = right - (mid + 1) + 1;
    vector<int> b(n1), c(n2);
    for (int i = 0; i < n1; i++)
        b[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        c[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (b[i] <= c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = c[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int> &a, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    merge(a, left, mid, right);
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
    cout << "array before sorting:";
    print_array(a, n);
    merge_sort(a, 0, n - 1);
    cout << endl;
    cout << "array after sorting:";
    print_array(a, n);
    return 0;
}