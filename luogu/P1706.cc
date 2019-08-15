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
const int N = 10;
int nums[N];
int vis[N];
int n;
void dfs(int pos) {
  if (pos == n) {
    for (int i = 0; i < n; ++i) printf("%5d", nums[i]);
    printf("\n");
    return;
  } else {
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        nums[pos] = i;
        vis[i] = 1;
        dfs(pos + 1);
        vis[i] = 0;
      }
    }
  }
}

void solve() {
  cin >> n;
  dfs(0);
}

int main() {
  solve();
  return 0;
}
