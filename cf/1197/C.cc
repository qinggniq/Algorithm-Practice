/*
* author : qinggniq
* github : https://github.com/qinggniq
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    vector<int> diff(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
        if (i != 0)
        {
            diff[i] = nums[i] - nums[i - 1];
        }
    }
    vector<int> back_up(diff.begin(), diff.end());
    sort(diff.begin(), diff.end(), std::greater<int>());
    unordered_map<int, int> mp;
    for (int i = 0; i < k - 1; ++i)
    {
        //cout << diff[i] << "\n";fdsfds
        mp[diff[i]]++;
    }
    int mx = INT_MIN, mi = INT_MAX, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        //cout << nums[i] << " ";
        if (i != 0 && mp.count(back_up[i]) && mp[back_up[i]])
        {
            //cout << back_up[i] << " " << mx << " " << mi << endl;
            mp[back_up[i]]--;
            ans += (mx - mi);
            mx = nums[i];
            mi = nums[i];
        }
        else
        {
            mx = max(mx, nums[i]);
            mi = min(mi, nums[i]);
            //cout << endl;
        }
    }
    ans += (mx - mi);
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}