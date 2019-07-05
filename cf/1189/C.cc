#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n, q, l, r; cin >> n;
    vector<int> prefix(n+1);
    prefix[0] = 0;
    int tmp;
    for (int i=1; i<=n; ++i) {
        cin >> tmp;
        prefix[i] = prefix[i-1] + tmp;
    }
    cin >> q;
    for (int i=0; i<q; ++i) {
        cin >> l >> r;
        cout << (prefix[r] - prefix[l-1])/10 << endl;
    }
    return 0;
}