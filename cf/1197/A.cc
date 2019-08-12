/*
* author : qinggniq
* github : https://github.com/qinggniq
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());

    int k = min(nums[n - 1], nums[n - 2]) - 1;
    if (k <= 0)
    {
        cout << "0\n";
    }
    else
    {
        nums.pop_back();
        nums.pop_back();
        //int cnt = distance(nums.begin(), unique(nums.begin(), nums.end()));
        cout << min((int)nums.size(), k) << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}