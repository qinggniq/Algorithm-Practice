#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> nums(n, 0);
  for (int i=0; i<n; ++i) {
    cin >> nums[i];
    if (nums[i] >= 0) {
      nums[i] = -nums[i] - 1;
    }
  }
  if (n&1) {
    auto it = min_element(nums.begin(), nums.end());
    *it = -(*it) - 1;
  }
  for_each(nums.begin(), nums.end(), [](auto it) {cout << it << " ";});
  cout << endl;
  return 0;
}
