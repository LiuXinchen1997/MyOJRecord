/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (0 == n || 1 == n) { return 0; }
        vector<vector<int>> dp(n, vector<int>(3, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        // dp[i][0] 第i天结束后，持有股票
        // dp[i][1] 第i天结束后，不持有股票，处于冷冻状态
        // dp[i][2] 第i天结束后，不持有股票，不处于冷冻状态

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }

        return max(dp[n-1][1], dp[n-1][2]);
    }
};
// @lc code=end

