#include <iostream>
#include <cassert>

using namespace std;

void solve() {
    int n; cin >> n;
    int len = 2;
    while (len*(len+1)/2 <= n) len++;
     n -=  len*(len-1)/2;
    assert(n >= 0);
    assert(n <= 45000);
    string ans = "133";
    while (n > 0) ans += "7", n--;
    len -= 2; 
    while (len > 0) {
        ans += "3";
        len--;
    }
    ans += "7";
    cout << ans << endl;
}

int main() {
    int n; cin >> n;
    while (n--) {
        solve();
    }
}
