/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int min_of_3(int a, int b, int c) {
        return min(a, min(b, c));
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int max_res = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            if (dp[i][0] > max_res) { max_res = dp[i][0]; }
        }
        for (int i = 1; i < n; i++) {
            dp[0][i] = matrix[0][i] - '0';
            if (dp[0][i] > max_res) { max_res = dp[0][i]; }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') { dp[i][j] = 0; }
                else {
                    dp[i][j] = min_of_3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                    if (dp[i][j] > max_res) { max_res = dp[i][j]; }
                }
            }
        }

        return max_res * max_res;
    }
};
// @lc code=end

