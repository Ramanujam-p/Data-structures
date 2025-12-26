//Brute force approach Time-complexity=O(n^2),Space-complexity=O(1)
#include <iostream>
#include <vector>
using namespace std;
class Answer
{
public:
    vector<int> findIndices(const vector<int> &a, int t)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] + a[j] == t)
                    return {i, j};
        return {};
    }
};
int main()
{
    Answer ans;
    int n, t;
    cout << "Enter the number of elements:";
    cin >> n;
    vector<int> a(n);
    cout<<"The elements are:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the target:";
    cin >> t;
    vector<int> b = ans.findIndices(a, t);
    cout << "Indices:" << b[0] << "," << b[1] << endl;
}