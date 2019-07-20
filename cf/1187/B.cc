#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n; cin >> n;
    string s; getline(cin, s); getline(cin, s);
    vector<unordered_map<int, int>> suf(26, unordered_map<int, int>());
    vector<int> tmp(26, 0);
    for (int i=0; i < s.size(); ++i) {
        tmp[s[i]-'a']++;
        suf[s[i]-'a'][tmp[s[i]-'a']] = i;
        
    }
    int q; cin >> q;
    string query; getline(cin, query);
    while (q--) {
        getline(cin, query);
        fill(tmp.begin(), tmp.end(), 0);
        for (int i=0; i < query.size(); ++i) tmp[query[i]-'a']++;
        int ans = 0;
        //cout << "=== ";
        for (int i=0; i < 26; ++i) {
            if (tmp[i])
                ans = max(ans, suf[i][tmp[i]]);//, cout << suf[i][tmp[i]] << " ";
        }
        //cout << endl;
        cout << ans + 1 <<endl;
    }
}