#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>


using namespace std;

int pool[2050];
int dp[2050][2050];
class Solution {
public:
    int makeArryaIncreasing(vector<int>& arr1, vector<int>&  arr2) {
        int n = arr1.size(), m = arr2.size();
        
        for (int i=0; i<m; ++i) pool[i] = arr2[i];
        sort(pool, pool+m);
        m = unique(pool, pool+m) - pool;
        memset(dp, -1,  sizeof dp);
        dp[0][m] = 0; 
        for (int i=0; i<m; ++i) dp[0][i] = 1; 
        for (int i=0; i<n-1; ++i) {
            for (int j=0; j<=m; j++) {
                if (dp[i][j] == -1) continue;
                int now_v = (j == m ? arr1[i]:pool[j]);
                if (arr1[i+1] > now_v) {
                    if (dp[i+1][m] == -1 || dp[i+1][m] > dp[i][j]) dp[i+1][m]  = dp[i][j];
                }

                int nxt_p = upper_bound(pool, pool+m, now_v) - pool;
                if (nxt_p < m) {
                    if (dp[i+1][nxt_p] == -1 || dp[i+1][nxt_p] > dp[i][j] + 1) {
                        dp[i+1][nxt_p] = dp[i][j]+1;
                    }
                }
            }
        }
        int ans = -1;
        for (int i=0; i<=m; ++i) {
            if (dp[n-1][i] == -1) continue;
            if (ans == -1 || ans > dp[n-1][i]) ans = dp[n-1][i];
        }
        return ans;
    }
}