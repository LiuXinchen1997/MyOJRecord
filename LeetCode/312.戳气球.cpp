/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        if (nums.size() == 1) { return nums[0]; }

        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        vector<int> val(n+2, 1);
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i-1];
        }

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i+len+1;

                int left = val[i];
                int right = val[j];

                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + left * val[k] * right);
                }
            }
        }

        return dp[0][n+1];
    }
};
// @lc code=end

