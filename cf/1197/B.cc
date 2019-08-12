/*
* author : qinggniq
* github : https://github.com/qinggniq
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int mx = INT_MIN, smx = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    for (int i = 2; i < n; ++i)
    {
        if (nums[i - 1] < min(nums[i], nums[i - 2]))
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main()
{
    solve();
    return 0;
}