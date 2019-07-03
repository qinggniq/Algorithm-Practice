#include <iostream>
#include <vector>

using namespace std;

int main() {
    string a, b; cin >> a >> b;
    vector<int> prefix(a.size()+1, 0);
    int asz = a.length(), bsz = b.length();
    int ans = 0, bone_sz = 0;
    for (int i=0; i<asz; ++i) prefix[i+1] = prefix[i] + (a[i] == '1');
    for (int i=0; i<bsz; ++i) bone_sz += (b[i] == '1');
    for (int i=0; i<=asz-bsz; ++i) {
        if ((prefix[i+bsz] - prefix[i] + bone_sz) % 2 == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}