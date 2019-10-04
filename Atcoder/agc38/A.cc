#include <bits/stdc++.h>

using namespace std;

void solve() {
    int H, W, A, B; cin >> H >> W >> A >> B;
    for (int j=0; j < H; j++) {for (int i=0; i < W; i++){
            if ((i < A && j < B) || (i >= A && j >= B)) {
                cout << "1";
            }else{
                cout << "0";
            }
        }
        cout << endl;
    }
}

int main() {
    int n; n = 1 ;
    while (n--) {
        solve();
    }
}