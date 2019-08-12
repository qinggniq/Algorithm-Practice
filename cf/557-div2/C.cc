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

bool check(int tar, const int k, const vector<int>& nums) {
  int mid = nums.size() / 2, sz = nums.size();
  ll cnt = 0;
  for (int i = mid; i < sz; ++i) {
    if (tar > nums[i]) {
      cnt += ((ll)tar - nums[i]);
    } else {
      break;
    }
  }
  return cnt <= k;
}

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) cin >> nums[i];
  sort(nums.begin(), nums.end());
  int nmid = nums.size() / 2;
  ll l = nums[nmid], r = l + K;
  while (l < r) {
    ll mid = (l + r + (ll)1) / (ll)2;
    if (check(mid, K, nums)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
}

int main() {
  solve();
  return 0;
}