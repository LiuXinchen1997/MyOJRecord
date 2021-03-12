/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() <= 1) { return false; }

        int sum = 0;
        int max_num = -1;
        for (int num : nums) {
            sum += num;
            if (num > max_num) {
                max_num = num;
            }
        }

        if (sum % 2 == 1) { return false; }
        sum = sum / 2;
        if (max_num > sum) { return false; }
        if (max_num == sum) { return true; }
        
        int n = nums.size();
        vector<int> dp(sum+1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (j - nums[i-1] >= 0) {
                    dp[j] = max(dp[j], dp[j-nums[i-1]] + nums[i-1]);
                }
            }
        }

        if (dp[sum] == sum) { return true; }
        return false;
    }
};
// @lc code=end

