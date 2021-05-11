/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int m = static_cast<int>(sqrt(n)) + 1;
        vector<int> square_nums(m+1, 0);
        
        for (int s = 1; s <= m; s++) { square_nums[s] = s * s; }

        for (int i = 1; i <= n; i++) {
            for (int s = 1; s < m; s++) {
                if (i < square_nums[s]) break;
                dp[i] = min(dp[i], dp[i-square_nums[s]] + 1);
            }
        }

        return dp[n];
    }
};
// @lc code=end

