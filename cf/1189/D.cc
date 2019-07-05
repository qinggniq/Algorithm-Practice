#include <iostream>
#include <vector>

using namespace std;
struct Node{
    int key;
    vector<int> next;
}G[100050];
int main() {
    int n; cin >> n;
    int u, v;
    for (int i=0; i<n-1; ++i) {
        cin >> u >> v;
        G[u].next.push_back(v);
        G[v].next.push_back(u);
    }
    bool flag = false;
    for (int i=1; i<=n; ++i) {
        if (G[i].next.size() == 2) {flag = true; break;}
    }
    if (!flag) cout << "YES";
    else cout << "NO"; 
    return 0;
}