#include <iostream>

using namespace std;
int solve(int a, int b) {
    int ans = 0;
    if ((a + 1) % 3 <= 1) {
        if (b&1) {
            ans = max(ans, (a + 1)/3 * (b+1)/2);
        } else {
            ans = max(ans, (a + 1)/3 * (b-2)/2 + (a + 1)/2);
        }
    }else{
        if (b&1) {
            ans = max(ans, (a + 1)/3 * (b+1)/2 + b/3);
        } else {
            ans = max(ans, (a + 1)/3 * (b-2)/2 + (a + 1)/2 - 1 + b/3);
        }
    }
    return ans;
} 

int main() {
    int m, n; cin >> m >> n;
    int a = min(m, n), b = max(m, n), ans = 0;
    if (b < 2) cout << 0 << endl;
    
    ans = max(solve(a, b), solve(b, a));
    cout << ans << endl;
    return 0;
}