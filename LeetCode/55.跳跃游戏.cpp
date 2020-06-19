/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (0 == nums.size() || 1 == nums.size()) { return true; }
        if (nums[0] == 0) { return false; }

        int max_ = nums[0];
        int i = 1;
        for (; i < nums.size();) {
            if (i > max_) { return false; }
            if (i + nums[i] > max_) { 
                max_ = i + nums[i];
                if (max_ >= nums.size() - 1) { return true; } 
            }
            i++;
        }

        return true;
    }
};
// @lc code=end

