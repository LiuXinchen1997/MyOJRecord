/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) { return nums[0]; }
        int max_res = nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            max_res = max(max_res, dp[i]);
        }

        return max_res;
    }
};
// @lc code=end

