/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) { return 0; }

        vector<int> dp(amount+1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i-coin] != -1) {
                    if (dp[i] == -1) {
                        dp[i] = dp[i-coin] + 1;
                    } else {
                        dp[i] = min(dp[i], dp[i-coin]+1);
                    }
                }
            }
        }

        return dp[amount];
    }
};
// @lc code=end

