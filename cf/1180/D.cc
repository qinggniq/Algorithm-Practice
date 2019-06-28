#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {

  int n, m; cin >> n >> m;
  int u = 1, d = n;
  setvbuf(stdout, NULL, _IONBF, 1024);
  while (u < d) {
    for (int i=1; i<=m; ++i) {
      printf("%d %d\n", u, i);//fflush(stdout);
      printf("%d %d\n", d, m-i+1);//fflush(stdout);
    }
    u++;
    d--;
  }
  if (u == d) {
    int l = 1, r = m;
    while (l < r) {
      printf("%d %d\n", u, l++);//fflush(stdout);
      printf("%d %d\n", u, r--);//fflushfflush(stdout);
      //cout << u << " " << l++ << endl;
      //cout << u << " " << r-- << endl;
    }
    if (l == r) printf("%d %d", u, l);//, fflush(stdout);//cout << u << " " << l << endl;
  }
  return 0;
}
