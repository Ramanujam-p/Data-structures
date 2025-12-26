#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Answer
{
public:
    vector<int> findIndices(const vector<int> &a, int t)
    {
        unordered_map<int, int> m;
        int n = a.size();
        for (int i = 0; i < n;i++)
        {
            int need = t - a[i];
            if(m.find(need)!=m.end())
                return {m[need], i};
            m[a[i]] = i;
        }
        return {};
    }
};
int main()
{
    Answer ans;
    int n, t;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements:";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the target:";
    cin >> t;
    vector<int> r = ans.findIndices(a, t);
    cout << "Indices:" << r[0] << "," << r[1] << endl;
    return 0;
}