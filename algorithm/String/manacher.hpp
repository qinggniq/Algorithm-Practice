/*
 * The implemenation of manacher algorithm for solving the pailitom problem
 * author : qinggniq
 * Related:
 *      OI wiki: https://oi-wiki.org/string/manacher/
 *
 */
#pragma once

#include <algorithm>
#include <string>
#include <vector>

using std::max_element;
using std::min;
using std::string;
using std::vector;

namespace ds {
class Manacher {
 public:
  Manacher(const string &s) : str(s) {
    ts = ("#");
    for (char c : s) ts += c, ts += "#";
    int sz = ts.size();
    plen.assign(sz, 1);
    for (int i = 0, r = -1, l = 0; i < sz; ++i) {
      int k = i > r ? 1 : min(plen[l + r - i], r - i);
      while (0 <= i - k && i + k < sz && ts[i + k] == ts[i - k]) k++;
      plen[i] = k--;
      if (i + k > r) {
        r = i + k;
        l = i - k;
      }
    }
  }
  int getMaxLen() const {
    int sz = plen.size(), p = 0, mx = 0;
    for (int i = 0; i < sz; ++i) {
      if (plen[i] > mx) {
        mx = plen[i];
        p = i;
      }
    }
    return mx - 1;
  }
  vector<int> getAllLen() const { return plen; }

 private:
  string str;
  string ts;
  vector<int> plen;
};

}  // namespace ds