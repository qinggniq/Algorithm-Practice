/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve() {
  int N, a, b, g, k;
  cin >> N;
  vector<PII> h(N), w(N);
  vector<int> sat;
  for (int i = 0; i < N; ++i) {
    cin >> a >> b >> g >> k;
    w[i].first = a;
    w[i].second = a + g;
    h[i].first = b;
    h[i].second = b + k;
  }
  int x, y;
  cin >> x >> y;
  for (int i = 0; i < N; ++i) {
    if (x >= w[i].first && x <= w[i].second) {
      sat.push_back(i);
    }
  }
  reverse(sat.begin(), sat.end());
  for (int i = 0; i < sat.size(); ++i) {
    if (y >= h[sat[i]].first && y <= h[sat[i]].second) {
      cout << sat[i] + 1 << endl;
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  solve();
  return 0;
}