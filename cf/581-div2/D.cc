#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size()-1;
    int tmp = 0;
    for (int i=n; i >= 0; --i) {
        if (s[i] == '0') {
            tmp ++;
        }else if (tmp) {
            tmp--;
        }else{
            s[i] = '0';
        }
    }
    cout << s << endl;
}

int main() {
    int n; n = 1;
    while (n--) {
    solve();
}
}