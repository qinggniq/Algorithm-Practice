/*
*  The implemenation of flyod.
* github : https://github.com/qinggniq
* author : qinggniq
*/
#pragma once
#include <climits>
#include <algorithm>
#include "../graph_link.hpp"

using std::min;
namespace ds {
    class Flyod{
        public:
            Flyod(const vector<vector<int>>& g):V(g.size()) {
                f.assign(g.size(), vector<int>(g[0].size(), INT_MAX));
                for (int k=0; k < V; ++k) {
                    for (int i=0; i < V; ++i) {
                        for (int j=0; j < V; ++j) {
                            f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                        }
                    }
                }
            }
        private:
        int V;
        vector<vector<int>> f;
    };
}// namespace ds