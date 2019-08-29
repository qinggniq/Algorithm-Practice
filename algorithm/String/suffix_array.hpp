#pragma once

#include <algorithm>
#include <string>
#include <vector>

using std::copy;
using std::distance;
using std::lower_bound;
using std::sort;
using std::string;
using std::unique;
using std::vector;

namespace ds {
class SA {
 public:
  SA(const vector<int>& s) {
    int n = s.size() - 1;
    //离散化
    copy(s.begin() + 1, s.end(), set.begin() + 1);  // idx from 1
    sort(set.begin() + 1, set.end());
    auto end = unique(set.begin() + 1, set.end());
    for (int i = 1; i < n; ++i) {
      a[i] =
          distance(set.begin(), std::lower_bound(set.begin() + 1, end, s[i]));
    }
    //获得第一次的rank
    for (int i = 1; i <= n; ++i) buc[a[i]]++;  //桶排序
    for (int i = 1; i <= n; ++i) buc[i] += buc[i - 1];
    for (int i = 1; i <= n; ++i) rank[i] = buc[a[i] - 1] + 1;

    //倍增
    for (int t = 1; t <= n; t <<= 1) {
      for (int i = 1; i <= n; ++i) fir[i] = rank[i];
      for (int i = 1; i <= n; ++i) sec[i] = i + t > n ? 0 : rank[i + t];  //????

      fill(buc.begin(), buc.end(), 0);
      for (int i = 1; i <= n; ++i) buc[sec[i]]++;
      for (int i = 1; i <= n; ++i) buc[i] += buc[i - 1];
      for (int i = 1; i <= n; ++i) tmp[n - --buc[sec[i]]] = i;  //????

      fill(buc.begin(), buc.end(), 0);
      for (int i = 1; i <= n; ++i) buc[fir[i]]++;
      for (int i = 1; i <= n; ++i) buc[i] += buc[i - 1];
      for (int j = 1, i; j <= n; ++j) i = tmp[j], sa[buc[fir[i]]--] = i;

      bool unique = true;
      for (int j = 1, i, last = 0; j <= n; ++j) {
        i = sa[j];
        if (!last)
          rank[i] = 1;
        else if (fir[i] == fir[last] && sec[i] == sec[last])
          rank[i] = rank[last], unique = false;
        else
          rank[i] = rank[last] + 1;

        last = i;
      }
      if (unique) break;
    }

    for (int i = 1, k = 0; i <= n; ++i) {
      if (rank[i] == 1)
        k = 0;
      else {
        if (k > 0) k--;
        int j = sa[rank[i] - 1];
        while (i + k <= n && j + k <= n && a[i + k] == a[j + k]) k++;
      }
      ht[rank[i]] = k;
    }
  }

 private:
  vector<int> sa;
  vector<int> ht;
  vector<int> a;
  vector<int> rank;
  vector<int> fir;
  vector<int> sec;
  vector<int> tmp;
  vector<int> buc;
  vector<int> set;
}

}  // namespace ds