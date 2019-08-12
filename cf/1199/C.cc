/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve() {
  long long N, n, I, k, K;
  cin >> N >> I;
  k = I * 8 / N;
  // cout << n << " " << I << " " << I / n << endl;
  if (k > 20) {
    cout << "0\n";
    return;
  }
  K = pow(2, k);
  vector<ll> nums(N + 1, -1), b(N + 1, 0);
  for (int i = 1; i <= N; ++i) cin >> nums[i];
  sort(nums.begin(), nums.end());
  // cout << "n : " << n << " k : " << k << " K : " << K << endl;
  int cnt = 0;
  for (int i = 1; i <= N; ++i) {
    if (nums[i] ^ nums[i - 1])
      nums[++cnt] = nums[i], b[cnt] = 1;
    else
      ++b[cnt];
  }
  for (int i = 1; i <= N; ++i) {
    b[i] += b[i - 1];
  }
  if (cnt <= K) {
    cout << "0\n";
    return;
  }
  int ans = 0;
  for (int i = 1, up = i + K - 1; up <= N; ++i, ++up) {
    int tmp = b[up] - b[i - 1];
    ans = max(ans, tmp);
  }
  cout << N - ans << "\n";
}

int main() {
  solve();
  return 0;
}