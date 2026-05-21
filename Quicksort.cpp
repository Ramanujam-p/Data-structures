#include <iostream>
#include <vector>
using namespace std;
int par(vector<int> &a, int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i <= high)
            i++;
        while (a[j] > pivot && j >= low)
            j--;
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}
void quick_sort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = par(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}
void input_array(vector<int> &a, int n)
{
    cout << "enter the array elements are:";
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
    cout << endl;
    quick_sort(a, 0, n - 1);
    cout << "array after sorting:";
    print_array(a, n);
}