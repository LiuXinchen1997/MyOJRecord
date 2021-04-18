/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n+1);
        
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j <= i+nums[i] && j < nums.size(); j++) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n-1];
    }
};
// @lc code=end

