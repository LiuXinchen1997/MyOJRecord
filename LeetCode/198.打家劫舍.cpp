/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int max_of_2(int a, int b) {
        return (a > b) ? a : b;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 0) { return 0; }
        if (nums.size() == 1) { return nums[0]; }
        
        int n = nums.size();
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        dp[1] = max_of_2(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max_of_2(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[n-1];
    }
};
// @lc code=end
