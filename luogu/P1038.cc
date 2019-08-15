/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 * tag : dp
 * method : 01dp
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve() {
  int v, n;
  cin >> v >> n;
  vector<PII> nums(n);
  vector<int> dp(v + 1, 0);
  for (int i = 0; i < n; ++i) cin >> nums[i].first >> nums[i].second;

  for (int i = 0; i < n; ++i) {
    for (int j = v; j >= nums[i].first; --j) {
      dp[j] = max(dp[j], dp[j - nums[i].first] + nums[i].second);
      dp[j] = max(dp[j], dp[j - 1]);
    }
  }
  cout << dp[v] << endl;
}

int main() {
  solve();
  return 0;
}