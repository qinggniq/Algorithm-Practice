/*
 * author : qinggniq
 * github : https://github.com/qinggniq
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using PII = pair<int, int>;

void solve() {
  int N;
  cin >> N;
  int exp = N, mul;
  while (cin >> mul && (mul == 0)) exp--;
  if (exp != -1) {
     if (exp == 0) {
         cout << mul;
     }else{
         cout << mul << "x^" << exp ;
     }//（（ *（***
  }

  for (int i = 0; i < N; ++i) {
    cin >> mul;
    if (mul) {
    } else {
    }
  }
}

int main() {
  solve();
  return 0;
}