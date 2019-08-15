/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

class MajorityChecker {
 public:
  int S, N;
  vector<vector<int>> blocks;
  vector<int> maj;
  vector<int> nums;
  MajorityChecker(vector<int>& arr) {
    blocks.resize(205);
    fill(blocks.begin(), blocks.end(), vector<int>(20005));
    maj.resize(205);
    S = sqrt(2 * arr.size());
    int sz = arr.size();
    map<int, int> mp;
    nums.swap(arr);
    N = 0;
    for (int a : nums) mp[a]++;
    for (auto m : mp) {
      if (m.second > S / 2) {
        maj[++N] = m.first;
        for (int i = 0; i < sz; ++i)
          blocks[N][i + 1] = blocks[N][i] + (nums[i] == m.first);
      }
    }
  }

  int query(int left, int right, int threshold) {
    if (right - left + 1 <= S) {
      int val = -1, cnt = 0;
      for (int i = left; i <= right; ++i) {
        if (val == nums[i])
          cnt++;
        else if (cnt)
          cnt--;
        else {
          val = nums[i];
          cnt = 1;
        }
      }
      cnt = 0;
      for (int i = left; i <= right; ++i) {
        cnt += (nums[i] == val);
      }
      if (cnt < threshold) return -1;
      return val;
    }
    for (int i = 1; i <= N; ++i) {
      int t = maj[i];
      if (blocks[i][right + 1] - blocks[i][left] >= threshold) return t;
    }
    return -1;
  }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
void solve() {}

int main() {
  solve();
  return 0;
}