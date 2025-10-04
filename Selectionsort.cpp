#include <iostream>
#include <vector>
using namespace std;
void selection_sort(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int m = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] < a[i])
                m = j;
        }
        swap(a[i], a[m]);
    }
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
    cout << "\n";
}
int main()
{
    int n;
    cout << "enter the size of the array:";
    cin >> n;
    vector<int> a(n);
    input_array(a, n);
    cout << "Before sorting:";
    print_array(a, n);
    selection_sort(a, n);
    cout << "after sorting:";
    print_array(a, n);
}