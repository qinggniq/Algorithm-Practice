#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;  cin >> n; 
    string res; cin >> res;
    for (int i=1; i < n; i++) {
        string s2; cin >> s2;
        string text = s2;
        text += "#";
        for (int j=max(0, (int)res.size() - (int)s2.size()); j < res.size(); j++) text += res[j];
        vector<int> pi(text.size()); 
        pi[0] = -1; 
        for (int j=1; j < text.size(); ++j) {
            pi[j] = pi[j-1];
            while (pi[j] != -1 && text[pi[j]+1] != text[j]) pi[j] = pi[pi[j]];
            if (text[pi[j] + 1] == text[j]) pi[j]++; 
        }
        for (int j = pi.back()+1; j < s2.size(); ++j) res += s2[j];
    }
    cout << res << endl;
}

int main() {
int n; n = 1;
while (n--) {
solve();
}
}