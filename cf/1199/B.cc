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
  double H, L;
  cin >> H >> L;
  printf("%.13f\n", (L * L - H * H) / (2 * H));
}

int main() {
  solve();
  return 0;
}