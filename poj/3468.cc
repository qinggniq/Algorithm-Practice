#ifndef __segment_tree__
#define __segment_tree__
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

typedef long long ll;
template <typename T>
class SegementTree {
 public:
  SegementTree(const std::vector<T>& nums_) {
    nums = nums_;
    tree = std::vector<T>(6 * nums.size() + 10, 0);
    lazy = std::vector<T>(6 * nums.size() + 10, 0);
    setOp([](T a, T b) -> decltype(a + b) { return a + b; });
    build(0, 0, (int)nums.size() - 1);
  }
  void setOp(std::function<T(T, T)> fun) { op = fun; }
  void build(int node, int start, int end) {
    if (start > end) return;

    if (start == end) {
      tree[node] = nums[start];
      return;
    }

    int mid = start + (end - start) / 2;
    build(node * 2 + 1, start, mid);
    build(node * 2 + 2, mid + 1, end);
    updateNode(node);
  }

  void update(int node, int sstart, int send, int ustart, int uend, T diff) {
    if (lazy[node] != 0) {
      tree[node] = op(tree[node], (send - sstart + 1) * lazy[node]);
      if (sstart != send) {
        lazy[node * 2 + 1] = op(lazy[node * 2 + 1], lazy[node]);
        lazy[node * 2 + 2] = op(lazy[node * 2 + 2], lazy[node]);
      }
      lazy[node] = 0;
    }
    if (sstart > send || ustart > send || uend < sstart) return;

    if (sstart >= ustart && send <= uend) {
      tree[node] = op(tree[node], (send - sstart + 1) * diff);
      if (sstart != send) {
        lazy[node * 2 + 1] = op(lazy[node * 2 + 1], diff);
        lazy[node * 2 + 2] = op(lazy[node * 2 + 2], diff);
      }
      return;
    }
    int mid = sstart + (send - sstart) / 2;
    update(node * 2 + 1, sstart, mid, ustart, uend, diff);
    update(node * 2 + 2, mid + 1, send, ustart, uend, diff);
    updateNode(node);
  }

  T rangeQuery(int node, int sstart, int send, int qstart, int qend) {
    if (lazy[node] != 0) {
      tree[node] = op(tree[node], (send - sstart + 1) * lazy[node]);

      if (sstart != send) {
        // FIXIT depend ont the kind of problem
        lazy[node * 2 + 1] = op(lazy[node * 2 + 1], lazy[node]);
        lazy[node * 2 + 2] = op(lazy[node * 2 + 2], lazy[node]);
      }
      // only update once;
      lazy[node] = 0;
    }
    if (sstart > send || sstart > qend || send < qstart) return 0;
    if (sstart >= qstart && send <= qend) return tree[node];
    int mid = sstart + (send - sstart) / 2;

    // FIXIT the operation depends on the kind of problem
    return op(rangeQuery(node * 2 + 1, sstart, mid, qstart, qend),
              rangeQuery(node * 2 + 2, mid + 1, send, qstart, qend));
  }

 private:
  void updateNode(int node) {
    // change the code depends on problem

    // sum of range
    tree[node] = op(tree[node * 2 + 1], tree[node * 2 + 2]);

    // // min of range
    // tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);

    // // max of range
    // tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
  }

 private:
  std::function<T(T, T)> op;
  std::vector<T> nums;
  std::vector<T> tree;
  std::vector<T> lazy;
};

#endif

using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<ll> nums(N);
  for (int i = 0; i < N; ++i) cin >> nums[i];
  SegementTree<ll> st(nums);

  char o;
  ll l, r, val;
  for (ll i = 0; i < Q; ++i) {
    cin >> o;
    if (o == 'Q') {
      cin >> l >> r;
      cout << st.rangeQuery(0, 0, N - 1, l - 1, r - 1) << endl;
    } else if (o == 'C') {
      cin >> l >> r >> val;
      st.update(0, 0, N - 1, l - 1, r - 1, val);
    }
  }
}