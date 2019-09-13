#include <bits/stdc++.h>

using namespace std; 
long long n, m, q, step;
void solve() {
    long long in_x, in_y, ou_x, ou_y; 
    cin >> in_x >>  in_y >> ou_x >> ou_y;
    in_y--;
    ou_y--;
    long long sec1 = in_y % step, sec2 = ou_y %step;
    if (in_x == 1) {
        sec1 = in_y / (n/step);
    }else{
        sec1 = in_y / (m/step);
    }
    if (ou_x == 1) {
        sec2 = ou_y / (n/step);
    }else{
        sec2 = ou_y / (m/step);
    }
    if (sec1 == sec2) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin >> n >> m >> q;
    step = __gcd(n, m);
    while (q--) {
        solve();
    }
}