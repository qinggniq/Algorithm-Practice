/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> nums(n + 1);
  for (int i = 1; i <= n; ++i) cin >> nums[i];
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    int l = i - 1, r = i + 1;
    while (l >= max(1, i - x) && nums[l] > nums[i]) l--;
    while (r <= min(n, i + y) && nums[r] > nums[i]) r++;
    if (l == max(1, i - x) - 1 && r == min(n, i + y) + 1) {
      cout << i << "\n";
      return;
    }
  }
}

int main() {
  solve();
  return 0;
}