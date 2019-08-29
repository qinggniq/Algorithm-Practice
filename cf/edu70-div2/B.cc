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
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VVVV = vector<VVV>;
vector<bool> vis;
VVVV d;

void bfs(int x, int y, int z, V& v) {
  fill(vis.begin(), vis.end(), false);
  queue<int> q;
  q.push(z);
  v[z] = 0;
  if (x > y) swap(x, y);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int v1 = u + y, v2 = u + x;
    if (v1 >= 10) v1 -= 10;
    if (v2 >= 10) v2 -= 10;
    if (!vis[v1]) {
      v[v1] = v[u] + 1;
      q.push(v1);
      vis[v1] = true;
    }
    if (!vis[v2]) {
      v[v2] = v[u] + 1;
      q.push(v2);
      vis[v2] = true;
    }
  }
}

void pre() {
  d.assign(10, VVV(10, VV(10, V(10, -1))));
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; i < 10; ++k) {
        bfs(i, j, k, d[i][j][k]);
      }
    }
  }
}
void solve() {
vis.resize(10);
pre();
st ring s;
cin >> s;
int sz = s.size();
for (int i = 0; i < 10; ++i) {
  for (int j = 0; j < 10; ++j) {
    int ans = 0;
    for (int k = 1; k < sz; ++k) {
      if (d[i][j][s[k - 1] - '0'][s[k] - '0'] == -1) {
        ans = -1;
        break;
      }
      ans += d[i][j][s[k - 1] - '0'[s[k] - '0']];
    }
    cout << ans << ' ';
  }
  cout << '\n';
}
id solve()
}

int main() {
  solve();
  return 0;
}