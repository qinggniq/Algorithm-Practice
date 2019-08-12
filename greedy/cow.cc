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
using PII = pair<int, int>;

void solve() {
  int M, S, C;
  cin >> M >> S >> C;
  vector<int> cows(C + 1), diff(C);
  int mx = -1, mi = INT_MAX;
  for (int i = 0; i < C; ++i) {
    cin >> cows[i];
    mx = max(cows[i], mx);
    mi = min(cows[i], mi);
  }
  int total = mx - mi + 1;
  sort(cows.begin(), cows.end() - 1);
  for (int i = 0; i < C - 1; ++i) {
    diff[i] = cows[i + 1] - cows[i];
  }
  sort(diff.begin(), diff.end() - 1, std::greater<int>());
  for (int i = 0; i < min(M - 1, C - 1); ++i) {
    total -= (diff[i] - 1);
  }
  cout << total << "\n";
}

int main() {
  solve();
  return 0;
}