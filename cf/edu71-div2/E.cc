#include <bits/stdc++.h>

using namespace std;

void solve() {
  int ans1, ans2;
  cout << "? ";

  for (int i = 1; i < 100; i++) cout << i << " ";
  cout << "100" << endl;
  cin >> ans1;
  cout << "? ";
  for (int i = 1; i < 100; i++) cout << (i << 7) << " ";
  cout << (100 << 7) << endl;
  cin >> ans2;
  int mask1 = 0, mask2 = 0;
  for (int i = 0; i < 7; i++) mask1 |= (1 << i);
  mask2 = mask1 << 7;
  cout << "! " << ((ans1 & mask2) | (ans2 & mask1)) << endl;
}

int main() {
  int n;
  n = 1;
  while (n--) {
    solve();
  }
}