#include <bits/stdc++.h>
using namespace std;
class Answer
{
public:
    int subArraySum(const vector<int> &a, int k)
    {
        int n = a.size();
        int s, c = 0;
        for (int i = 0; i < n; i++)
        {
            s = 0;
            for (int j = i; j < n; j++)
            {
                s += a[j];
                if (s == k)
                    c++;
            }
        }
        return c;
    }
};
int main()
{
    Answer ans;
    int n, k, r;
    cout << "Enter the size of the array:";
    cin >> n;
    cout << "enter the k:";
    cin >> k;
    vector<int> a(n);
    cout << "The array elements are:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    r = ans.subArraySum(a, k);
    cout << "The number of subarray that equals the sum " << k << " is: " << r << endl;
    return 0;
}