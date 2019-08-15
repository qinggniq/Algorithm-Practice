#include <iostream>
#include <string>
#include <vector>

using namespace std;
class KMP {
 public:
  KMP(const string& _s) : s(_s) {}

  vector<int> find(const string& t) {
    string ts = t + "#" + s;
    int sz = ts.size();
    pi.assign(ts.size(), 0);
    int j;
    for (int i = 1; i < sz; ++i) {
      int j = pi[i - 1];
      while (j > 0 && ts[i] != ts[j]) j = pi[j - 1];
      if (ts[i] == ts[j]) j++;
      pi[i] = j;
    }
    return pi;
  }

 private:
  string s;
  vector<int> pi;
};

int main() {
  KMP kmp("fsadfffffffffffffffffffffffffF");
  auto v = kmp.find("ffff");
  for (int t : v) cout << t << " ";
}