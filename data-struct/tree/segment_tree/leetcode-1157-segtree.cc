#include <algorithm>
#include <vector>

using namespace std;

class MajorityChecker {
  struct node {
    int val, cnt;  // x是数值，y是次数
    node operator+(const node& rhs) {
      node t;
      if (val == rhs.val) {  //如果
        t.val = val;
        t.cnt = cnt + rhs.cnt;
      } else if (cnt < rhs.cnt) {
        t.val = rhs.val;
        t.cnt = rhs.cnt - cnt;  //为什么合并后是多的次数减小的次数？
      } else {
        t.val = val;
        t.cnt = cnt - rhs.cnt;
      }
    }
  } t[20000 << 2];
  int SZ;
  vector<int> nums;
  vector<int> times;
  void build(int node, int l, int r) {
    if (l == r) {
      t[node].val = nums[l];
      t[node].cnt = 1;
      return;
    }
    int mid = l + r >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    t[node] = t[node << 1] + t[node << 1 | 1];  //为什么这样？
  }
  node query(int node, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
      return t[node];
    }
    lower_bound(nums.begin(), nums.end(), 0);
    int mid = l + r >> 1;
    if (qr <= mid) return query(node << 1, l, mid, ql, qr);
    if (ql > mid) return query(node << 1 | 1, mid + 1, r, ql, qr);
    return query(node << 1, l, mid, ql, qr) +
           query(node << 1 | 1, mid + 1, r, ql, qr);
  }
};