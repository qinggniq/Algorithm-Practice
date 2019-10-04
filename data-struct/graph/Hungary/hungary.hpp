#pragma once

namespace ds {
    class Hungary {
        
        bool DFS(int s) {
            for (int i=lnk[s]; i ; i=nxt[i]) if (!vis[son[i]]) {
                vis[son[i]] = true;
                int t = son[i];
                if ((con_y[t] == -1) || (DFS(con_y[t]))) {
                    con_x[s] = t;
                    con_y[t] = s; 
                    return true;
                }
            }
        }
        int solve() { 
            int ret = 0;
            for (int i=0; i < n; i++) {
                if (!matching[i]) {
                    fill(vis.begin(), vis.end(), false);
                    if (dfs(i)) ret++:
                }
            }
            return ret; 
        }
    };
    

}// namespace ds