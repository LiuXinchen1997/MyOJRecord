/*
 * @lc app=leetcode.cn id=1411 lang=cpp
 *
 * [1411] 给 N x 3 网格图涂色的方案数
 */

// @lc code=start
class Solution {
public:
    static const int MOD = 1000000007;

    int numOfWays(int n) {
        vector<int> types;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (i != j && j != k) {
                        types.push_back(i*9 + j*3 + k);
                    }
                }
            }
        }

        int num_types = types.size();
        if (1 == n) { return num_types; }
        vector<vector<int>> dis(num_types, vector<int>(num_types, 0));
        for (int i = 0; i < num_types; i++) {
            int type1 = types[i];
            int x1 = type1 / 9; type1 %= 9;
            int x2 = type1 / 3; type1 %= 3;
            int x3 = type1;
            for (int j = i+1; j < num_types; j++) {
                int type2 = types[j];
                int y1 = type2 / 9; type2 %= 9;
                int y2 = type2 / 3; type2 %= 3;
                int y3 = type2;

                if (x1 != y1 && x2 != y2 && x3 != y3) {
                    dis[i][j] = 1;
                    dis[j][i] = 1;
                }
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(num_types, 1));
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < num_types; j++) {
                dp[i][j] = 0;
                for (int k = 0; k < num_types; k++) {
                    if (dis[j][k]) {
                        dp[i][j] += dp[i-1][k]; dp[i][j] %= MOD;
                    }
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < num_types; i++) {
            ret += dp[n][i];
            ret %= MOD;
        }

        return ret;
    }
};
// @lc code=end

