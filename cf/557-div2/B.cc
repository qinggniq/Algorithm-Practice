/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve() {
  int n;
  cin >> n;
  vector<ll> nums(n);
  for (ll i = 0; i < n; ++i) cin >> nums[i];
  ll sm = accumulate(nums.begin(), nums.end(), (ll)0);
  ll mx = *max_element(nums.begin(), nums.end());
  if (sm & 1 || mx > sm / 2) {
    cout << "NO";
    return;
  }
  cout << "YES";
}

int main() {
  solve();
  return 0;
}