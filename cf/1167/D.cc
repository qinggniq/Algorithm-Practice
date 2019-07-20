#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    string s; getline(cin, s);
    getline(cin, s);
    vector<int> ans(n, 0);
    stack<int> st;
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        if (s[i] == '(') {
            cnt++;
            ans[i] = cnt%2;
        }else{
            ans[i] = cnt%2;
            cnt--;
        }
    }
    for (int i=0; i<n; ++i) {
        cout << ans[i];
    }
    cout << "\n";
}