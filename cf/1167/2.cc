#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int action[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int ra[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
int idx[10] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8};
void dfs(vector<vector<vector<int>>>& memo, const string& s, char l, char r, int step, int now, int ans) {
    if (idx[l-'0'] >= idx[r-'0']) return;
    if (step >= ans) return;
    if (memo[l-'0'][r-'0'][now] != -1) return ;
    if (memo[l-'0'][r-'0'][now] == -1) {
        memo[l-'0'][r-'0'][now] = step;
    }else{
        memo[l-'0'][r-'0'][now] = min(memo[l-'0'][r-'0'][now], step);
    }
    if (now == s.length()) {
        ans = min(ans, step);
        if (memo[l-'0'][r-'0'][now] == -1) {
            memo[l-'0'][r-'0'][now] = step;
        }else{
            memo[l-'0'][r-'0'][now] = min(memo[l-'0'][r-'0'][now], step);
        }
        return;
    }
    cout << "in" << " " << l << " " << r << " " << step << " " <<  now << endl;
    if (r == s[now] || l == s[now]) {
        int nl, nr;
        if (l == s[now]) {
            
        }
        for (int i=0; i<4; ++i) {
            char nl = l + ra[i][0], nr = r + ra[i][1];
            if (idx[l-'0'] == 0 && ra[i][0] == -1) continue;
            if (idx[r-'0'] == 9 && ra[i][1] == 1) continue;
            if (l == '0' && ra[i][0] == -1) nl = '9';
            if (l == '9' && ra[i][0] == 1) nl = '0';
            if (r == '9' && ra[i][1] == 1) nr = '0';
            if (r == '0' && ra[i][1] == -1) nr = '9';
            if (r == s[now)
            dfs(memo, s, nl, nr, step+1, now, ans); 
        }
        
        dfs(memo, s, l, r, step+1, now+1, ans);
        
    }else{
        for (int i=0; i<4; ++i) {
            char nl = l + action[i][0], nr = r + action[i][1];
            if (idx[l-'0'] == 0 && action[i][0] == -1) continue;
            if (idx[r-'0'] == 9 && action[i][1] == 1) continue;
            if (l == '0' && action[i][0] == -1) nl = '9';
            if (l == '9' && action[i][0] == 1) nl = '0';
            if (r == '9' && action[i][1] == 1) nr = '0';
            if (r == '0' && action[i][1] == -1) nr = '9';
            dfs(memo, s, nl, nr, step+1, now, ans); 
        }
    }
   
}

int main() {
    string s; getline(cin, s);
    int n = s.length(), ans=INT_MAX;
    vector<vector<vector<int>>> memo(10, vector<vector<int>>(10, vector<int>(n+1, -1)));
    dfs(memo, s, '5', '6', 0, 0, ans);
    cout << ans << endl;
    return 0;
}