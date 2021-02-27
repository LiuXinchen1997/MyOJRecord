/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;

        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] != '*') { // 第j个字符
                    if (i == 0) { continue; }
                    if (matches(s[i-1], p[j-1])) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                } else {
                    dp[i][j] = dp[i][j-2];
                    if (i == 0) { continue; }
                    if (matches(s[i-1], p[j-2])) {
                        dp[i][j] = (dp[i-1][j] || dp[i][j-2]);
                    }
                }
            }
        }

        return dp[m][n];
    }

    bool matches(char s, char p) {
        if ('.' == p) { return true; }
        return s == p;
    }
};
// @lc code=end
