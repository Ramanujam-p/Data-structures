#include <bits/stdc++.h>
using namespace std;
class Answer
{
public:
    int subArraySum(const vector<int> &a, int k)
    {
        unordered_map<int, int> m;
        m[0] = 1;
        int n = a.size();
        int s = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            s += a[i];
            if (m.find(s - k) != m.end())
                c += m[s - k];
            m[s]++;
        }
        return c;
    }
};
int main()
{
    int n, k;
    Answer ans;
    cout << "Enter the size of the array:";
    cin >> n;
    cout<<"Enter k:";
    cin >> k;
    vector<int> a(n);
    cout << "The array elements are:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int r = ans.subArraySum(a, k);
    cout << "The number of subarrays sum is equal to:" << k << " is:" << r;
    return 0;
}