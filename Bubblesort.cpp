#include <iostream>
#include <vector>
using namespace std;
void bubble_sort(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}
void input_array(vector<int> &a, int n)
{
    cout << "enter the elements of the array:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void print_array(vector<int> &a, int n)
{
    cout << "The array elements are:";
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
    cout << "Before sorting the array:";
    print_array(a, n);
    cout << endl;
    bubble_sort(a, n);
    cout << "after sorting the array:";
    print_array(a, n);
    return 0;
}