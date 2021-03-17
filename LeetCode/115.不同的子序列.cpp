/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        // assert m >= n
        if (m < n) { return 0; }

        vector<vector<long>> dp(m+1, vector<long>(n+1));
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int i = m-1; i >= 0; i--) {
            char s_c = s[i];
            for (int j = n-1; j >= 0; j--) {
                char t_c = t[j];
                if (s_c == t_c) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        return dp[0][0];
    }
};
// @lc code=end

