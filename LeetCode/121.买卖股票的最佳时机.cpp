/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        int res = 0;
        if (0 == n || 1 == n) { return res; }

        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1] - prices[i-1] + prices[i], 0);
            if (dp[i] > res) {
                res = dp[i];
            }
        }

        return res;
    }
};
// @lc code=end

