#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;

int calc(vector<int>& nums) {
  int sz = nums.size();
  int q = 0;
  for (int i = 0; i < sz; ++i) {
    if ((1 << i) == sz) {
      q = i;
      break;
    }
  }
  cout << ans[1] << endl;
  int j = nums.size() - 1;

  for (int i = 1; i <= q; ++i) {
    int cnt = 0, add = 0;
    while (cnt < (sz >> (i))) {
      cnt++;
      (ans[j << 1] + ans[j << 1 | 1]) int tmp =
          ((1 << ((i - 1))) - (ans[j] - ans[j << 1] - ans[j << 1 | 1]));
      add += tmp;
      j--;
    }
    cout << ans[1] + add << endl;
  }
}

int merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
  vector<int> tmp(r1 - l1 + r2 - l2 + 2);
  int pos = 0, cnt = 0;
  int l = l2, r = r2;
  int s = l1, e = r2;
  while (l1 <= r1 && l2 <= r2) {
    if (nums[l1] <= nums[l2]) {
      tmp[pos++] = nums[l1];
      l1++;
    } else if (nums[l1] > nums[l2]) {
      cnt++;
      tmp[pos++] = nums[l2];
      l2++;
    }
  }

  if (l1 > r1) {
    while (l2 <= r2) {
      tmp[pos++] = nums[l2];
      l2++;
    }
  } else if (l2 > r2) {
    cnt += (r1 - l1) * (r - l + 1);
    while (l1 <= r1) {
      tmp[pos++] = nums[l1];
      l1++;
    }
  }

  for (int i = s; i <= e; ++i) {
    nums[i] = tmp[i - s];
  }
  return cnt;
}

int count(vector<int>& nums, int start, int end, int node) {
  if (start == end) {
    ans[node] = 0;
    return 0;
  } else {
    int mid = start + end >> 1;
    int lc = count(nums, start, mid, node << 1);
    int rc = count(nums, mid + 1, end, node << 1 | 1);
    int now = merge(nums, start, mid, mid + 1, end);
    if (node == 1) {
      int a = 0;
      cout << " -- " << endl;
    }
    ans[node] = lc + rc + now;
    return ans[node];
  }
}

int main() {
  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
  reverse(nums.begin(), nums.end());
  ans.resize(nums.size() * 4);
  count(nums, 0, nums.size() - 1, 1);
  calc(nums);
}