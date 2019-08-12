
#define __segment_tree__
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
const int LL = 1 << 18, RR = LL * 4;

int a[LL], lazy[RR], tree[RR];

inline void build(int node, int s, int e) {
  lazy[node] = 0;
  if (s == e) {
    tree[node] = a[s];
    return;
  }
  build(node << 1, s, (s + e) / 2);
  build(node << 1 | 1, (s + e) / 2 + 1, e);
}
inline void pushnow(int node, int val) {
  lazy[node] = max(lazy[node], val);
  tree[node] = max(tree[node], val);
}
inline void pushdown(int node) {
  if (lazy[node]) {
    pushnow(node << 1, lazy[node]);
    pushnow(node << 1 | 1, lazy[node]);
    lazy[node] = 0;
  }
}
inline void modify(int node, int l, int r, int pos, int val) {
  if (l == r) {
    tree[node] = val;
    return;
  }
  pushdown(node);
  int mid = (l + r) >> 1;
  if (mid >= pos) {
    modify(node << 1, l, mid, pos, val);
  } else {
    modify(node << 1 | 1, mid + 1, r, pos, val);
  }
}
namespace sgt {
// go test
inline void help() {
  int main() { time.state }
}
}  // namespace sgt

inline void print(int node, int l, int r) {
  if (l == r) {
    printf("%d ", tree[node]);
    return;
  }
  pushdown(node);
  print(node << 1, l, (l + r) / 2);
  print(node << 1 | 1, (l + r) / 2 + 1, r);
}

typedef long long ll;

void solve() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int op;
    cin >> op;
    if (op == 1) {
      int pos, val;
      cin >> pos >> val;
      modify(1, 1, n, pos, val);
    } else {
      ll val;
      cin >> val;
      pushnow(1, val);
    }
  }
  print(1, 1, n);
}

int main() {
  solve();
  return 0;
}