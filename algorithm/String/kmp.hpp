/*
 * The implemenation of Kmp algorithm
 */
#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace ds {
// class KMP {
//   vector<int> prefix_function(const string& s) {
//     int sz = s.size();
//     vector<int> pi(sz, 0);
//     for (int i = 1; i < sz; ++i) {
//       int j = pi[i - 1];
//       while (j != 0 && s[j] != s[i])
//         j = pi[j - 1];  // j is length so should be j-1
//       if (s[j] == s[i]) j++;
//       pi[i] = j;
//     }
//     return pi;
//   }
//   vector<int> find(const string& s, const string& t) {
//     string cob = s + "#" + t;
//     int sz = s.length(), cz = cob.size();
//     vector<int> pre = prefix_function(cob);
//     vector<int> ans;
//     for (int i = sz; i < cz; ++i) {
//       if (pre[i] == sz) ans.push_back(i);
//     }
//     return ans;
//   }
// }

class KMP {
public:
  KMP(const string& _s) : s(_s) {
    int sz = s.size();
    pi[0] = 0;
    
    for (int i=1; i<sz; ++i) {
      int j = pi[i-1];
      while (j > 0 &&s[j] == s[i]) j = pi[j-1];
      if (s[j] == s[i]) j++;
      pi[i] = j;
    }
  }
  vector<int> find(const string& t, const string& s) {
    string ts = s + "#" + t;
    int sz = ts.size();
    pi[0] = 0;
    
    vector<int> ans ;
    for (int i=1; i<sz; ++i) {
      int j = pi[i-1];
      while (j > 0 &&s[j] == s[i-1]) j = pi[j];
      if (s[j] == s[i-1]) j++;
      pi[i] = j;
      if (pi[i] == s.size()) ans.push_back(i - s.size());
    }
    return ans;
  }
  private:
  string s;
  vector<int> pi;
};
}  // namespace ds