/*
 * The implemenation of Minimize Cycle in  Undirected Graph.
 *  author : qinggniq
 *  github : https://github.com/qinggniq
*/
#pragma once
#include <algorithm>


namespace ds {
    const int  maxn = 1e5;
    const int inf = 1e9;
    int val[maxn + 1][maxn + 1];  // 原图的邻接矩阵
    
    inline int floyd(const int &n) {
        static int dis[maxn + 1][maxn + 1];  // 最短路矩阵
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) dis[i][j] = val[i][j];  // 初始化最短路矩阵
        
        int ans = inf;
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i < k; ++i) for (int j = 1; j < i; ++j)
                ans = std::min(ans, dis[i][j] + val[i][k] + val[k][j]);  // 更新答案
            for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);  // 正常的 floyd 更新最短路矩阵
        }
        return ans;
    }
}