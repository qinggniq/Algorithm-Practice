/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve() {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    auto it = mp.lower_bound(-t);
    if (it != mp.end()) {
      mp[it->first]--;
      mp[-t]++;
      if (mp[it->first] == 0) {
        mp.erase(it->first);
      }
    } else {
      mp[-t]++;
    }
  }
  //   int ans = 0;
  //   for (auto m : mp) {
  //     ans += m.second;
  //   }
  printf("%d", mp.size());
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
    printf("\r\n");
  }
  return 0;
}