#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 200, maxk = 750;

int sum[maxk][maxk], nums[maxn];

void solve() {
  int q, op, x, y;
  cin >> q;
  while (q--) {
    cin >> op >> x >> y;
    if (op == 1) {
      nums[x] += y;
      for (int i = 1; i < maxk; ++i) sum[i][x % i] += y;
    } else if (x >= maxk) {
      int ans = 0;
      for (int i = y; i <= 500000; i += x) {
        ans += nums[i];
      }
      cout << ans << endl;
    } else {
      cout << sum[x][y] << endl;
    }
  }
}

int main() {
  int n;
  solve();
}