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

const int N = 2e5 + 10;
const long long INF = (1LL << 60);
vector<PII> safe;
vector<PII> tre;

int dis(int a, int b) { return abs(a - b); }

int L[N], R[N], LV[N], RV[N];
struct node {
  int x, y;
  bool operator<(const node& rhs) {
    if (y == rhs.y) return x < rhs.x;
    return y < rhs.y;
  }
} _[N];

int is[N];

void solve() {
  int n, m, k, q, n_ = 0;
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= k; ++i) {
    cin >> _[i].y >> _[i].x;
  }
  sort(_ + 1, _ + 1 + k);
  for (int i = 1; i <= k; ++i) {
    int tx = _[i].x, ty = _[i].y;
    n_ = max(n_, ty);
    if (!LV[ty])
      LV[ty] = tx;
    else
      LV[ty] = min(LV[ty], tx);
    if (!RV[ty])
      RV[ty] = tx;
    else
      RV[ty] = max(RV[ty], tx);
  }
  for (int i = 1; i <= q; ++i) {
    cin >> is[i];
    L[is[i]] = R[is[i]] = is[i];
  }
  sort(is + 1, is + 1 + q);
  for (int i = 1; i <= m; ++i) {
    if (!L[i]) L[i] = L[i - 1];
  }
  for (int i = m; i >= 1; --i) {
    if (!R[i]) R[i] = R[i + 1];
  }
  int posl = 1, posr = 1;
  long long ans = 0, preresl = 0, preresr = 0;
  for (int i = 1; i <= n_; ++i) {
    if (i == 1) {
      if (RV[i]) ans = dis(posl, RV[i]), posl = posr = RV[i];
      preresl = preresr = ans;
    } else {
      preresl++;
      preresr++;
      if (!LV[i] && !RV[i]) continue;
      long long resl = INF, resr = INF;
      if (L[posl])
        resl = min(resl, preresl + dis(posl, L[posl]) + dis(L[posl], RV[i]) +
                             dis(RV[i], LV[i]));
      if (R[posl])
        resl = min(resl, preresl + dis(posl, R[posl]) + dis(R[posl], RV[i]) +
                             dis(RV[i], LV[i]));
      if (L[posr])
        resl = min(resl, preresr + dis(posr, L[posr]) + dis(L[posr], RV[i]) +
                             dis(RV[i], LV[i]));
      if (R[posr])
        resl = min(resl, preresr + dis(posr, R[posr]) + dis(R[posr], RV[i]) +
                             dis(RV[i], LV[i]));
      //进行转移;
      if (L[posl])
        resr = min(resr, preresl + dis(posl, L[posl]) + dis(L[posl], LV[i]) +
                             dis(RV[i], LV[i]));
      if (R[posl])
        resr = min(resr, preresl + dis(posl, R[posl]) + dis(R[posl], LV[i]) +
                             dis(RV[i], LV[i]));
      if (L[posr])
        resr = min(resr, preresr + dis(posr, L[posr]) + dis(L[posr], LV[i]) +
                             dis(RV[i], LV[i]));
      if (R[posr])
        resr = min(resr, preresr + dis(posr, R[posr]) + dis(R[posr], LV[i]) +
                             dis(RV[i], LV[i]));
      ans = min(resl, resr);
      preresl = resl;
      preresr = resr;
      posl = LV[i];
      posr = RV[i];
    }
  }
  cout << ans << "\n";
}

int main() {
  solve();
  return 0;
}