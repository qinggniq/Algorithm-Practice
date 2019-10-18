#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> nums(n);
  vector<int> fac(n + 1, 0);
  for (int i = 0; i < n; ++i) cin >> nums[i].first >> nums[i].second;
  for (int i = fac[0] = 1; i <= n; ++i) fac[i] = (ll)fac[i - 1] * i % mod;
  int ans[4] = {fac[n], 1, 1, 1};
  for (int c = 1; c <= 2; ++c) {
    sort(nums.begin(), nums.end());
    int l = 0, r;
    while (l < n) {
      r = l + 1;
      while (r < n && nums[r].first == nums[l].first) r++;
      ans[c] = 1LL * ans[c] * fac[r - l] % mod;
      l = r;
    }
    ans[0] = (1LL * ans[0] + 1LL * (mod - ans[c])) % mod;
    for (int i = 0; i < n; ++i) swap(nums[i].first, nums[i].second);
  }
  int l = 0, r;
  sort(nums.begin(), nums.end());
  while (l < n) {
    r = l + 1;
    while (r < n && nums[r].first == nums[l].first) r++;
    map<int, int> mp;
    for (int i = l; i < r; i++) mp[nums[i].second]++;
    for (auto &p : mp) {
      ans[3] = 1LL * ans[3] * fac[p.second] % mod;
    }
    l = r;
  }
  for (int i = 1; i < n; ++i)
    if (nums[i].second < nums[i - 1].second) ans[3] = 0;
  ans[0] = (1LL * ans[0] + 1LL * ans[3]) % mod;
  cout << ans[0] << endl;
}

int main() {
  int n;
  n = 1;
  while (n--) {
    solve();
  }
}