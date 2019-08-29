#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

namespace first {
vector<ll> head;
vector<ll> tail;
ll find_head(ll x) { return head[x] == x ? x : find_head(head[x]); }

ll find_tail(ll x) { return tail[x] == x ? x : find_tail(tail[x]); }

void merge(ll x, ll y) {
  ll head_x = find_head(x);
  ll tail_y = find_tail(y);
  head[x] = tail_y;
  tail[y] = head_x;
}

ll pre(ll x) {
  register int res = 0;
  // cal the distance form x to head
  while (head[x] != x) {
    x = head[x];
    res++;
  }
  return res;
}

ll dis(ll x, ll y) { return max(pre(x), pre(y)) - min(pre(x), pre(y)) - 1; }

}  // namespace first

namespace optimized {
vector<ll> head;
vector<ll> tail;
vector<ll> prefix;

ll find_head(ll x) {
  if (head[x] != x) {
    if (head[head[x]] != head[x]) {
      prefix[x] += prefix[head[x]];
    }
    head[x] = find_head(head[x]);  // compress path
  }
  return head[x];
}

ll find_tail(ll x) { return tail[x] == x ? x : find_tail(tail[x]); }

void merge(ll x, ll y) {
  ll head_x = find_head(x);
  ll tail_y = find_tail(y);

  head[head_x] = tail_y;
  tail[tail_y] = head_x;
  // 1 is the distance between head_x and tail_y, if head[y] != tail[y], then
  // prefix[x] will add the distance whrn call find_head(x)
  prefix[head_x] = 1;  // now head[x] will be the first of head[x];
}

ll pre(ll x) {
  if (head[x] == x) {
    return prefix[x] = 0;
  } else {
    if (head[head[x]] != head[x]) {
      prefix[x] += pre(head[x]);
    }
    head[x] = find_head(head[x]);
  }
  return prefix[x];
}
}  // namespace optimized