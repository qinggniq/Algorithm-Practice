/*
*   The implemenation of Bellman Flord.
*   author : qinggniq
*   github : https://github.com/qinggniq
*/
#pragma once
#include <climits>
#include <algorithm>
#include "../graph_link.hpp"

using std::min;
namespace ds {
    class Bellman{
        Bellman(const vector<vector<int>> &in):g(in.size(), in) {
            for (int i=1; i<g.V(); ++i) {
                for (Edge& e : g.adj(i)) {
                    relax(i, e.v, e.w);
                }
            }
        }
        private:
        int edg_len(int u, int v) { 
            for (Edge& e:g.adj(u)) {
                if (e.v == v) return e.w;
            }
            return INT_MAX;
        }
        void relax(int u, int v, int w) { 
            dist[u] = min(dist[u], dist[v] + w);
        }
        private:
        vector<int> dist;
        DireGraphLinkList g;
    };
}// namespace ds