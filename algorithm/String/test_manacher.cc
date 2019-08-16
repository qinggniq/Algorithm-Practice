#include <iostream>
#include "manacher.hpp"
using namespace std;
using namespace ds;

// class MLC {
//  public:
//   MLC(const string& _s) : s(_s) {
//     string ts = "#";
//     for (char c : s) ts += c, ts += ("#");
//     int sz = ts.size();
//     plen.assign(sz, 1);
//     for (int i = 0, r = -1, l = 0; i < sz; ++i) {
//       int k = i > r ? 1 : min(plen[l + r - i], r - i);
//       while (i + k < sz && i - k >= 0 && ts[i + k] == ts[i - k]) k++;
//       plen[i] = k--;
//       if (i + k > r) {
//         r = i + k;
//         l = i - k;
//       }
//     }
//   }
//   int getMaxLen() const { return *max_element(plen.begin(), plen.end()) - 1;
//   } vector<int> getAllLen() const { return plen; }

//  private:
//   string s;
//   vector<int> plen;
// };

class MLC {
  MLC(const string& s) {
    string ts = "#";
    for (char c : s) ts += c, ts += "#";
    int sz = ts.size();
    plens.resize(sz);
    for (int i = 0, l = 0, r = -1; i < sz; ++i) {
      int k = i > r ? 1 : min(plens[l + r - i], r - i);
      while (i + k < sz && i - k >= 0 && ts[i + k] == ts[i - k]) k++;
      plens[i] = k--;
      if (i + k > r) {
        r = i + k;
        l = i - k;
      }
    }
  }
  int getMaxLen() const { return *max_element(plens.begin(), plens.end()) - 1; }

 private:
  vector<int> plens;
};

int main() {
  string s("#f#f#f#f#f#");
  cin >> s;
  Manacher m(s);
  MLC ml(s);
  auto o = m.getAllLen();
  auto n = m.getAllLen();
  for (int i = 0; i < o.size(); ++i) {
    cout << o[i] << " " << n[i] << endl;
  }
  cout << m.getMaxLen() << endl;
}
