#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

int main() {
  ll n, q, tmp; cin >> n >> q;
  deque<int> nums;
  vector<pair<int, int>> res(n+1);
  for (int i=0; i<n; ++i) {
    cin >> tmp;
    nums.push_back(tmp);
  }
  for (int i=1; i<n; ++i) {
    int a = nums.front(); nums.pop_front();
    int b = nums.front(); nums.pop_front();
    res[i] = make_pair(a, b);
    nums.push_back(min(a, b));
    nums.push_front(max(a, b));
  }
  vector<int> save(nums.begin(), nums.end());
  for (int i=0; i<q; ++i) {
    ll m; cin >> m;
    if (m < n) {
      cout << res[m].first << " " << res[m].second << endl;
    }else{
      cout << save[0] << " " << save[(m-n)%(n-1)+1] << endl;
    }
  }
  return 0;
}
