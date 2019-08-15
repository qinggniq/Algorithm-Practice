/*
 * The implemenation of Kmp algorithm
 */
#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace ds {
class KMP {
  vector<int> prefix_function(const string& s) {
    int sz = s.size();
    vector<int> pi(sz, 0);
    for (int i = 1; i < sz; ++i) {
      int j = pi[i - 1];
      while (j != 0 && s[j] != s[i])
        j = pi[j - 1];  // j is length so should be j-1
      if (s[j] == s[i]) j++;
      pi[i] = j;
    }
    return pi;
  }
  vector<int> find(const string& s, const string& t) {
    string cob = s + "#" + t;
    int sz = s.length(), cz = cob.size();
    vector<int> pre = prefix_function(cob);
    vector<int> ans;
    for (int i = sz; i < cz; ++i) {
      if (pre[i] == sz) ans.push_back(i);
    }
    return ans;
  }
}
}  // namespace ds