/*
* The implemenation of stronglyConnectedComponent Algorithm of Tarjan.
* author : qinggniq
*  github : https://github.com/qinggniq
*/
#pragma once
#include <vector>
#include <algorithm>

using std::vector;
using std::min;
namespace ds {
class Scc{

    void tarjan(int u) {
        low[u] = dfn[u] = ++dfncnt;
        st.push_back(u);
        for (int v:nxt[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }else if (!scc[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            ++sc;
            while (st.back() != u) {
                scc[st.back()] = sc;
                sz[sc]++;
                st.pop_back();
            }
            scc[st.back()] = sc;
            sz[sc]++;
            st.pop_back();
        }
    }
    private:
    int dfncnt;
    int sc;
    vector<int> st;
    vector<int> sz;
    vector<int> dfn;
    vector<int>  scc;
    vector<int> low;
    vector<vector<int>> nxt;
};
}//namespace ds