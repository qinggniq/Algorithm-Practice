#include <iostream>
#include <vector>

using namespace std;

class UF{
private:
    vector<int> sz, f;
public:
    UF(int n): sz(n+1), f(n+1) {
        fill(sz.begin(), sz.end(), 1);
        for (int i=1; i<=n; ++i) {
            f[i] = i;
        }
    }
    int find(int x) {
        if (f[x] == x) {
            return x;
        }
        f[x] = find(f[x]);
        return f[x];
    }
    void un(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return ;
        int xsz = sz[rx], ysz = sz[ry];
        
        if (xsz > ysz) {
            f[ry] = rx;
            sz[rx] += ysz;
        }else{
            f[rx] = ry;
            sz[ry] += xsz;
        }
    }
    int size(int x) {
        return sz[find(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, t; cin>>n>>m;
    UF uf(n);
    for (int i=0; i<m; ++i) {
        cin >> t;
        if (!t) continue;
        int fi = 0;cin>>fi;
        for (int j=0; j<t-1; ++j) {
            int tmp; cin>>tmp;
            uf.un(fi, tmp);
        }
    }
    for (int i=1; i<=n; ++i) {
        cout << uf.size(i) << " ";
    }
    cout << "\n";
    return 0;
}