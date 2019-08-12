/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<long long, long long>;

void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> nums(n + 1, 0);
  vector<long long> sm(n + 1, 0);
  for (long long i = 0; i < n; ++i) cin >> nums[i];
  long long ans = 0;
  for (long long i = 0; i < m; ++i) {
    for (long long j = 0; j < n; ++j) {
      sm[j] = nums[j];
      if (j % m == i) sm[j] = nums[j] - k;
    }
    for (long long j = 1; j < n; ++j) sm[j] += sm[j - 1];
    long long mi = 0;
    for (long long j = 0; j < n; ++j) {
      if (j % m == i) ans = max(ans, sm[j] - mi);
      mi = min(mi, sm[j]);
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}