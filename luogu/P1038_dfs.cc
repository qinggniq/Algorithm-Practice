/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 * tag : dp
 * method : dfs using inspiration dfs
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;
const int N = 105;
struct Node {
  int cost, val;
  double f;  // val of one storage
  bool operator<(const Node& rhs) { return f > rhs.f; }
} node[N];
int n, m, ans;
int f(int t, int v) {  // t : pos v:package storage
  int tot = 0;
  for (int i = 1; t + i <= n; ++i) {
    if (v >= node[t + i].cost) {
      v -= node[t + i].cost;
      tot += node[t + i].val;
    } else {
      return tot + (int)(v * node[t + i].f);
    }
  }
  return tot;
}
void work(int t, int p, int v) {  // t:pos, p : cur storage , v : val
  ans = max(ans, v);
  if (t > n) return;
  if (f(t, p) + v > ans) work(t + 1, p, v);  // don't select
  if (node[t].cost <= p) work(t + 1, p - node[t].cost, v + node[t].val);
}
void solve() {
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> node[i].cost >> node[i].val;
    node[i].f = 1.0 * node[i].val / node[i].cost;
  }
  sort(node + 1, node + n + 1);
  work(1, m, 0);
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}