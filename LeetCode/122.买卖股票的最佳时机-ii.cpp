/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        int res = 0;
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            res = max(res, dp[i][0]);
        }

        return res;
    }
};
// @lc code=end

