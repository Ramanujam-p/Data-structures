#include <iostream>
#include <vector>
using namespace std;
int par(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
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