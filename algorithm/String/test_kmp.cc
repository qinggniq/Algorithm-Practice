#include <iostream>
#include <string>
#include <vector>

using namespace std;
// class KMP {
//  public:
//   KMP(const string& _s) : s(_s) {}

//   vector<int> find(const string& t) {
//     string ts = t + "#" + s;
//     int sz = ts.size();
//     pi.assign(ts.size(), 0);
//     int j;
//     for (int i = 1; i < sz; ++i) {
//       int j = pi[i - 1];
//       while (j > 0 && ts[i] != ts[j]) j = pi[j - 1];
//       if (ts[i] == ts[j]) j++;
//       pi[i] = j;
//     }
//     return pi;
//   }

//  private:
//   string s;
//   vector<int> pi;
// };

// class KMP {
//  public:
//   KMP(const string& _s) : s(_s) {}
//   vector<int> find(const string& t) {
//     string ts = t + "#" + s;
//     int sz = ts.size();
//     pi.resize(sz);
//     pi[0] = 0;
//     for (int i = 1; i < sz; ++i) {
//       int j = pi[i - 1];
//       while (j > 0 && ts[i] != ts[j]) j = pi[j - 1];  // wrong at ts[i] !=
//       ts[j] if (ts[i] == ts[j]) j++; pi[i] = j;
//     }
//     return pi;
//   }

//  private:
//   vector<int> pi;
//   string s;
// };

class KMP {
 public:
  KMP(const string& _s) : s(_s) {}
  vector<int> find(const string& t) {
    string ts = t + "#" + s;
    int sz = ts.size();
    pi.assign(sz, 0);
    for (int i = 1; i < sz; ++i) {
      int j = pi[i - 1];
      while (j > 0 && ts[i] != ts[j]) j = pi[j - 1];
      if (ts[i] == ts[j]) j++;
      pi[i] = j;
    }
    return pi;
  }

 private:
  vector<int> pi;
  string s;
};
int main() {
  KMP kmp("fsadfffffffffffffffffffffffffF");
  auto v = kmp.find("ffff");
  for (int t : v) cout << t << " ";
}