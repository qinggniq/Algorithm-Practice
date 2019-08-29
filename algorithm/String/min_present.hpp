/*
 * The implemenation of minium presentation of string;
 * Related:
 *      wiki: https://oi-wiki.org/string/minimal-string/
 */

#include <algorithm>
#include <string>

using std::min;
using std::string;

namespace ds {
class MPS {
 public:
  MPS(const string& _s) : s(_s) {
    int i = 0, j = 1, k = 0;
    int sz = s.size();
    while (k < sz && i < sz && j < sz) {
      if (s[(i + k) % sz] == s[(j + k) % sz]) {
        k++;
      } else {
        // if s[i+k..sz] > s[j+k..sz]
        s[(i + k) % sz] > s[(j + k) % sz] ? i = i + k + 1 : j = j + k + 1;
        if (i == j) i++;
        k = 0;
      }
    }
    pos = min(i, j);
  }

 private:
  int pos;
  string s;
};
}  // namespace ds