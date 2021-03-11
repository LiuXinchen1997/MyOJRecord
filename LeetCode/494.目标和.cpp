/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(2002, 0));
        
        dp[0][nums[0] + 1000] += 1;
        dp[0][-nums[0] + 1000] += 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = -1000; j <= 1000; j++) {
                if (dp[i-1][j+1000] > 0) {
                    dp[i][j+nums[i]+1000] += dp[i-1][j+1000];
                    dp[i][j-nums[i]+1000] += dp[i-1][j+1000];
                }
            }
        }

        return S > 1000 ? 0 : dp[nums.size()-1][S+1000];
    }
};
// @lc code=end

